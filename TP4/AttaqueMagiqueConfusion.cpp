#include "AttaqueMagiqueConfusion.h"



AttaqueMagiqueConfusion::AttaqueMagiqueConfusion():AttaqueMagique(2)
{
    //ctor
}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(int duree):AttaqueMagique(duree)
{

}
AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
    //dtor
}


//meths
//
//string  AttaqueMagiqueConfusion::getTypeAttaque() const
//{
//    return typeid(AttaqueMagiqueConfusion).name(); //retourne une string "AttaqueMagiqueConfusion"
//}

bool AttaqueMagiqueConfusion::appliquerAttaque(Creature& creatureAdverse)
{
    if(duree_>0)
    {
        if(creatureAdverse.getPointDeVie()>=5)     //on enleve -2 a 33% de reussite
        {
            int chance = rand() % 3;
            if (chance ==0)  //une chance sur 3
            {
                creatureAdverse.setPointDeVie(creatureAdverse.getPointDeVie()-2);
                cout<<"La confusion a retiré de la vie à "<<creatureAdverse.getNom()<<endl;
                return true;
            }
        }
    }
    else
        return false;
}

bool AttaqueMagiqueConfusion::estFini()
{
    if(duree_=0)
        return true;
    else
        return false;
}
