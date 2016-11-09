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
    sort(listMaitre_.begin();listMaitre_.end();FoncteurComparerDresseurs());    //on trie les dresseurs
    sort(listCompagnon_.begin();listCompagnon_.end();FoncteurComparerCreatures()); //on trie les créatures

    os<<"Liste des dresseurs de Polyland : "<<endl;
    for(auto it=listMaitre_.begin();it!=listMaitre_.end();it++){
        os<<it<<endl;
    }
    os<<"Liste des créatures de Polyland : "<<endl;
    for(auto it=listCompagnon_.begin();it!=listCompagnon.end();it++){
        os<<it<<endl;
    }
    return os;
}
