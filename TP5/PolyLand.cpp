/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description:
*/
#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

//operator <<
ostream& operator<<(ostream& os, PolyLand poly)
{
    poly.listMaitre_.sort(FoncteurComparerDresseurs());    //on trie les dresseurs
    poly.listCompagnon_.sort(FoncteurComparerCreatures()); //on trie les créatures

    os<<"Liste des dresseurs de Polyland : "<<endl;
    for(auto it=poly.listMaitre_.begin();it!=poly.listMaitre_.end();it++){
        os<<*it<<endl;
    }
    os<<"Liste des créatures de Polyland : "<<endl;
    for(auto it=poly.listCompagnon_.begin();it!=poly.listCompagnon_.end();it++){
        os<<*it<<endl;
    }
    return os;
}
