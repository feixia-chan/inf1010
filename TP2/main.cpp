#include <iostream>
#include "Creature.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include <time.h>
#include <clocale>  // pour setlocale

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	cout << "CREATION DES DRESSEURS" << endl;
	// Creer DYNAMIQUEMENT les dresseurs suivants (nom):
	// ("Sasha")
	// ("Pierre")
	// ("Regis")
	// A COMPLETER...


	cout << endl << "CREATION ET AFFICHAGE DES CREATURES" << endl;
	// Creer les Creatures suivantes (nom, attaque, defense, pointDeVie, mana):
	// ("Pokachu", 10, 2, 50, 25)
	// ("Salimouche", 12, 3, 45, 20)
	// ("Carapouce", 10, 1, 55, 25)
	// ("Balbazar", 11, 2, 50, 22)
	// A COMPLETER...

	// Creer la Creature Touflamme en utilisant l'opérateur = et en utilisant la creature existante Salimouche.
	// Le nom de Touflamme devrai ensuite etre modifie pour "Touflamme" et son attaque passera de 12 a 15.
	// A COMPLETER...

	// Creer la Creature Pokachoum en utilisant le constructeur de copie et en utilisant la creature existante Pokachu.
	// Le nom de Pokachoum devrai ensuite etre modifie pour "Pokachoum" et sa defense passera de 2 a 7.
	// A COMPLETER...

	// Afficher les informations sur Pokachu, Touflamme et Pokachum
	// A COMPLETER...


	// Creer les pouvoirs suivants
	// ("Boule de feu", 5, 5)
	// pistoletAEau("Pistolet a eau", 6, 6)
	// eclair("Eclair", 10, 5)
	// A COMPLETER...


	// Creer le pouvoir lanceFeuille en utilisant le contructeur par copie et en utilisant le pouvoir bouleDeFeu.
	// Le nom du pouvoir lanceFeuille doit ensuite etre modifie pour "Lance Feuille".
	// A COMPLETER...


	// Creer le pouvoir tonerre en utilisant l'operateur = et en utilisant le pouvoir eclair.
	// Le nom du pouvoir tonerre doit ensuite etre modifie pour "Tonerre" et son nombre de degat doit etre diminue a 3.
	// A COMPLETER...



	// Faites afficher les informations des pouvoirs bouleDeFeu, lanceFeuille et tonnerre.
	// A COMPLETER...


	// Ajouter le pouvoir a la creature correspondante
	// Salimouche -> bouleDeFeu
	// Carapouce -> pistoletAEau
	// Balbazar -> lanceFeuille
	// Pokachu -> eclair et tonnerre
	// Touflamme -> tonnerre
	// Pokachum -> eclair
	// A COMPLETER...

	cout << endl << "AJOUT DE CREATURES ET DE DRESSEURS A POLYLAND" << endl << endl;

	PolyLand polyland;


	// Ajouter les dresseurs et les creatures. Attention, vous devez utiliser l'operateur += pour ajouter un dresseur.
	// A COMPLETER...


	//Ce dresseur est deja present, il ne devrais pas s'ajouter.
	// A COMPLETER...
	polyland += Pierre;

	cout << "TEST D'AFFICHAGE" << endl << endl;
	// Tests d'affichage
	cout << polyland << endl;
	cout << *(polyland.choisirCreatureAleatoire()) << endl;
	cout << *(polyland.choisirDresseurAleatoire()) << endl;

	cout << endl << "COMPETITION" << endl;
	// Debut de la competition
	cout << endl << "Bienvenue a Polyland" << endl;
	Dresseur Vous("Hey", "Team INF1010");


	// Cette commande ne devrait pas fonctionner
	Carapouce.oublierPouvoir(&eclair);


	// Assignez une creature au dresseur.
	// Sasha -> Salimouche
	// Pierre -> Balbazar
	// Regis -> Carapouce
	// A COMPLETER...

	// Assignez à vous-meme Pokachu
	// A COMPLETER...

	/*******************************************************************/
	/*                       DEBUT DES TESTS                           */
	/* Les modifications restantes sont a la fin de la fonction main.  */
	/*******************************************************************/
	//Duel entre vous et salimouche
	cout << endl << "TESTS DE COMBAT" << endl;

	cout << endl << "Un Salimouche surgit" << endl;

	cout << "Vous avez rencontré un Salimouche sauvage qui vous attaque..." << endl;

	Salimouche.attaquer(bouleDeFeu, *(Vous.getUneCreature("Pokachu")));
	Vous.getUneCreature("Pokachu")->attaquer(eclair, Salimouche);
	//Vous gagnez obligatoirement le duel
	while (Salimouche.getPointDeVie() > 0) {
		((Vous.getUneCreature("Pokachu")))->attaquer(eclair, Salimouche);
	}
	cout << "Vous avez battu un Salimouche, vous pouvez maintenante le capturer" << endl;

	if (polyland.attraperCreature(&Vous, &Salimouche)) {
		cout << "Felicitation vous avez attrapé un Salimouche !" << endl;
	}
	else {
		cout << "Le Salimouche s'est échappé" << endl;
	}


	cout << endl;
	cout << "Vous trouvez une potion magique, vous décidez de l'utilisez sur Pokachu" << endl;

	ObjetMagique potionMagique("Potion magique", 15);
	cout << potionMagique << endl;
	//Vous venez de trouver une potion magique
	Vous.setObjetMagique(potionMagique);
	//Soin de votre creature
	Vous.utiliserObjetMagique(Vous.getUneCreature("Pokachu"));

	//Choix d'une creature aleatoirement parmi celles possibles
	Creature* creatureAleatoire = polyland.choisirCreatureAleatoire();
	//Debut du duel avec la creature choisie aléatoirement
	cout << endl << "Un " << creatureAleatoire->getNom() << " se jette sur votre Pokachu" << endl;
	cout << "Un duel entre Pokachu et " << creatureAleatoire->getNom() << " est engagé" << endl;

	//Vous attaquez la créature tant que qu'elle est en vie...
	while (creatureAleatoire->getPointDeVie() > 0) {
		if (Vous.getUneCreature("Pokachu")->getPointDeVie() > 0) {
			//... ou que votre créature est morte
			(Vous.getUneCreature("Pokachu"))->attaquer(eclair, *creatureAleatoire);
			if (creatureAleatoire->getPointDeVie() > 0)
				creatureAleatoire->attaquer(*(creatureAleatoire->getPouvoirs()[0]), *(Vous.getUneCreature("Pokachu")));
		}
		else
			break;
	}

	//Il se peut que vous gagniez...
	if (creatureAleatoire->getPointDeVie() == 0)
		cout << "Vous avez vaincu " << creatureAleatoire->getNom() << endl;
	else {
		//Sinon votre seconde créature se charge de finir le combat
		while (creatureAleatoire->getPointDeVie() > 0)
			(Vous.getUneCreature("Salimouche"))->attaquer(bouleDeFeu, *creatureAleatoire);
		cout << "Votre Pokachu a été battu mais heuresement votre Salimouche finit par vaincre " << creatureAleatoire->getNom() << endl;
	}





	cout << "Pokachu et salimouche n'arrete pas de se chamailler, vous decidez d'abandonner Salimouche" << endl;

	//Vous en avez marre des chamailleries, vous décidez de relacher Salimouche
	if (polyland.relacherCreature(&Vous, "Salimouche")) {
		cout << "Vous avez decidé de relacher Salimouche !" << endl;
	}
	else {
		//ce cas ne devrait pas s'afficher
		cout << "Oh il y a eu un petit problème technique... Salimouche n'a pas pu être relaché" << endl;
	}

	/*******************************/
	/*       FIN DES TESTS         */
	/*******************************/


	cout << endl << "INFO DRESSEUR APRES TOUTES CES PERIPETIES" << endl;
	// Afficher les informations de Polyland
	// A COMPLETER...
	cout << endl << "DERNIER TESTS" << endl;
	// Cette commande ne devrait pas fonctionner
	Carapouce.oublierPouvoir(&eclair);

	// Suite a un combat intense, Carapouce perd son pouvoir pistoletAEau. Retirez ce pouvoir.
	// A COMPLETER...
	Carapouce.oublierPouvoir(&pistoletAEau);

	// test des opérateurs == de la classe Dresseur
	Dresseur test1("test", "testeur");
	Dresseur test2("test", "testeur");
	test1.ajouterCreature(&Pokachu);
	test1.ajouterCreature(&Touflamme);
	test2.ajouterCreature(&Touflamme);
	test2.ajouterCreature(&Pokachu);

	cout << "________________________________________________" << endl;
	cout << "TEST OPERATEURS" << endl << endl;
	cout << "dresseur == dresseur : \t" << (test1 == test2) << " --- Reponse attendue : 1" << endl;
	cout << "dresseur == nom : \t" << (test1 == test2.getNom()) << " --- Reponse attendue : 1" << endl;
	cout << "nom == dresseur : \t" << (test1.getNom() == test2) << " --- Reponse attendue : 1" << endl;

	test1.ajouterCreature(&Carapouce);
	cout << "dresseur == dresseur : \t" << (test1 == test2) << " --- Reponse attendue : 0" << endl;

	test1.setNom("testNouveau");
	cout << "dresseur == nom : \t" << (test1 == test2.getNom()) << " --- Reponse attendue : 0" << endl;
	cout << "nom == dresseur : \t" << (test1.getNom() == test2) << " --- Reponse attendue : 0" << endl;


	// Liberer les ressources s'il le faut
	// A COMPLETER...


	system("pause");
	return 0;
}
