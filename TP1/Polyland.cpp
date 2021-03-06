#include "Polyland.h"

Polyland::Polyland()    //Constructeur
{
    listeDresseur_ = new Dresseur*[100];
    for(int i=0;i<MAX_NOMBRE_DRESSEURS;i++){
        listeDresseur_[i]=nullptr;
    }
    listeCreature_ = new Creature*[1000];
    for(int i=0;i<MAX_NOMBRE_CREATURES;i++){
        listeCreature_[i]=nullptr;
    }
    nombreDresseur_=0;
    nombreCreature_=0;
}

Polyland::~Polyland()   //Destructeur
{
    for(int i=0;i<MAX_NOMBRE_DRESSEURS;i++){
        delete listeDresseur_[i];
    }
    delete [] listeDresseur_;
    listeDresseur_=nullptr;
    for(int i=0;i<MAX_NOMBRE_CREATURES;i++){
        delete listeCreature_[i];
    }
    delete [] listeCreature_;
    listeCreature_=nullptr;
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
    if(nombreDresseur_==MAX_NOMBRE_DRESSEURS){
        //Test pour savoir si le tableau est déjà plein
        cout<<"Polyland est déjà surpeuplée en dresseurs ! Pas de rajout possible !"<<endl;
        return false;
    }
    else{
        bool existe=false; //existence du dresseur
        int trou=MAX_NOMBRE_DRESSEURS;
        int i =0;
       while(i<MAX_NOMBRE_DRESSEURS && !existe){
            if (listeDresseur_[i]!=nullptr && listeDresseur_[i]->getNom() == dresseur->getNom()){ //on teste si ce dresseur existe déjà
                existe=true;
                cout << "existant" <<endl;
            }
            //on cherche la première place disponible
            if(listeDresseur_[i]==nullptr && trou>=i){
                trou=i;
                cout << i;
            }

            i++;
        }
        cout << endl;
        //si ce dresseur n'est pas déjà à polyland
        if(!existe){
            cout << "non existant";
            //on l'insère à la première place disponible
           listeDresseur_[trou]= new Dresseur(*dresseur);
            cout <<"insertion place" << trou <<endl;
            //on incrémente le nombre de dresseurs
            nombreDresseur_++;
            cout<<"Bienvenue "<<dresseur->getNom()<<endl;
            return true;
        }
        else{
            //si le dresseur est déjà à polyland
            cout<<"Ce dresseur est déjà à Polyland !"<<endl;
            return false;
        }
    }
}

bool Polyland::retirerDresseur(const string& nom)
{
    if(nombreDresseur_==0){     //on regarde si le tableau n'est pas vide
        cout<<"Il n'y a aucun dresseur a Polyland"<<endl;
        return false;
    }
    else{
        bool supprime=false;
        for(int i=0;i<nombreDresseur_;i++){
            if(listeDresseur_[i]->getNom() == nom){ //on teste si ce dresseur existe
               listeDresseur_[i]=nullptr;
                nombreDresseur_--;                 //et on décrémente le nombre de dresseurs
                supprime=true;
                cout<<nom<<" a bien été expulsé de Polyland"<<endl;
                return true;
            }
        }
        if(!supprime){      //on vérifie si le dresseur a ete supprime de polyland
            cout<<"Ce dresseur n'existe pas !"<<endl;   //si non c'est que le dresseur appelé n'existe pas
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
        int trou=MAX_NOMBRE_CREATURES;
        int i=0;
         while(i<MAX_NOMBRE_CREATURES && !existe){
            if(listeCreature_[i]!=nullptr && listeCreature_[i]->getNom() == creature.getNom()){ //on teste si cette créature existe déjà
                existe=true;
            }
            //on regarde où est la première place disponible
            if(listeCreature_[i]==nullptr && trou>=i){
                trou=i;
            }
            i++;
        }
        if(!existe){
            //si elle n'est pas à Polyland alors on la met à la première place disponible
            listeCreature_[trou]= new Creature(creature);
            //on incrémente alors le nombre de créatures
            nombreCreature_++;
            //on indique que la creature a été ajoutée
            cout<<creature.getNom()<<" a bien été ajouté"<<endl;
            return true;
        }
        else{
            //si la créature est déjà à polyland
            cout<<"Une créature possède déjà ce nom "<<endl;
            return false;
        }
    }
}

bool Polyland::retirerCreature(string nom)
{
    if(nombreCreature_==0){     //on vérifie que le tableau n'est pas vide
        cout<<"Il n'y a aucune creature a Polyland"<<endl;
        return false;
    }
    else{
        bool supprime=false;
        for(int i=0;i<nombreCreature_;i++){
            if(listeCreature_[i]->getNom() == nom){  //on teste si cette créature existe
                listeCreature_[i] = nullptr;         //on la retire
                nombreCreature_--;                  // et on décrémente le nombre de créatures
                supprime=true;
                //on indique que la creature a été retirée
                cout<<nom<<" a bien été retiré de la liste"<<endl;
                return true;
            }
        }
        if(!supprime){      //dans le cas où on la creature appelée n'est pas dans la liste
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
    while(listeDresseur_[choix]==nullptr);   //on va chercher un dresseur de manière aléatoire qui ne soit pas null
    return listeDresseur_[choix];
}

Creature* Polyland::choisirCreatureAleatoire()
{
    int choix=0;
    do{
    choix = rand() % nombreCreature_;
    }
    while(listeCreature_[choix]==nullptr);   //on va chercher une creature de maniere aléatoire qui ne soit pas null
    return listeCreature_[choix];
}

//Attraper et relacher des créatures
bool Polyland::attraperCreature(Dresseur* dresseur, Creature creature)
{
    //on regénère la créature
    creature.setEnergie(creature.getEnergieTotale());
    creature.setPointDeVie(creature.getPointDeVieTotal());

    return(dresseur->ajouterCreature(creature));    //on retourne si la creature a bien été ajoutée au dresseur
}

bool Polyland::relacherCreature(Dresseur* dresseur, const string& nom)
{
    return(dresseur->retirerCreature(nom));         //on retourne si la creature a bien été ajoutée au dresseur
}

//Infos Dresseur
void Polyland::infosDresseur(const string& nom) const
{
    //on va chercher l'indice du dresseur portant le nom en paramètre
    //on initialise l'indice à un nombre supérieur au nombre de dresseurs max (au cas où il y aurait des trous dans la liste)

    int indiceNom=-1, i=0;

    while(i<MAX_NOMBRE_DRESSEURS && indiceNom==-1){
        if(listeDresseur_[i]!=nullptr && listeDresseur_[i]->getNom()==nom){
            indiceNom=i;
        }
        else{
            i++;
        }
    }
    //si le dresseur était bien à polyland alors l'indice est inférieur au nombre de dresseur max
    if(indiceNom>=0){
        //on affiche les infos du dresseur
        listeDresseur_[i]->affichage();
    }
    else{
        //sinon le dresseur n'est pas à polyland
        cout<<"Il n'y a pas de dresseur avec ce nom à Polyland"<< endl;
    }
}
