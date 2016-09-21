#include "Polyland.h"

Polyland::Polyland()    //Constructeur
{
    listeDresseur = new Dresseur[100];
    for(int i=0;i<listeDresseur.size();i++){
        listeDresseur[i]=nullptr;
    }
    listeCreature = new Creature[1000];
    for(int i=0;i<listeCreature.size();i++){
        listeCreature[i]=nullptr;
    }
    nombreDresseur_=0;
    nombreCreature_=0;
}

Polyland::~Polyland()   //Destructeur
{
    for(int i=0<listeDresseur.size();i++){
        delete listeDresseur[i];
    }
    for(int i=0<listeCreature.size();i++){
        delete listeCreature[i];
    }
}

//Accesseurs
int Polyland::getNbDresseurs() const
{
    return nombreDresseur_;
}
int Polyland::getNbCreatures() const
{
    return nombreCreature_;
}

//Modifier le tableau de Dresseurs
void Polyland::ajouterDresseur(const Dresseur& dresseur)
{
    if(nombreDresseur_==100){   //Test pour savoir si le tableau est déjà plein
        cout<<"Polyland est déjà surpeuplée en dresseurs ! Pas de rajout possible !"<<endl;
    }
    else{
        bool existe=false;
        int trou=nombreDresseur_;
        for(int i=0;i<nombreDresseur_;i++){
            if(listeDresseur[i]->getNom() == dresseur.getNom()){ //on teste si ce dresseur existe déjà
                existe=true;
            }
            if(listeDresseur[i]==nullptr){
                trou=i;
            }
        }
        if(!existe){
            listeDresseur[trou]= dresseur;
            nombreDresseur_++;
            cout<<"Bienvenue à Polyland, "<<dresseur.getNom()<<endl;
        }
        else{
            cout<<"Ce dresseur existe déjà !"<<endl;
        }
    }
}

void Polyland::retirerDresseur(const string& nom)
{
    if(nombreDresseur_==0){
        cout<<"Le tableau est déjà vide !"<<endl;
    }
    else{
        bool supprime=false;
        for(int i=0;i<nombreDresseur_;i++){
            if(listeDresseur[i]->getNom() == nom){ //on teste si ce dresseur existe
                listeDresseur[i] = nullptr;
                nombreDresseur_--;
                supprime=true;
                cout<<nom<<" a bien été expulsé de Polyland"<<endl;
            }
        }
        if(!supprime){
            cout<<"Ce dresseur n'existe pas !"<<endl;
        }
    }
}

//Modifier le tableau de creatures
void Polyland::ajouterCreature(Creature creature)
{
    if(nombreCreature_==1000){   //Test pour savoir si le tableau est déjà plein
        cout<<"Polyland est déjà surpeuplée en créatures. Pas de rajout possible "<<endl;
    }
    else{
        bool existe=false;
        int trou=nombreCreature_;
        for(int i=0;i<nombreCreature_;i++){
            if(listeCreature[i]->getNom() == creature.getNom()){ //on teste si cette créature existe déjà
                existe=true;
            }
            if(listeCreature[i]==nullptr){
                trou=i;
            }
        }
        if(!existe){
            listeCreature[trou]= creature;
            nombreCreature_++;
            cout<<creature<<" a bien été ajouté"<<endl;
        }
        else{
            cout<<"Une créature possède déjà ce nom "<<endl;
        }
    }
}

void Polyland::retirerCreature(string nom)
{
    if(nombreCreature_==0){
        cout<<"Le tableau est déjà vide !"<<endl;
    }
    else{
        bool supprime=false;
        for(int i=0;i<nombreCreature_;i++){
            if(listeCreature[i]->getNom() == nom){ //on teste si cette créature existe
                listeCreature[i] = nullptr;
                nombreCreature_--;
                supprime=true;
                cout<<nom<<" a bien été retiré de la liste"<<endl;
            }
        }
        if(!supprime){
            cout<<"Aucune créature ne possède ce nom"<<endl;
        }
    }
}

//Méthodes aléatoires
Dresseur Polyland::choisirDresseurAleatoire()
{
    int choix=0;
    do{
    choix = rand() % nombreDresseur_;
    }
    while(listeDresseur[choix]==nullptr);
    return listeDresseur[choix];
}

Creature Polyland::choisirCreatureAleatoire()
{
    int choix=0;
    do{
    choix = rand() % nombreCreature_;
    }
    while(listeCreature[choix]==nullptr);
    return listeCreature[choix];
}

//Attraper et relacher des créatures
bool Polyland::attraperCreature(Dresseur& dresseur, Creature& creature)
{
    bool attrape=false;
    if(dresseur.ajouterCreature(creature)){
        attrape=true;
    }
    return attrape;
}

bool Polyland::relacherCreature(Dresseur& dresseur, Creature& creature)
{
    bool relache=false;
    if(dresseur.retirerCreature(creature.getNom())){
        relache=true;
    }
    return relache;
}

//Infos Dresseur
void Polyland::infosDresseur(const string& nom) const
{
    int indiceNom=0;
    for(int i=0;i<nombreDresseur_;i++){
        if(listeDresseur[i]->getNom()==nom){
            indiceNom=i;
        }
    }
    cout<<listeDresseur[indiceNom]->affichage()<<endl;
}
