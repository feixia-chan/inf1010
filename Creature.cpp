#include "Creature.h"


//https://github.com/feixia-chan/inf1010.git    maude.carrier@polymtl.ca

//constructeurs
Creature::Creature(){
    nom_="";
    attaque_=0;
    defense_=0;
    pointDeVie_=0;
    pointDeVieTotal_=0;
    energie_=0;
    energieTotale_=0;
    experience_=0;
    experienceNecessaire_=0;
    niveau_=0;
    Pouvoir pouvoir;
    pouvoir_=pouvoir;
}

Creature::Creature(string nom, int attaque, int defense, int pointDeVie, int energie, Pouvoir pouvoir){
    nom_=nom;
    attaque_=attaque;
    defense_=defense;
    pointDeVie_=pointDeVie;
    pointDeVieTotal_=pointDeVie;
    energie_=energie;
    energieTotale_=energie;
    experience_=0;
    experienceNecessaire_=100;
    niveau_=1;
    pouvoir_=pouvoir;
    }

    //destructeur

Creature::~Creature(){
};

    //accesseurs
string Creature::getNom() const{
    return nom_;
}

int Creature::getAttaque() const{
    return attaque_;
}

int Creature::getDefense() const{
    return defense_;
}

int Creature::getPointDeVie() const{
    return pointDeVie_;
}

int Creature::getPointDeVieTotal() const{
    return pointDeVieTotal_;
}

int Creature::getEnergie() const{
    return energie_;
}

int Creature::getEnergieTotale() const{
    return energieTotale_;
}

int Creature::getExperience()const{
    return experience_;
}

int Creature::getExperienceNecessaire() const{
    return experienceNecessaire_;
}

int Creature::getNiveau() const{
    return niveau_;
}

Pouvoir Creature::getPouvoir() const{
    return pouvoir_;
}

    //modificateurs
void Creature::setNom(string nom){
    nom_=nom;
}

void Creature::setAttaque(int attaque){
    attaque_=attaque;
}

void Creature::setDefense(int def){
    defense_=def;
}

void Creature::setPointDeVie(int pv){
    pointDeVie_=pv;
}

void Creature::setPointDeVieTotal(int pvt){
    pointDeVieTotal_=pvt;
}

void Creature::setEnergie(int energie){
    energie_=energie;
}

void Creature::setEnergieTotale(int energieTotale){
    energieTotale_=energieTotale;
}

void Creature::setExperience(int xp){
    experience_=xp;
}

void Creature::setExperienceNecessaire(int xpNecessaire){
    experienceNecessaire_=xpNecessaire;
}

void Creature::setNiveau(int lvl){
    niveau_=lvl;
}

void Creature::setPouvoir(Pouvoir pouvoir){
    pouvoir_=pouvoir;
}
    //methodes
void Creature::attaquer(Creature & creature)   //modifié
{
		//L'attaque est possible si votre créature a assez d'energie
		//Et que la creature adverse a encore des points de vie
		if(this->getEnergie() > this->getPouvoir().getEnergieNecessaire() && creature.pointDeVie_>=0){

			//Calcul du nombre de degat selon une formule
			unsigned int degat = this->getPouvoir().getNombreDeDegat()* (attaque_ / 2 - creature.defense_);
			//On choisit un nombre aléatoire entre 0 et 5
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				//Afficher le nom de la créature qui lance l'attaque, le nom de l'attaque,
				//le nombre de dégat infligé, et la créature qui est attaquée
				cout << this->getNom() << " lance une attaque " << pouvoir_.getNom() << " !" << endl;
				cout << degat << " points de dégâts sont infligés à " << creature.getNom() << endl;

                //encaissement des dégâts par la créature et diminution de l'énergie
                creature.setPointDeVie(creature.getPointDeVie()-degat);
                this->setEnergie(this->getEnergie()-this->getPouvoir().getEnergieNecessaire());
                cout << this->getNom() << "a encore " << energie_ << " PE" <<endl;

                //Afficher le nombre d'XP gagné ou non
                int xp = experienceGagner(creature);
				if(xp!=0){ //la créature adverse est morte
                    cout << this->getNom() << " a gagné "<< xp << " point d'expérience !" << endl;
				}
                else {
                    //Afficher le nombre de point de vie restant de la créature attaquée
                    cout << creature.getNom() << " a encore " << creature.getPointDeVie()<<" PV"<<endl;

				//Faites attention aux requis d'une attaque

                }
			}
		}
        else {
            //La créature adverse est déjà vaincue
            cout << "Attaque " << this->getPouvoir().getNom() << " a échouée" << endl;
        }
    }


int Creature::experienceGagner(const Creature& creature)
{
	if (creature.getPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.getNiveau() + 1 - niveau_) * ((creature.getAttaque() + 5 - attaque_) *
		 (creature.getDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) { //on peut lvl up
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotale_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else {
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::information(){
    cout << "Nom : "<< this->getNom() <<endl;
    cout << "Niveau : "<< this->getNiveau() <<endl;
    cout << "Experience totale : "<< this->getExperience() <<" XP"<<endl;
    cout << "Expérience nécessaire pour le prochain niveau: "<< this->getExperienceNecessaire() <<" XP"<<endl;
    cout << "Pouvoir : "<< pouvoir_.getNom() <<endl;
    cout << pouvoir_.getNom()<<" inflige "<<pouvoir_.getNombreDeDegat()<<" points de dégats et coute "<<pouvoir_.getEnergieNecessaire()<<" PE"<<endl;
    cout << "Points de vie restants : "<< this->getPointDeVie() << "/" << this->getPointDeVieTotal() <<" PV"<< endl;
    cout << "Attaque : "<< this->getAttaque() <<endl;
    cout << "Defense : "<< this->getDefense() <<endl;
    cout << "Energie restante : " << this->getEnergie() << "/"<< this->getEnergieTotale() <<" PE"<< endl;
}
