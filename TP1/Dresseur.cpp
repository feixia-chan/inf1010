#include "Dresseur.h"


//Constructeurs

Dresseur::Dresseur(){   //Constructeur par défaut

    nom_="";
    nombreCreatures_=0;
    nombreCreaturesMax_=2;
    creatures_=new Creature*[MAX_NOMBRE_CREATURES];
    for(unsigned int i=0;i<nombreCreaturesMax_;i++){
        creatures_[i]=nullptr;
    }
}

Dresseur::Dresseur(const string& nom){ //Constructeur avec nom
    nom_=nom;
    nombreCreatures_=0;
    nombreCreaturesMax_=2;
    creatures_=new Creature*[MAX_NOMBRE_CREATURES];
    for(unsigned int i=0;i<nombreCreaturesMax_;i++){
        creatures_[i]=nullptr;
    }
}

//Destructeur

Dresseur::~Dresseur(){
    for(unsigned int i=0;i<nombreCreaturesMax_;i++){
        delete creatures_[i];
    }
    delete [] creatures_;
    creatures_=nullptr;
}

//Accesseurs

string Dresseur::getNom() const{
    return nom_;
}

ObjetMagique Dresseur::getObjetMagique() const{
    return objetMagique_;
}

Creature** Dresseur::getCreatures() const{
    return creatures_;
}

unsigned int Dresseur::getNombreCreatures() const{
    return nombreCreatures_;
}

//Modificateurs

void Dresseur::setNom(const string& nom){
    nom_=nom;
}

void Dresseur::setObjetMagique(const ObjetMagique& objetMagique){
    objetMagique_=objetMagique;
}

void Dresseur::setCreature(Creature** creatures){
    creatures_=creatures;
}

//Ajouter ou retirer des créatures

bool Dresseur::ajouterCreature(const Creature& creature){
    //On regarde si le tableau est plein
    if (nombreCreatures_==nombreCreaturesMax_){
        //si oui on double la taille du tableau creatures_ en utilisant un tableau de copie
        Creature** copie = new Creature*[nombreCreaturesMax_];
        for(unsigned int i=0;i<nombreCreaturesMax_;i++){
            copie[i]=creatures_[i];
        }
        //on supprime creatures_ pour le recréer plus grand
        delete [] creatures_;
        creatures_=nullptr;
        nombreCreaturesMax_*=2;
        creatures_= new Creature*[nombreCreaturesMax_];
        for(unsigned int i=0;i<nombreCreaturesMax_/2;i++){
            creatures_[i]=copie[i];
        }
        //on supprime la copie
        delete [] copie;
        copie = nullptr;

        return false;
    }
    //Si le tableau n'est pas plein
    else{
        //on teste si on possède déjà la créature
        for (unsigned int i=0; i<nombreCreaturesMax_;i++){
            if (creatures_[i]== &creature){
                return false;
            }
        }
        //sinon on regarde où est la première place disponible dans le tableau
        int c=0;
        while(creatures_[c]!=nullptr){
            c++;
        }
        //on l'ajoute à cette place
        creatures_[c]= new Creature(creature);
        //on incrémente le nombre de créatures que possède le dresseur
        nombreCreatures_++;

        return true;
    }
}

bool Dresseur::retirerCreature(const string& nom){
    //on cherche si on possède une créature avec ce nom
    for (unsigned int i=0;i<nombreCreaturesMax_;i++){
        //si oui...
        if(creatures_[i]->getNom()==nom){
            //on la retire...
            creatures_[i]=nullptr;
            //et on décrémente le nombre de créatures possédés
            nombreCreatures_--;
            return true;
        }
    }
    return false;
}

//Objet magique pour soigner

void Dresseur::utiliserObjetMagique(Creature* creature){
    //On regarde si l'apport du bonus ne dépasse pas les caractéristiques max de la créature
    if(creature->getPointDeVie()+objetMagique_.getBonus()>=creature->getPointDeVieTotal()){
        //si c'est le cas on met la vie au max
        creature->setPointDeVie(creature->getPointDeVieTotal());
    }
    else{
        //sinon on rajoute simplement me bonus à l'état actuelle
        creature->setPointDeVie(creature->getPointDeVie()+objetMagique_.getBonus());
    }
    //même fonctionnement que pour la vie mais avec l'énergie
    if(creature->getEnergie()+objetMagique_.getBonus()>=creature->getEnergieTotale()){
        creature->setEnergie(creature->getEnergieTotale());
    }
    else{
        creature->setEnergie(creature->getEnergie()+objetMagique_.getBonus());
    }
}

//Affichage

void Dresseur::affichage() const
{
    //Nom du dresseur plus son nombre de créatures
    cout<<"Le dresseur "<<this->getNom()<<" possède "<<this->getNombreCreatures()<<" créature(s)"<<endl;
    //chaque créature qu'il possède
    for(unsigned int i=0;i<nombreCreatures_;i++){
        //on n'affiche pas les cases vides
        if(creatures_[i]!=nullptr){
            creatures_[i]->information();
            cout<<endl;
        }
    }
}
