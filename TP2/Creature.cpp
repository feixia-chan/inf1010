#include "Creature.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
 ;

Creature::Creature():nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
	energie_(0), experience_(0), niveau_(1) // A MODIFIER... (si necessaire)
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

Creature::Creature(const string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie):
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1) // A MODIFIER... (si necessaire)
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}

//constructeur par copie
Creature::Creature(const Creature& creature)
{
    nom_=creature.nom_;
    attaque_=creature.attaque_;
    defense_=creature.defense_;
    pointDeVie_=creature.pointDeVie_;
    pointDeVieTotal_=creature.pointDeVieTotal_;
    energie_=creature.energie_;
    energieTotal_=creature.energieTotal_;
    niveau_=creature.niveau_;
    experience_=creature.experience_;
    experienceNecessaire_=creature.experienceNecessaire_;
    for(int i=0;i<creature.getPouvoirs().size();i++){
        pouvoirs_.push_back(new Pouvoir(*creature.getPouvoirs()[i]));
    }
}

Creature::~Creature() // A MODIFIER... (si necessaire)
{
    //destruction des pointeurs qui sont dans le vecteur pouvoir
    for(int i=pouvoirs_.size()-1;i>=0;i--){
        delete pouvoirs_[i];
        pouvoirs_.pop_back();
    }
}

string Creature::getNom() const
{
	return nom_;
}

unsigned int Creature::getAttaque() const
{
	return attaque_;
}

unsigned int Creature::getDefense() const
{
	return defense_;
}

unsigned int Creature::getPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::getPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::getEnergie() const
{
	return energie_;
}

unsigned int Creature::getEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::getExperience() const
{
	return experience_;
}

unsigned int Creature::getExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::getNiveau() const
{
	return niveau_;
}

vector<Pouvoir*> Creature::getPouvoirs() const
{
	return pouvoirs_;
}


void Creature::attaquer(Pouvoir pouvoir, Creature & creature)// A MODIFIER... (si necessaire)
{
	//on vérifie que la créature possède le pouvoir qu'on lui demande de lancer
	bool attaque=false;
	for(int i=0;i<pouvoirs_.size();i++){
        if(pouvoirs_[i] == &pouvoir)
        attaque=true;
	}
	if (attaque && energie_ >= pouvoir.getEnergieNecessaire())
    {
		if (creature.getPointDeVie() >= 0)
        {
			//Calcul du nombre de degat selon une formule
			unsigned int degat = (pouvoir.getNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				cout << nom_ << " lance " << pouvoir.getNom() << " qui inflige " << degat << " degat a " << creature.getNom() << endl;
				if (degat > creature.getPointDeVie()) {
					creature.setPointDeVie(0);
					int xp = experienceGagnee(creature);
					cout << nom_ << " a gagné " << xp << " XP" << endl;
				}
				else
					creature.setPointDeVie(creature.getPointDeVie() - degat);
				cout << creature.getNom() << " a encore " << creature.getPointDeVie() << " PV" << endl;
				energie_ -= pouvoir.getEnergieNecessaire();    //je pense que ce serait plus logique de mettre cette ligne de code avant de savoir si la créature est vaincue car l'attaquant est censé utiliser de l'énergie dans tous les cas
			}
			else {
				cout << "Attaque " << pouvoir.getNom() << " a échouée" << endl;
			}
		}
		else
			cout << "Vous deja avez vaincu " << creature.getNom() << endl;
	}

}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.getPointDeVie() <= 0)
    {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.getNiveau() + 1 - niveau_) * ((creature.getAttaque() + 5 - attaque_) * (creature.getDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_))
        {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else
        {
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::setAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::setDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::setPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::setEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::setExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::setNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::setPouvoirs(vector<Pouvoir*> pouvoirs) // A MODIFIER... (si necessaire)
{
	if(pouvoirs_.size()==pouvoirs.size()){
        for(int i=0;i<pouvoirs.size();i++){
            *pouvoirs_[i]=*pouvoirs[i];
        }
	}
	else if(pouvoirs_.size()<pouvoirs.size()){
        for(int i=0;i<pouvoirs_.size();i++){
            *pouvoirs_[i]=*pouvoirs[i];
        }
        for(int i=pouvoirs_.size();i<pouvoirs.size();i++){
            pouvoirs_.push_back(new Pouvoir(*pouvoirs[i]));
        }
	}
	else{
        for(int i=0;i<pouvoirs.size();i++){
            *pouvoirs_[i]=*pouvoirs[i];
        }
        for(int i=pouvoirs.size();i<pouvoirs_.size();i++){
            delete pouvoirs_[i];
            pouvoirs_.pop_back();
        }
	}
}

void Creature::setNom(const string& nom)
{
    nom_=nom;
}

void Creature::information() const // A MODIFIER... (si necessaire)
{
	cout << nom_ << " a " << attaque_ << " en attaque et " << defense_ << " en defense, " << endl
		<< "Il a " << pointDeVie_ << "/" << pointDeVieTotal_ << " PV et " << energie_ << "/" << energieTotal_ << " Energie" << endl
		<< "Il est au niveau " << niveau_ << " avec " << experience_ << "d'XP" << endl
		<< "Il lui manque " << experienceNecessaire_ - experience_ << " jusqu'au prochain niveau " << endl;
	cout << "Son pouvoir  est : ";
	for(unsigned int i=0;i<pouvoirs_.size();i++){
        pouvoirs_[i]->description();
    }
	cout << endl;
}

// _______TP2________

//operators
Creature& Creature::operator=(const Creature& creature)
{
    if(this != &creature){
        for(int i=pouvoirs_.size()-1;i>=0;i--){
            delete pouvoirs_[i];
            pouvoirs_[i]=nullptr;
            pouvoirs_.pop_back();
        }
        nom_=creature.nom_;
        attaque_=creature.attaque_;
        defense_=creature.defense_;
        pointDeVie_=creature.pointDeVie_;
        pointDeVieTotal_=creature.pointDeVieTotal_;
        energie_=creature.energie_;
        energieTotal_=creature.energieTotal_;
        niveau_=creature.niveau_;
        experience_=creature.experience_;
        experienceNecessaire_=creature.experienceNecessaire_;
        for(int i=0;i<creature.getPouvoirs().size();i++){
            pouvoirs_.push_back(new Pouvoir(*creature.getPouvoirs()[i]));
        }
    }
    return *this;
}

bool Creature::operator==(const Creature& creature) //pour comparer 2 créature sans les pouvoirs
{
    return(nom_==creature.nom_
            && attaque_==creature.attaque_
            && defense_==creature.defense_
            && pointDeVie_==creature.pointDeVie_
            && pointDeVieTotal_==creature.pointDeVieTotal_
            && energie_==creature.energie_
            && energieTotal_==creature.energieTotal_
            && niveau_==creature.niveau_
            && experience_==creature.experience_
            && experienceNecessaire_==creature.experienceNecessaire_);
}

bool Creature::operator==(const string& nom)    //pour comparer une créature avec un nom donné
{
    return(nom_==nom);
}

bool operator==(const string& nom, const Creature& creature)    //pour comparer un nom avec une créature
{
    return nom==creature.nom_;
}

ostream& operator<<(ostream& o, const Creature& creature) //pour l'affichage de créature avec ou sans pouvoir
{
    if(creature.pouvoirs_.size()==0){    //affichage sans pouvoir
        o<<creature.nom_<<" a "<<creature.attaque_<<" en attaque et "<<creature.defense_<<" en defense,\nil a "
        <<creature.pointDeVie_<<"/"<<creature.pointDeVieTotal_<<" PV et "<<creature.energie_<<"/"<<creature.energieTotal_<<" PE,\nil est au niveau "
        <<creature.niveau_<<" avec "<<creature.experience_<<" XP,\n il lui manque "
        <<creature.experienceNecessaire_-creature.experience_<<" XP pour monter d'un niveau.\nPouvoirs :\n"
        <<creature.nom_<<" ne possede aucun pouvoir";
    }
    else{   //affichage avec pouvoirs
        o<<creature.nom_<<" a "<<creature.attaque_<<" en attaque et "<<creature.defense_<<" en defense,\nil a "
        <<creature.pointDeVie_<<"/"<<creature.pointDeVieTotal_<<" PV et "<<creature.energie_<<"/"<<creature.energieTotal_<<" PE,\nil est au niveau "
        <<creature.niveau_<<" avec "<<creature.experience_<<" XP,\n il lui manque "
        <<creature.experienceNecessaire_-creature.experience_<<" XP pour monter d'un niveau.\nPouvoirs :\n";
        for(int i=0; i<creature.pouvoirs_.size();i++){
            o<<*creature.pouvoirs_[i]<<"\n";
        }
    }
    return o;
}

bool Creature::ajouterPouvoir(const Pouvoir& pouvoir)
{
    for(int i=0;i<pouvoirs_.size();i++){    //on vérifie si la créature possède déjà le pouvoir
        if(pouvoirs_[i] == &pouvoir){
            return false;
        }
        //si elle ne le possède pas on l'ajoute
            pouvoirs_.push_back(new Pouvoir(pouvoir));
            return true;
    }
}

bool Creature::oublierPouvoir(const string& nom)
{
    //on cherche si la creature possède le pouvoir demandé
    for(int i=0;i<pouvoirs_.size();i++){
        if(pouvoirs_[i]->getNom()==nom){ //si elle le possède
            pouvoirs_[i]=pouvoirs_[pouvoirs_.size()-1]; //on met le dernier pouvoir du vecteur à sa place
            delete pouvoirs_[pouvoirs_.size()-1];   //on supprime le dernier pointeur
            pouvoirs_.pop_back();   //on le pop pour réduire le vecteur
            return true;
        }
    }
    //si elle ne le possède pas
    return false;
}
