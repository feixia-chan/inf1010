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
        //accesseurs
        list <T*> getListMaitre() const;
        list <S*> getListCompagnon()const;

        void setListMaitre(list <T*> listeM);
        void setListCompagnon(<list <S*> listeC);


    protected:
    list <T*> listMaitre_;  //liste de maîtres
    list <S*> listCompagnon_;  //liste de compagnons
    private:
};

template< typename T, typename S >
MondeMagique<T,S>::MondeMagique(){}
template< typename T, typename S >
MondeMagique<T,S>::~MondeMagique(){

}

//accesseurs
 template< typename T, typename S >
MondeMagique<T,S>::list <T*> getListMaitre() const{
    return listMaitre_;
 }

template< typename T, typename S >
MondeMagique<T,S>::list <S*> getListCompagnon()const

template< typename T, typename S >
MondeMagique<T,S>::void setListMaitre(list <T*> listeM){
    listMaitre_ = listeM;
}
template< typename T, typename S >
MondeMagique<T,S>::void setListCompagnon(<list <S*> listeC){
    listCompagon_=listeC;
}


#endif // MONDEMAGIQUE_H
