#include "Professeur.h"

Professeur::Professeur(const string& nom, const string& equipe) //constructeur par paramètre semblable à celui de Dresseur
{
    Dresseur(nom, equipe);
    outil_=nullptr;
}

Professeur::Professeur(const Professeur& prof)
{
    nom_=prof.nom_;
    equipe_=prof.equipe_;
    for(unsigned int i=0;i<prof.creatures_.size();i++){
        creatures_.push_back(new Creature(*prof.creatures_[i]));
    }
    outil_=new OutilScientifique(*prof.outil_);
}

Professeur::~Professeur()   //Destructeur
{
    delete outil_;
    outil_=nullptr;
}

//Accesseurs/Modificateurs
OutilScientifique* Professeur::getOutil()
{
    return outil_;
}

void Professeur::setOutil(OutilScientifique* outil)
{
    delete outil_;
    outil_=nullptr;
    outil_=outil;
}

//Soigner une créature
void Professeur::soigner(Creature& creature)
{
    creature.setPointDeVie(creature.getPointDeVieTotal());  //rend toute la vie à la créature
    creature.setEnergie(creature.getEnergieTotale());   //rend toute l'énergie à la créature
}

//utiliser l'outil
void Professeur::utiliserOutil(Creature& creature)
{
    outil_->utiliser(creature);
}

Professeur& Professeur::operator=(const Professeur& prof)
{
    if(this!= &prof){
        delete outil_;
        outil_=nullptr;
        nom_=prof.nom_;
        equipe_=prof.equipe_;
        for(unsigned int i=0;i<prof.creatures_.size();i++){
            creatures_.push_back(new Creature(*prof.creatures_[i]));
        }
        outil_=new OutilScientifique(*prof.outil_);
    }
}
