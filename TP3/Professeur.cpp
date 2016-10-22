#include "Professeur.h"

Professeur::Professeur(const string& nom, const string& equipe) //constructeur par paramètre semblable à celui de Dresseur
{
    Dresseur(nom, equipe);
    outil_=nullptr;
}

Professeur::Professeur(const Professeur& prof)
{
    this->setNom(prof.getNom());
    this->setEquipe(prof.getEquipe());
    this->setCreature(prof.getCreatures());
    outil_=new OutilScientifique(*prof.outil_);
}

Professeur::~Professeur()   //Destructeur
{
    delete outil_;
    outil_=nullptr;
}

//Accesseurs/Modificateurs
OutilScientifique* Professeur::getOutil() const
{
    return outil_;
}

void Professeur::setOutil(OutilScientifique outil)
{
    delete outil_;
    outil_=nullptr;
    outil_=new OutilScientifique(outil);
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
        this->setNom(prof.getNom());
        this->setEquipe(prof.getEquipe());
        this->setCreature(prof.getCreatures());
        outil_=new OutilScientifique(*prof.outil_);
    }
}
