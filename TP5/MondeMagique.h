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
void setListCompagnon(list <S*> listeC);
//méthodes
template< typename T>
void ajouter (T* maitre); //ajoute un maitre dans la liste
template< typename S >
void ajouter (S* compagnon);// ajoute une créature dans la liste
template< typename T>
bool supprimer (T* maitre); //supprime le maitre de la liste si égal (return false si non trouvé)
template< typename S>
bool supprimer (S* compagnon); //supprime le compagnon de la liste si égal (return false si non trouvé)
template< typename PredicatUn >
void supprimerMaitre(PredicatUn predicat);
template< typename PredicatUn >
void supprimerCompagnon(PredicatUn predicat);
void vider(); //vide les deux listes
//surcharge d'opérateurs
template<typename T>
list <T*> operator+=(T* maitre); //ajoue un maitre via meth ajouter
template<typename S>
list <S*> operator+=(S* compagnon);
template<typename T>
list<T*> operator-=(T* maitre); //supprime un maitre via meth supprimer
template<typename S>
list<T*> operator-=(S* compagnon);
protected:
list <T*> listMaitre_; //liste de maîtres
list <S*> listCompagnon_; //liste de compagnons
private:
};
template< typename T, typename S >
MondeMagique<T,S>::MondeMagique() {}
template< typename T, typename S >
MondeMagique<T,S>::~MondeMagique()
{
}
//accesseurs
template< typename T, typename S>
list <T*> MondeMagique<T,S>::getListMaitre() const
{
return listMaitre_;
}
template< typename T, typename S >
list <S*> MondeMagique<T, S>::getListCompagnon()const
{
return listCompagnon_;
}
template< typename T typename S>
void MondeMagique<T,S>::setListMaitre(list <T*> listeM)
{
listMaitre_ = listeM;
}
template< typename T,typename S >
void MondeMagique<T,S>::setListCompagnon(<list <S*> listeC)
{
listCompagon_=listeC;
}

template< typename T, typename S>
void MondeMagique<T,S>::ajouter (T* maitre)
{
listMaitre_.push_back(maitre);
}
template< typename T, typename S >
void MondeMagique<T,S>::ajouter (S* compagnon)
{
listCompagnon_.push_back(compagnon);
}

template< typename T, typename S>
bool MondeMagique<T,S>::supprimer (T* maitre)
{
auto it = find(listMaitre_.begin(),listeMaitre_.end(),maitre)
if(it!=listeMaitre_.end()){
listMaitre_.erase(it);
return true;
}
else
{
return false;
}
}

template<typename T, typename S>
bool MondeMagique<T,S>::supprimer (S* Compagnon)
{
auto it = find(listCompagnon_.begin(),listeCompagnon_.end(),compagnon))
if (it!=listeCompagnon_.end())
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
void MondeMagique<T,S>::supprimerMaitre(PredicatUn predicat){
auto it= remove_if(listMaitre_.begin(),listMaitre_.end(),!predicat);
listMaitre_.erase(it, listMaitre_.end());
}
template< typename PredicatUn >
void MondeMagique<T,S>::supprimerCompagnon(PredicatUn predicat){
auto it = remove_if(listCompagnon_.begin(),listCompagnon_.end(),!predicat);
listCompagnon_.erase(it, listCompagnon_.end())
}
template<typename T, typename S>
void MondeMagique<T,S>::vider()
{
listMaitre_.erase(listMaitre.begin(),listMaitre.end());
listCompagnon_.erase(listCompagnon_.begin(),listCompagnon_.end());
}
//opérateurs
template<typename T, typename S>
list <T*> MondeMagique<T,S>::operator+=(T* maitre)
{
ajouter(maitre);
return listMaitre_;
}
template<typename T, typename S>
list <S*> MondeMagique<T,S>::operator+=(S* compagnon)
{
ajouter(compagnon) ;
return listCompagnon_;
}
template<typename T, typename S>
list<T*> MondeMagique<T,S>::operator-=(T* maitre)
{
supprimer(maitre);
return listMaitre_;
}
template<typename T, typename S>
list<T*> MondeMagique<T,S>::operator-=(S* compagnon)
{
supprimer(compagnon);
return listCompagnon_;
}
#endif // MONDEMAGIQUE_H
