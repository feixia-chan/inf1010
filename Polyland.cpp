#include "Polyland.h"

Polyland::Polyland()    //Constructeur
{
    listeDresseur = new Dresseur*[100];
    for(int i=0;i<MAX_NOMBRE_DRESSEURS;i++){
        listeDresseur[i]=nullptr;
    }
    listeCreature = new Creature*[1000];
    for(int i=0;i<MAX_NOMBRE_CREATURES;i++){
        listeCreature[i]=nullptr;
    }
    nombreDresseur_=0;
    nombreCreature_=0;
}

Polyland::~Polyland()   //Destructeur
{
    for(int i=0;i<MAX_NOMBRE_DRESSEURS;i++){
        delete listeDresseur[i];
    }
    delete [] listeDresseur;
    listeDresseur=nullptr;
    for(int i=0;i<MAX_NOMBRE_CREATURES;i++){
        delete listeCreature[i];
    }
    delete [] listeCreature;
    listeCreature=nullptr;
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
bool Polyland::ajouterDresseur(Dresseur* dresseur)
{
    if(nombreDresseur_==100){   //Test pour savoir si le tableau est déjà plein
        cout<<"Polyland est déjà surpeuplée en dresseurs ! Pas de rajout possible !"<<endl;
        return false;
    }
    else{
        bool existe=false;
        int trou=nombreDresseur_;
        for(int i=0;i<nombreDresseur_;i++){
            if(listeDresseur[i]->getNom() == dresseur->getNom()){ //on teste si ce dresseur existe déjà
                existe=true;
            }
            if(listeDresseur[i]==nullptr){
                trou=i;
            }
        }
        if(!existe){
            listeDresseur[trou]= dresseur;
            nombreDresseur_++;
            cout<<"Bienvenue à Polyland, "<<dresseur->getNom()<<endl;
            return true;
        }
        else{
            cout<<"Ce dresseur existe déjà !"<<endl;
            return false;
        }
    }
}

bool Polyland::retirerDresseur(const string& nom)
{
    if(nombreDresseur_==0){
        cout<<"Le tableau est déjà vide !"<<endl;
        return false;
    }
    else{
        bool supprime=false;
        for(int i=0;i<nombreDresseur_;i++){
            if(listeDresseur[i]->getNom() == nom){ //on teste si ce dresseur existe
                listeDresseur[i] = nullptr;
                nombreDresseur_--;
                supprime=true;
                cout<<nom<<" a bien été expulsé de Polyland"<<endl;
                return true;
            }
        }
        if(!supprime){
            cout<<"Ce dresseur n'existe pas !"<<endl;
            return false;
        }
    }
}

//Modifier le tableau de creatures
bool Polyland::ajouterCreature(Creature creature)
{
    if(nombreCreature_==1000){   //Test pour savoir si le tableau est déjà plein
        cout<<"Polyland est déjà surpeuplée en créatures. Pas de rajout possible "<<endl;
        return false;
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
            listeCreature[trou]= new Creature(creature);
            nombreCreature_++;
            cout<<creature.getNom()<<" a bien été ajouté"<<endl;
            return true;
        }
        else{
            cout<<"Une créature possède déjà ce nom "<<endl;
            return false;
        }
    }
}

bool Polyland::retirerCreature(string nom)
{
    if(nombreCreature_==0){
        cout<<"Le tableau est déjà vide !"<<endl;
        return false;
    }
    else{
        bool supprime=false;
        for(int i=0;i<nombreCreature_;i++){
            if(listeCreature[i]->getNom() == nom){ //on teste si cette créature existe
                listeCreature[i] = nullptr;
                nombreCreature_--;
                supprime=true;
                cout<<nom<<" a bien été retiré de la liste"<<endl;
                return true;
            }
        }
        if(!supprime){
            cout<<"Aucune créature ne possède ce nom"<<endl;
            return false;
        }
    }
}

//Méthodes aléatoires
Dresseur* Polyland::choisirDresseurAleatoire()
{
    int choix=0;
    do{
    choix = rand() % nombreDresseur_;
    }
    while(listeDresseur[choix]==nullptr);
    return listeDresseur[choix];
}

Creature* Polyland::choisirCreatureAleatoire()
{
    int choix=0;
    do{
    choix = rand() % nombreCreature_;
    }
    while(listeCreature[choix]==nullptr);
    return listeCreature[choix];
}

//Attraper et relacher des créatures
bool Polyland::attraperCreature(Dresseur* dresseur, Creature creature)
{
    bool attrape=false;
    if(dresseur->ajouterCreature(creature)){
        attrape=true;
    }
    return attrape;
}

bool Polyland::relacherCreature(Dresseur* dresseur, const string& nom)
{
    bool relache=false;
    if(dresseur->retirerCreature(nom)){
        relache=true;
    }
    return relache;
}

//Infos Dresseur
void Polyland::infosDresseur(const string& nom) const
{
    int indiceNom=nombreDresseur_+1;
    for(int i=0;i<nombreDresseur_;i++){
        if(listeDresseur[i]->getNom()==nom){
            indiceNom=i;
        }
    }
    if(indiceNom<nombreDresseur_){
        listeDresseur[indiceNom]->affichage();
    }
    else{
        cout<<"Il n'y a pas de dresseur avec ce nom à Polyland"<< endl;
    }
}
