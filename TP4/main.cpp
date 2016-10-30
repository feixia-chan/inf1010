/*
Fichier: main.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier
Description: Programme de test
*/

#include <iostream>
#include "Creature.h"
#include "CreatureMagique.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include "AttaqueMagique.h"
#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    cout << "CREATION DES DRESSEURS" << endl;
    // Creer DYNAMIQUEMENT les dresseurs suivants (nom, equipe):
    // ("Sasha", "Team de feu")
    // ("Pierre", "Equipe de Poly")
    // ("Regis", "Equipe de Poly")
    Dresseur* Sasha = new Dresseur("Sasha", "Team de feu");
    Dresseur* Pierre = new Dresseur("Pierre", "Equipe de Poly");
    Dresseur* Regis = new Dresseur("Regis", "Equipe de Poly");

    cout << endl << "CREATION DES CREATURES" << endl;
    // Creer les Creatures suivantes (nom, attaque, defense, pointDeVie, energie):
    // ("Pokachu", 10, 2, 50, 25)
    // ("Salimouche", 12, 3, 45, 20)
    // ("Carapouce", 10, 1, 55, 25)
    // ("Balbazar", 11, 2, 50, 22)
    Creature Pokachu = Creature("Pokachu", 10, 2, 50, 25);
    Creature Salimouche = Creature("Salimouche", 12, 3, 45, 20);
    Creature Carapouce = Creature("Carapouce", 10, 1, 55, 25);
    Creature Balbazar = Creature("Balbazar", 11, 2, 50, 22);

    cout << "CRÉATION DES POUVOIRS" << endl;
    // Creer les pouvoirs ci-dessous (nom, degat, energie)
    // ("Boule de feu", 5, 5)
    // ("Pistolet a eau", 6, 6)
    // ("Eclair", 10, 5)
    // ("Etincelle", 8, 6)
    Pouvoir bouleDeFeu("Boule de feu", 5, 5);
    Pouvoir pistoletAEau("Pistolet a eau", 6, 6);
    Pouvoir eclair("Eclair", 10, 5);
    Pouvoir etincelle("Etincelle", 8, 6);

    // Creer le pouvoir lanceFeuille en utilisant le contructeur par copie et en utilisant le pouvoir bouleDeFeu.
    // Le nom du pouvoir lanceFeuille doit ensuite etre modifie pour "Lance Feuille".
    Pouvoir lanceFeuille(bouleDeFeu);
    lanceFeuille.setNom("Lance feuille");

    // Creer le pouvoir tonerre en utilisant l'operateur = et en utilisant le pouvoir eclair.
    // Le nom du pouvoir tonerre doit ensuite etre modifie pour "Tonerre" et son nombre de degat doit etre diminue a 3.
    Pouvoir tonerre;
    tonerre = eclair;
    tonerre.setNom("Tonerre");
    tonerre.setNombreDeDegat(3);

    cout << "CRÉATION DES CREATURES MAGIQUES" << endl;
    // Creer la CREATURE MAGIQUE Touflamme en utilisant la creature existante Salimouche et un bonus de 2.
    // Le nom de Touflamme devrai ensuite etre modifie pour "Touflamme" et son attaque passera de 12 a 15.
    // A COMPLETER...
    CreatureMagique Touflamme(Salimouche,2);
    Touflamme.setNom("Touflamme");
    Touflamme.setAttaque(15);

    // Creer la CREATURE MAGIQUE Pokachoum en utilisant la creature existante Pokachu et un bonus de 3.
    // Le nom de Pokachoum devrai ensuite etre modifie pour "Pokachoum" et sa defense passera de 2 a 7.
    // A COMPLETER...
    CreatureMagique Pokachoum(Pokachu,3);
    Pokachoum.setNom("Pokachoum");
    Pokachoum.setDefense(7);

    cout << "CRÉATION DES ATTAQUES MAGIQUES" << endl;
    //Creer une attaque magique de poison avec le constructeur par défaut
    // A COMPLETER...
    AttaqueMagiquePoison* attaquePoisonm = new AttaqueMagiquePoison();
    //Creer une attaque magique de confusion qui a une durée de 4
    // A COMPLETER...
    AttaqueMagiqueConfusion* attaqueConfusionm = new AttaqueMagiqueConfusion(4);

    cout << "APPRENTISSAGE DES POUVOIRS" << endl;
    // Ajouter le pouvoir a la creature correspondante
    // Salimouche -> bouleDeFeu
    // Carapouce -> pistoletAEau
    // Balbazar -> lanceFeuille
    // Pokachu -> eclair et tonnerre
    // Touflamme -> etincelle
    // Pokachoum -> eclair
    Salimouche.apprendrePouvoir(&bouleDeFeu);
    Carapouce.apprendrePouvoir(&pistoletAEau);
    Balbazar.apprendrePouvoir(&lanceFeuille);
    Pokachu.apprendrePouvoir(&eclair);
    Pokachu.apprendrePouvoir(&tonerre);
    Touflamme.apprendrePouvoir(&etincelle);
    Pokachoum.apprendrePouvoir(&eclair);

    cout << "APPRENTISSAGE DES ATTAQUES MAGIQUES" << endl;
    // Ajouter l'attaque magique à la créature magique correspondante
    // Pokachoum -> Confusion
    // Touflamme -> Poison
    // A COMPLETER...
    Pokachoum.apprendreAttaqueMagique(attaqueConfusionm);
    Touflamme.apprendreAttaqueMagique(attaquePoisonm);

    cout << endl << "AJOUT DE CREATURES ET DE DRESSEURS A POLYLAND" << endl << endl;

    PolyLand polyland;

    // Ajouter les dresseurs et les creatures. Attention, vous devez utiliser l'operateur += pour ajouter un dresseur.
    polyland += &Salimouche;
    polyland += &Carapouce;
    polyland += &Balbazar;
    polyland += &Pokachu;
    polyland += &Touflamme;
    polyland += &Pokachoum;

    polyland += Regis;
    polyland += Pierre;
    polyland += Sasha;

    Dresseur Vous("Hey", "Team INF1010");

    // Assignez une creature au dresseur.
    // Sasha -> Salimouche
    // Pierre -> Balbazar
    // Regis -> Touflamme
    Sasha->ajouterCreature(&Salimouche);
    Pierre->ajouterCreature(&Balbazar);
    Regis->ajouterCreature(&Touflamme);

    // Assignez à vous-meme Pokachoum
    Vous.ajouterCreature(&Pokachoum);

    cout << "TEST D'AFFICHAGE" << endl << endl;
    cout << polyland << endl;


    cout << endl << "COMPETITION" << endl;


    /*******************************************************************/
    /*                       DEBUT DES TESTS                           */
    /* Les modifications restantes sont a la fin de la fonction main.  */
    /*******************************************************************/
    //Duel entre vous et salimouche
    cout << endl << "TESTS DE COMBAT" << endl;

    cout << endl << "Un Salimouche surgit" << endl;

    cout << "Vous avez rencontré un Salimouche sauvage qui vous attaque..." << endl;


    Salimouche.attaquer(bouleDeFeu, *(Vous.getUneCreature("Pokachoum")));
    Vous.getUneCreature("Pokachoum")->attaquer(eclair, Salimouche);
    //Vous gagnez obligatoirement le duel
    while (Salimouche.getPointDeVie() > 0)
    {
        ((Vous.getUneCreature("Pokachoum")))->attaquer(eclair, Salimouche);
    }
    cout << "Vous avez battu un Salimouche, vous pouvez maintenante le capturer" << endl;

    if (polyland.attraperCreature(&Vous, &Salimouche))
    {
        cout << "Felicitation vous avez attrapé un Salimouche !" << endl;
    }
    else
    {
        cout << "Le Salimouche s'est échappé" << endl;
    }

    cout << endl;
    cout << "Vous trouvez une potion magique, vous décidez de l'utilisez sur Pokachoum" << endl;

    ObjetMagique potionMagique("Potion magique", 15);
    cout << potionMagique << endl;
    //Vous venez de trouver une potion magique
    Vous.setObjetMagique(potionMagique);
    //Soin de votre creature
    Vous.utiliserObjetMagique(Vous.getUneCreature("Pokachoum"));

    //Debut du duel avec Touflamme
    cout << endl << "Touflamme se jette sur votre Pokachoum" << endl;
    cout << "Un duel entre Pokachoum et Touflamme est engagé" << endl;

    //Vous attaquez la créature tant que qu'elle est en vie...
    while (Touflamme.getPointDeVie() > 0)
    {
        if (Vous.getUneCreature("Pokachoum")->getPointDeVie() > 0)
        {
            //... ou que votre créature est morte
            (Vous.getUneCreature("Pokachoum"))->attaquer(eclair, Touflamme);
            if (Touflamme.getPointDeVie() > 0)
            {
                Touflamme.attaquer(*(Touflamme.getPouvoirs().back()), *(Vous.getUneCreature("Pokachoum")));
                //Attention ici Touflamme n'ingligera pas de dommages à pokachoum car d'après la formule des dégats
                //on a 8*(15/2 - 7) or 15/2 égal 7 ici donc les dommages sont nuls
            }
        }
        else
            break;
    }

    //Il se peut que vous gagniez...
    if (Touflamme.getPointDeVie() == 0)
        cout << "Vous avez vaincu Touflamme" << endl;
    else
    {
        //Sinon votre seconde créature se charge de finir le combat
        while (Touflamme.getPointDeVie() > 0)
            (Vous.getUneCreature("Salimouche"))->attaquer(bouleDeFeu, Touflamme);
        cout << "Votre Pokachoum a été battu mais heuresement votre Salimouche finit par vaincre Touflamme" << endl;
    }

    cout << "Pokachoum et Salimouche n'arrete pas de se chamailler, vous decidez d'abandonner Pokachum" << endl;

    //Vous en avez marre des chamailleries, vous décidez de relacher Salimouche
    if (polyland.relacherCreature(&Vous, "Pokachoum"))
    {

        cout << "Vous avez bien relaché Pokachoum !" << endl;
    }
    else
    {
        //ce cas ne devrait pas s'afficher
        cout << "Oh il y a eu un petit problème technique... Pokachoum n'a pas pu être relaché" << endl;
    }


    cout << endl << "DERNIER TEST AFFICHAGE" << endl;
    cout << Salimouche << endl;
    cout << Carapouce << endl;
    cout << Salimouche << endl;
    cout << Balbazar << endl;
    cout << Pokachu << endl;
    cout << Touflamme << endl;
    cout << Pokachoum << endl;

    /*******************************/
    /*       FIN DES TESTS         */
    /*******************************/

    // Liberer les ressources si il le faut
    // A COMPLETER...

    //dresseurs
    delete Sasha;
    delete Pierre;
    delete Regis;
    delete attaqueConfusionm;
    delete attaquePoisonm;

    system("pause");
    return 0;
}
