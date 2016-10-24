

/*
Fichier: main.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:
Description: Programme de test
*/

#include <iostream>
#include <time.h>
#include <typeinfo>

#include "Creature.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include "Professeur.h"
#include "CreatureMagique.h"
#include "PotionMagique.h"
#include "PouvoirPoison.h"
#include "PouvoirHallucinogene.h"
#include "PouvoirSoporifique.h "
#include "GreenBull.h"
#include "Elixir.h"
#include "EtatConfus.h"
#include "EtatEmpoisonne.h"
#include "EtatEndormi.h"

using namespace std;

void appliquerEtatSelonType(Creature& creature) {
    EtatCreature* etat = creature.getEtat();
    EtatEmpoisonne* etatPoison;
    EtatEndormi* etatEndormi;
    EtatConfus* etatConfus;
    switch (etat->getType())
    {
    case TypeEtat_normal:
        etat->appliquerEtat(creature);
        break;
    case TypeEtat_empoisonne:
        etatPoison = static_cast<EtatEmpoisonne*>(creature.getEtat());
        etatPoison->appliquerEtat(creature);
        break;
    case TypeEtat_endormi:
        etatEndormi = static_cast<EtatEndormi*>(creature.getEtat());
        etatEndormi->appliquerEtat(creature);

        break;
    case TypeEtat_confus:
        etatConfus = static_cast<EtatConfus*>(creature.getEtat());
        etatConfus->appliquerEtat(creature);

        break;
    default:
        break;
    }
}

//TODO à compléter appelle la méthode appropriée selon le type
//dit si la créature peut attaquer, il faut appeler la bonne
// méthode de étatCréature ou d'une de ses classes filles
bool peutAttaquerSelonType(Creature& creature) {
    bool peutAttaquer = false;
    EtatCreature* etat = creature.getEtat();
    EtatEmpoisonne* etatPoison;
    EtatEndormi* etatEndormi;
    EtatConfus* etatConfus;
    switch (etat->getType())
    {
    case TypeEtat_normal:
        peutAttaquer = etat->peutAttaquer();
        break;
    case TypeEtat_empoisonne:
        etatPoison = static_cast<EtatEmpoisonne*>(creature.getEtat());
        peutAttaquer = etatPoison->peutAttaquer();
        break;
    case TypeEtat_endormi:
        etatEndormi = static_cast<EtatEndormi*>(creature.getEtat());
        peutAttaquer = etatEndormi->peutAttaquer();
        break;
    case TypeEtat_confus:
        //TODO
        etatConfus = static_cast<EtatConfus*>(creature.getEtat());
        peutAttaquer = etatConfus->peutAttaquer();
        break;
    default:
        break;
    }
    return peutAttaquer;
}

//TODO à compléter (s'inpirer des fonctions au-dessus)
bool estFiniSelonType(Creature& creature) {
    bool estFini = false;
    EtatCreature* etat = creature.getEtat();
    EtatEmpoisonne* etatPoison;
    EtatEndormi* etatEndormi;
    EtatConfus* etatConfus;
    switch (etat->getType())
    {
    case TypeEtat_normal:
        //TODO
        estFini = etat->estFini();
        break;
    case TypeEtat_empoisonne:
        etatPoison = static_cast<EtatEmpoisonne*>(creature.getEtat());
        etatPoison->estFini();
        break;
    case TypeEtat_endormi:
        etatEndormi = static_cast<EtatEndormi*>(creature.getEtat());
        estFini = etatEndormi->estFini();
        cout <<estFini << endl;
        break;
    case TypeEtat_confus:
        etatConfus = static_cast<EtatConfus*>(creature.getEtat());
        estFini = etatConfus->estFini();
        break;
    default:
        break;
    }
    return estFini;
}

//TODO étudier le fonctionnement et s'en inspirer pour l'implémentation des
//operator << dans les classes filles /!\ il est probable qu'il faille
//que l'opérateur<< ne travaille pas, il faudra sûrement adapter la méthode
//ci-dessous
void afficherEtatSelonType(Creature& creature) {
    EtatCreature* etat = creature.getEtat();
    EtatEmpoisonne* etatPoison;
    EtatEndormi* etatEndormi;
    EtatConfus* etatConfus;
    cout << creature.getNom() << " est dans l'état: ";
    switch (etat->getType())
    {
    case TypeEtat_normal:
        cout << *etat << endl;
        break;
    case TypeEtat_empoisonne:
        etatPoison = static_cast<EtatEmpoisonne*>(creature.getEtat());
        cout <<*etatPoison << " Empoisonne durera : " << etatPoison->getDuree()<< " tours"<< endl;
        break;
    case TypeEtat_endormi:
        etatEndormi = static_cast<EtatEndormi*>(creature.getEtat());
        cout << *etatEndormi << " : Somnolence durera : " << etatEndormi->getDuree()<< " tours"<<endl;
        break;
    case TypeEtat_confus:
        etatConfus = static_cast<EtatConfus*>(creature.getEtat());
        cout << *etatConfus <<" : Confusion durera : " << etatConfus->getDuree()<< " tours"<<  endl;
        break;
    default:
        break;
    }
}
/*###############################################################################
*###############################Debut MAIN#######################################*
*################################################################################*/
int main()
{
	srand(time(NULL));
    setlocale(LC_ALL, "");

    cout << "BIENVENU DANS LE MONDE MERVEILLEUX DE POLYLAND" << endl;
    //TODO créez un Professeur nommé Chen ("Chen", "Laboratoire Poly")
    Professeur Chen("Chen","Laboratoire Poly");

    OutilScientifique scanner("scanner", "étudier une créature");
    cout << scanner << endl;
    Chen.setOutil(scanner);
    Dresseur mauvaisGars("Jessie", "Team Rocket");

    //TODO créez les créatures suivantes
    //miaouss ("Miaouss", 10, 2, 50, 22) type = Creature
    //pokachu ("Pokachu", 10, 2, 100, 25) type = Creature
    //Salimouche ("Salimouche", 12, 3, 45, 20) type = Creature
    //rondodu ("Rondodu", 10, 2, 50, 25) type = Creature
    //mewtwo ("Mewtwo", 20, 3, 50, 25, 5) type = CreatureMagique
    Creature Miaouss("Miaouss", 10, 2, 50, 22);
    Creature Pokachu("Pokachu", 10, 2, 100, 25);
    Creature Salimouche("Salimouche", 12, 3, 45, 20);
    Creature Rondodu("Rondodu", 10, 2, 50, 25);
    CreatureMagique Mewtwo("Mewtwo", 20, 3, 50, 25, 5);

    cout << "TEST : affichage de la créature magique" << endl;
    cout << Mewtwo << endl;
    cout << "FIN TEST : affichage de la créature magique" << endl;

    //TODO Créez les pouvoirs suivants
    // eclair ("Eclair", 10, 5) type = Pouvoir
    //morsureVenin ("Morsure Venin", 10, 5, 3) type = PouvoirPoison
    //ondeFolie ("onde Folie", 4, 5, 4) type = PouvoirHallucinogene
    //berceuse ("Berceuse", 2, 5, 2) type = PouvoirSoporifique
    //telekinesie ("Telekinesie", 15, 5, 4) type = PouvoirHallucinogene
    Pouvoir eclair("Eclair", 10, 5);
    PouvoirPoison morsureVenin("Morsure Venin", 10, 5, 3);
    PouvoirHallucinogene ondeFolie("Onde Folie", 4, 5, 4);
    PouvoirSoporifique berceuse("Berceuse", 2, 5, 2);
    PouvoirHallucinogene telekinesie("Telekinesie", 15, 5, 4);

    cout << "TEST AFFICHAGE Pouvoir" << endl;
    cout << eclair << endl;
    cout << morsureVenin << endl;
    cout << ondeFolie << endl;
    cout << berceuse << endl;
    cout << telekinesie << endl;
    cout << "FIN : TEST AFFICHAGE Pouvoir" << endl;

    Pokachu.apprendrePouvoir(&eclair);
    Miaouss.apprendrePouvoir(&morsureVenin);
    Miaouss.apprendrePouvoir(&ondeFolie);
    Rondodu.apprendrePouvoir(&berceuse);
    Mewtwo.apprendrePouvoir(&telekinesie);

    mauvaisGars.ajouterCreature(&Miaouss);
    Chen.ajouterCreature(&Salimouche);

    cout << "TEST PolyLand " << endl;
    PolyLand polyland;
    polyland += &Miaouss;
    polyland += &Pokachu;
    polyland += &Rondodu;
    polyland += &Mewtwo;
    polyland += &Chen;
    polyland += &mauvaisGars;
    cout << polyland << endl;
    cout << "FIN TEST PolyLand " << endl;

    Dresseur Vous("Etudiant", "Team INF1010");
    Vous.ajouterCreature(&Pokachu);
    cout << "LA TEAM MISSILE VOUS ATTAQUE" << endl;
    while (Pokachu.getPointDeVie() > 0 && Miaouss.getPointDeVie() > 0)
    {
        Miaouss.attaquer(morsureVenin, Pokachu);
        morsureVenin.appliquerEffetOffensif(Pokachu);
        //Pauvre pokachu, l'attaque l'a possiblement empoisonné!
        appliquerEtatSelonType(Pokachu);
        if (peutAttaquerSelonType(Pokachu)){
            Pokachu.attaquer( eclair, Miaouss);
        }
        if (estFiniSelonType(Pokachu)){
            Pokachu.setEtat(new EtatCreature("normal")); //attention aux fuites mémoires
      }

        cout << "Fin d'attaque, affichage de l'etat de Pokachu" << endl;
        cout << "Pokachu est dans l'état: " << *(Pokachu.getEtat()) <<endl;
        cout << "affichage de l'etat de Pokachu (autre méthode)" << endl << endl;
        afficherEtatSelonType(Pokachu);
    }

    if (Pokachu.getPointDeVie() > 0) {
        cout << "Felicitation vous avez gagné" << endl;
    }
    else {
        cout << "Hum Pokachu est mal en point" << endl;
    }
    //Test potion magique
    PotionMagique potion("Potion", 10);
    unsigned int ancienPointDeVie = Pokachu.getPointDeVie();
    cout << "Vous utilisez une potion magique" << endl;
    cout << potion << endl;
    potion.utiliserSur(Pokachu);
    if (Pokachu.getPointDeVie() == ancienPointDeVie + 10)
        cout << "Potion: OK" << endl;

    //Test GreenBull
    GreenBull boissonTonique("greenBull", 10);
    unsigned int ancienneEnergie = Pokachu.getEnergie();
    cout << "Vous utilisez une boisson énergisante" << endl;
    cout << boissonTonique << endl;
    boissonTonique.utiliserSur(Pokachu);
    if (Pokachu.getEnergie() == ancienneEnergie + 10)
        cout << "GreenBull: OK" << endl;

    //Test elixir
    Pokachu.setEnergie(Pokachu.getEnergie() - 10);
    ancienneEnergie = Pokachu.getEnergie();
    ancienPointDeVie = Pokachu.getPointDeVie();
    Elixir elixir("elixir", 10);
    elixir.utiliserSur(Pokachu);
    if (Pokachu.getEnergie() == ancienneEnergie + 10 &&
        Pokachu.getPointDeVie() == ancienPointDeVie + 20) {
        cout << "Elixir: OK" << endl;
    }
    //Le professeur soigne votre créature
    Chen.soigner(Pokachu);
    if (Pokachu.getPointDeVie() == Pokachu.getPointDeVieTotal() &&
        Pokachu.getEnergie() == Pokachu.getEnergieTotale()) {
        cout << "Soigner: OK" << endl;
    }

    cout << "C'est incroyable, une créature magique vous attaque" << endl;
    while (Mewtwo.getPointDeVie() > 0 && Pokachu.getPointDeVie() > 0)
    {
        //l'attaque devrait augmenter les points de vie de la créature
        unsigned int pointDeVie = Mewtwo.getPointDeVie();
        Mewtwo.attaquer(telekinesie, Pokachu);
        //Les points de vie de la créature doivent augmenter
        //quand elle attaque
        if (Mewtwo.getPointDeVie() >= pointDeVie) {
            cout << "Creature magique OK" << endl;
        }
        telekinesie.appliquerEffetOffensif(Pokachu);

        //TODO : appliquer l'état selon le type
        //Indice: regardez plus haut dans le code
        if (peutAttaquerSelonType(Pokachu))
            Pokachu.attaquer(eclair, Mewtwo);

        if (estFiniSelonType(Pokachu))
            Pokachu.setEtat(new EtatCreature("normal"));

        //TODO : afficher l'etat en prenant en compte le type
        //Indice: regardez plus haut dans le code
        //et répondre à la question relative à l'affichage
    }
    Chen.soigner(Pokachu);
    cout << "Votre Pokachu surprend un Rondodu, terrifié celui-ci lui chante une berceuse" << endl;
    Rondodu.attaquer(berceuse, Pokachu);
    berceuse.appliquerEffetOffensif(Pokachu);
    //rondodu (ou plutot Pokachu ?) devrait dormir pour deux tours
    for (unsigned int i = 0; i < 4; ++i) {
        appliquerEtatSelonType(Pokachu);
    }
    if (estFiniSelonType(Pokachu)) {
        cout << "Pokachu s'est réveillé! : Berceuse OK" << endl;
    }
    else {
        cout << "Bizarre pokachu aurait dû se réveiller..." << endl;
    }
    //Attention aux double free et fuites mémoires
    Professeur Phelina(Chen);
    Professeur Orme(Chen);
    Orme = Phelina;
    //vérification de la copie
    cout << "TEST Professeur : affichage de l'information des professeurs" << endl;
    cout << Chen << endl;
    cout << Orme << endl;
    cout << Phelina << endl;
    cout << "FIN TEST" << endl;




    //delete : pas de delete dans notre cas ?



	return 0;
}
