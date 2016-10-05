#include "Elixir.h"

Elixir::Elixir()
{}

Elixir::Elixir(const string& nom,int bonus):ObjetMagique(nom, bonus)    //constructeur par paramètres
{}

Elixir::Elixir(const Elixir& elixir)    //constructeur par copie
{
    nom_=elixir.nom_;
    bonus_=elixir.bonus_;
}

Elixir::~Elixir()
{}

//operator
ostream& operator<<(ostream& flux, Elixir& elixir)
{
    return flux<<"L'elixir "<<elixir.nom_<<" rend "<<2*elixir.bonus_<<" points de vie et "<<elixir.bonus_<<" point d'énergie"<<end;
}

//surcharge de utiliserSur
void Elixir::utiliserSur(Creature& creature) const
{
    ObjetMagique::utiliserSur(creature);
    PotionMagique::utiliserSur(creature);
}
