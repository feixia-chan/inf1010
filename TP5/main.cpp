/*
Fichier: main.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 24 septembre 2016 par Maude Carrier
Description: Programme de test
*/

#include <iostream>
#include <time.h>
#include <clocale>  // pour setlocale
#include <functional> //pour bind
#include <map>

#include "AttaqueMagique.h"
#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"
#include "ObjetMagique.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include "CreatureMagique.h"
#include "Foncteur.h"

using namespace std;


int main()
{
	srand(time(NULL));
    setlocale(LC_ALL, "");

	// Dresseurs
    Dresseur vous("Vous", "PolyMtl");
    Dresseur sacha("Sacha", "UDEM");

    //Creatures
    Creature pokachu("Pokachu", 10, 20, 100, 50);
    Creature salimouche("Salimouche", 20, 15, 110, 50);

	// Creer la CREATURE MAGIQUE pokachoum en utilisant la creature existante pokachu et un bonus de 3.
	// Le nom de pokachoum devrai ensuite etre modifie pour "Pokachoum" et sa defense passera de 2 a 7.
	// A COMPLETER...
	CreatureMagique pokachoum(pokachu,3);
	pokachoum.setNom("Pokachoum");
	pokachoum.setDefense(7);

	// Creer la CREATURE MAGIQUE Touflamme en utilisant la creature existante Salimouche et un bonus de 2.
	// Le nom de Touflamme devrai ensuite etre modifie pour "Touflamme" et son attaque passera de 12 a 15.
	// A COMPLETER...
	CreatureMagique touflamme(salimouche,2);
	touflamme.setNom("Touflamme");
	touflamme.setAttaque(15);

    //Pouvoirs
    Pouvoir bouleDeFeu("Boule de feu", 5, 5);
	Pouvoir eclair("Eclair", 10, 5);
	Pouvoir tonerre("Tonnerre", 15, 10);

	// Faites apprendre le pouvoir bouleDeFeu par Salimouche, les pouvoirs tonerre et eclair par pokachu ainsi que le pouvoir
	// tonerre par touflamme.
	// A COMPLETER...
	salimouche.apprendrePouvoir(&bouleDeFeu);
	pokachu.apprendrePouvoir(&eclair);
	pokachu.apprendrePouvoir(&tonerre);
	touflamme.apprendrePouvoir(&tonerre);

	PolyLand polyland;

	// Ajouter les dresseurs vous et sacha ainsi que les créatures pokachu, salimouche,
	// pokachoum et touflamme à polyland avec l'opérateur +=
	// A COMPLETER...
	polyland+=vous;
	polyland+=sacha;
	polyland+=pokachu;
	polyland+=salimouche;
	polyland+=pokachoum;
	polyland+=touflamme;

	// En vous promenant dans Polyland, vous attrappez un pokachu et Sacha attrappe un salimouche et un touflamme
	// A COMPLETER...
	polyland.attraperCreature(&vous,&pokachu);
	polyland.attraperCreature(&sacha,&salimouche);
	polyland.attraperCreature(&sacha,&touflamme);

    cout << "TEST AFFICHAGE" << endl;
    cout << "pouvoir de la creature avant trie" << endl;
    cout << pokachu << endl;

    pokachu.trierPouvoir(FoncteurComparerPouvoir());
    cout << "pouvoir de la creature apres trie" << endl;
    cout << pokachu << endl;

	cout << "Affichage de Polyland" << endl;
	cout << polyland << endl;
    cout << "FIN TEST AFFICHAGE" << endl;
    cout <<  endl;

    cout << "TEST DRESSEUR" << endl;

    if (vous == sacha) //Les deux dresseurs n'ont pas les mêmes créatures
        cout << "DRESSEUR operateur== : Erreur Technique!!!!" << endl;

    sacha.ajouterCreature(&pokachu);
    vous.ajouterCreature(&salimouche);
    vous.ajouterCreature(&touflamme);
    if (!(vous == sacha)) //Les deux dresseurs ont maintenant les mêmes créatures
        cout << "DRESSEUR operateur== : Erreur Technique!!!!" << endl;
    vous.enleverCreature(touflamme.getNom());

    FoncteurCreatureVie vieCompriseEntre(80, 150);
    vous.appliquerFoncteurUnaire(vieCompriseEntre);
    if (vieCompriseEntre.getCompteur() == 2)
        cout << "appliquerFoncteurUnaire: OK" << endl;
    else
        cout << "appliquerFoncteurUnaire: Erreur Technique!!!!" << endl;

    cout << "TEST DRESSEUR : get element max" << endl;
    cout << *(vous.getCreatureMax(FoncteurComparerCreature())) << endl;
    cout << "TEST DRESSEUR : FIN get element max" << endl;

    cout << "TEST DRESSEUR : suppression" << endl;
    //Supprime les créatures ayant une attaque supérieure a
    //attaque max
    unsigned int attaqueMax = 11;
    FoncteurObtenirAttaqueCreature getAttaque;
    vous.supprimerElements(
        bind(
            /*A COMPLETER générer un opérateur > pour les entiers*/
            greater<int>(),
            //Le bind ci-dessous permet d'appeler la méthode getAttaque() de la
            //Creature* passée en argument du foncteur lors des appels de ce dernier dans supprimerElements
                bind(
                    getAttaque, _1
                    /*A COMPLETER utiliser le premier placeholder (attention aux namespace) (reçoit un Creature*)*/
                ),
                /*A COMPLETER faire en sorte que le résultat de getAttaque() soit comparer à attaquer max*/
             attaqueMax
        )
    );
    //N.B: A l'issue de la fonction vous ne devriez plus posséder de Salimouche

    cout << vous << endl;
    cout << "FIN TEST DRESSEUR" << endl;
    cout << endl;


    cout << "Début MAP" << endl;
    cout << "Soyez fiers dresseurs, l'incroyable tournoi de polyland a lieu aujourd'hui!!!" << endl;

    //Les règles de ce tournoi sont particulières, chaque dresseur ne peut inscrire qu'une seule créature!!!
    //Créez une map Dresseur*-->Creature* avec une clé qui compare les dresseurs* en ordre alphabétique suivant leur nom.
    //Cette map utilisera peut-être un foncteur pour faire la comparaison ...
	// Cette map permettra de savoir quel dresseur a inscrit quelle créature!
	// A COMPLETER...
	map<Dresseur*,Creature*,FoncteurComparerDresseurs> creaturesInscrites;

	//Vous désirez inscrire pokachu au tournoi
	//Sacha désire inscrire touflamme au tournoi
	// A COMPLETER...
	creaturesInscrites[&vous]=&pokachu;
	creaturesInscrites[&sacha]=&touflamme;

    cout << "Début MAP" << endl;
    cout << "Vous a inscrit la créature:" << endl;
    cout << *(creaturesInscrites[&vous]) << endl;
    cout << "Sacha a inscrit la créature:" << endl;
    cout << *(creaturesInscrites[&sacha]) << endl;

	//Debut du duel avec Touflamme
	cout << endl << "Touflamme se jette sur votre Pokachu" << endl;
	cout << "Un duel entre Pokachu et Touflamme est engagé" << endl;

	//Vous attaquez Touflamme tant que qu'elle est en vie, et miraculeusement touflamme ne réplique jamais... Vous allez gagner ce duel.
	//Étapes: While (touflamme a encore des points de vie) { pokachu attaque }
	//Faites bien attention à utiliser les créatures qui se trouvent dans la map, et non les créature de Polyland.
    //Vous êtes dans un tournoi après tout !!
	//A COMPLETER...
	while(creaturesInscrites[&sacha]->getPointDeVie()>0){
        creaturesInscrites[&vous]->attaquer(*creaturesInscrites[&vous]->getPouvoirs()[0],*creaturesInscrites[&sacha]);
	}
	cout<<"Pokachu a vaincu Touflamme !"<<endl;

	//Sacha désire remplacer sa créature inscrite au tournoi. Remplacez Touflamme par Salimouche.
	// A COMPLETER...
	creaturesInscrites[&sacha]=&salimouche;
	cout<<"Sacha a desormais inscrit Salimouche au tournoi"<<endl;


	cout << endl << "FIN DE POLYLAND ... :(" << endl << endl;

	// Supprimer Touflamme de polyland à l'aide de la méthode supprimerCompagnon et le FoncteurCreaturesDeMemeNom
	// A COMPLETER...
	polyland.supprimerCompagnon(FoncteurCreaturesDeMemeNom("Touflamme"));

	polyland -= &sacha;
	polyland -= &pokachu;

	// Affichage de polyand
	cout << polyland << endl;

	polyland.vider();

	system("pause");
	return 0;
}
