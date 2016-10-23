#include "Elixir.h"

Elixir::Elixir()
{}

Elixir::Elixir(const string& nom,int bonus):PotionMagique(nom, bonus)    //constructeur par paramètres
{}

Elixir::Elixir(const Elixir& elixir)    //constructeur par copie
{
    setNom(elixir.getNom());
    setBonus(elixir.getBonus());
}

Elixir::~Elixir()
{}

//operator
ostream& operator<<(ostream& flux, Elixir& elixir)
{
    return flux<<"L'elixir "<<elixir.getNom()<<" rend "<<2*elixir.getBonus()<<" points de vie et "<<elixir.getBonus()<<" point d'énergie";
}

//surcharge de utiliserSur
void Elixir::utiliserSur(Creature& creature) const
{
    ObjetMagique::utiliserSur(creature);
    PotionMagique::utiliserSur(creature);
}
