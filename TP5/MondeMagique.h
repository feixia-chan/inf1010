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

    template< typename T>
    bool supprimer (T* maitre); //supprime le maitre de la liste si égal (return false si non trouvé)
    template< typename S>
    bool supprimer (S* compagnon);  //supprime le compagnon de la liste si égal (return false si non trouvé)

    template< typename PredicatUn >
    void supprimerMaitre(PredicatUn predicat);
    template< typename PredicatUn >
    void supprimerCompagnon(PredicatUn predicat);

    void vider(); //vide les deux listes



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
MondeMagique<T,S>::void ajouter (T* maitre)
{
    listMaitre_.push_back(maitre);

}

template< typename S >
MondeMagique<T,S>::void ajouter (S* compagnon)
{
    listCompagnon_.push_back(compagnon);
}


template< typename T>
MondeMagique<T,S>::bool supprimer (T* maitre)
{
    auto it = find(listMaitre_.begin(),listeMaitre_.end(),maitre))
    if (it!=listeMaitre_.end())
    {
        listMaitre_.erase(it);
        return true;
    }
    else
    {
        return false;
    }
}


template< typename S>
MondeMagique<T,S>::bool supprimer (S* Compagnon)
{
    auto it = find(listCOmpagnon_.begin(),listecompagnon_.end(),compagnon))
    if (it!=listecompagnon_.end())
    {
        listCompagnon_.erase(it);
        return true;
    }
    else
    {
        return false;
    }
}

    template< typename PredicatUn >
    MondeMagique<T,S>::void supprimerMaitre(PredicatUn predicat){
       auto it= remove_if(listMaitre_.begin(),listMaitre_.end(),!predicat);
       listMaitre_.erase(it, listMaitre_.end());
    }

template< typename PredicatUn >
    MondeMagique<T,S>::void supprimerCompagnon(PredicatUn predicat){
        auto it = remove_if(listCompagnon_.begin(),listCompagnon_.end(),!predicat);
        listCompagnon_.erase(it, listCompagnon_.end())
    }

MondeMagique<T,S>::void vider()
{
    listMaitre_.erase(listMaitre.begin(),listMaitre.end());
    listCompagnon_.erase(listCompagnon_.begin(),listCompagnon_.end());
}
#endif // MONDEMAGIQUE_H
