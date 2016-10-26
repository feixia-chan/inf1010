#include "AttaqueMagiquePoison.h"

#include <stdlib>

//constructeurs & destructeurs
AttaqueMagiquePoison::AttaqueMagiquePoison():AttaqueMagique(2)
{

}
AttaqueMagiquePoison::AttaqueMagiquePoison(int duree):AttaqueMagique(duree){}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{

}


//meths

string getTypeAttaque()
{
    return typeid(AttaqueMagiquePoison).name; //retourne une string "AttaqueMagiquePoison"
}

 bool appliquerAttaque(Creature& creatureAdverse){
    if(duree_>0){
        if(creatureAdverse.getEnergie()>=5){    //on enleve -2 a 33% de reussite
            int chance = rand() % 3;
            if (chance ==0){ //une chance sur 3
                creatureAdverse.setEnergie(creatureAdverse.getEnergie()-2);
                return true;
            }
        }
    }
    else
        return false;
 }