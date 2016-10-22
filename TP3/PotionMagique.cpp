#include "PotionMagique.h"

PotionMagique::PotionMagique()  //constructeur par défaut
{}

PotionMagique::PotionMagique(const string& nom, int bonus):ObjetMagique(nom, bonus) //constructeur par paramètres
{}

PotionMagique::~PotionMagique()
{}

//operator
ostream& operator<<(ostream& flux, const PotionMagique potion)
{
    return flux<<"La potion "<<potion.getNom()<<" rend "<<potion.getBonus()<<" points de vie";
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
