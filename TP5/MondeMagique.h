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
    template<typename T>
    list <T*> getListMaitre() const;
    template<typename S>
    list <S*> getListCompagnon()const;

    template< typename T >
    void setListMaitre(list <T*> listeM);
    template< typename S >
    void setListCompagnon(<list <S*> listeC);

    //méthodes
    template< typename T>
    void ajouter (T* maitre); //ajoute un maitre dans la liste
    template< typename S >
    void ajouter S* compagnon);// ajoute une créature dans la liste


protected:
    list <T*> listMaitre_;  //liste de maîtres
    list <S*> listCompagnon_;  //liste de compagnons
private:
};

template< typename T, typename S >
MondeMagique<T,S>::MondeMagique() {}
template< typename T, typename S >
MondeMagique<T,S>::~MondeMagique()
{

}

//accesseurs
template< typename T>
MondeMagique<T,S>::list <T*> getListMaitre() const
{
    return listMaitre_;
}

template< typename S >
MondeMagique<T,S>::list <S*> getListCompagnon()const

template< typename T >
MondeMagique<T,S>::void setListMaitre(list <T*> listeM)
{
    listMaitre_ = listeM;
}
template< typename S >
MondeMagique<T,S>::void setListCompagnon(<list <S*> listeC)
{
    listCompagon_=listeC;
}


template< typename T>
MondeMagique<T,S>::void ajouter (T* maitre){
    listMaitre_.push_back(maitre);

}
template< typename S >
MondeMagique<T,S>::void ajouter S* compagnon)
{
    listCompagnon_.push_back(compagnon);
}

#endif // MONDEMAGIQUE_H
