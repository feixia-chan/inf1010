/*
Fichier: MondeMagique.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 2 novembre 2016
Description: Classe générique des mondes magiques

http://www.cplusplus.com/reference/algorithm/
*/

#ifndef MONDEMAGIQUE_H
#define MONDEMAGIQUE_H

#include <string>
#include <vector>
#include <typeinfo>
#include<list>
#include<algorithm>

using namespace std;

template <typename T, typename S>
class MondeMagique
{
    public:
        MondeMagique() {}
        virtual ~MondeMagique() {}


    protected:
    list <T*> listMaitre_;  //liste de maîtres
    list <S*> listeCompagnon_;  //liste de compagnons
    private:
};

template< typename T, typename S >
MondeMagique<T,S>::MondeMagique(){}
~MondeMagique<T,S>::MondeMagique(){

}


#endif // MONDEMAGIQUE_H
