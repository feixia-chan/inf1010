#include "GreenBull.h"

GreenBull::GreenBull()  //constructeur par défaut
{}

GreenBull::GreenBull(const string& nom, int bonus):ObjetMagique(nom, bonus) //constructeur par paramètres
{}

GreenBull::~GreenBull()
{}

GreenBull::GreenBull(const GreenBull& greenBull)    //constructeur par copie
{
    nom_=greenBull.nom_;
    bonus_=greenBull.bonus_;
}

//operator
ostream& operator<<(ostream& flux, const GreenBull potion)
{
    return flux<<"La boisson énergisante "<<potion.nom_<<" rend "<<potion.bonus_<<" énergies"<<endl;
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
