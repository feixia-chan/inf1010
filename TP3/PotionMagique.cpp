#include "PotionMagique.h"

PotionMagique::PotionMagique()  //constructeur par défaut
{}

PotionMagique::PotionMagique(const string& nom, int bonus):ObjetMagique(nom, bonus) //constructeur par paramètres
{}

PotionMagique::~PotionMagique()
{}

PotionMagique::PotionMagique(const PotionMagique& potion)   //constructeur par copie
{
    nom_=potion.nom_;
    bonus_=potion.bonus_;
}

//operator
ostream& operator<<(ostream& flux, const PotionMagique potion)
{
    return flux<<"La potion "<<potion.nom_<<" rend "<<potion.bonus_<<" points de vie"<<endl;
}

//surcharge de la méthode utiliserSur
void PotionMagique::utiliserSur(Creature& creature) const
{
    if ((creature.getPointDeVieTotal() - creature.getPointDeVie()) >= getBonus()) {
        creature.setPointDeVie(creature.getPointDeVie() + getBonus());
    }
    else {
        creature.setPointDeVie(creature.getPointDeVieTotal());
    }
}
