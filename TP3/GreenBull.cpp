#include "GreenBull.h"

GreenBull::GreenBull():ObjetMagique()  //constructeur par défaut
{}

GreenBull::GreenBull(const string& nom, int bonus):ObjetMagique(nom, bonus) //constructeur par paramètres
{}

GreenBull::~GreenBull()
{}

//operator
ostream& operator<<(ostream& flux, const GreenBull potion)
{
    return flux<<"La boisson énergisante "<<potion.getNom() <<" rend "<<potion.getBonus()<<" énergies";
}

//surcharge de la méthode utiliserSur
void GreenBull::utiliserSur(Creature& creature) const
{
    if ((creature.getEnergieTotale() - creature.getEnergie()) > getBonus()) {
        creature.setEnergie(creature.getEnergie() + getBonus());
    }
    else {
        creature.setEnergie(creature.getEnergieTotale());
    }
}
