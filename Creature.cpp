#include "Creature.h"

//https://github.com/feixia-chan/inf1010.git    maude.carrier@polymtl.ca


void Creature::attaquer(const Pouvoir & pouvoir, Creature & creature)   //modifié
{
		//L'attaque est possible si votre créature a assez d'energie
		//Et que la creature adverse a encore des points de vie
		if(this->energie_>pouvoir.getEnergieNecessaire && creature->pointDeVie_>=0){



			//Calcul du nombre de degat selon une formule
			unsigned int degat = (pouvoir.getNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			//On choisit un nombre aléatoire entre 1 et 6
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				//Afficher le nom de la créature qui lance l'attaque, le nom de l'attaque,
				//le nombre de dégat infligé, et la créature qui est attaquée
				cout << this->getNom() << "lance une attaque" << pouvoir.getNom <<"!" << endl;
				cout << degat << "points de dégâts sont infligés à " << creature.getNom() << endl;

                //encaissement des dégâts par la créature
                creature.setPointDeVie(creature.getPointDeVie()-degat);
                int xp = experienceGagner(creature);

				//Afficher le nombre d'XP gagné ou non
				if(xp!=0){ //la créature adverse est morte
                    cout this->getNom() << "a gagné"<< xp << "point d'expérience !" << endl;
				}
                else {
                    cout creature.getNom() << a encore << creature.getPointDeVie() <<endl;
				//Afficher le nombre de point de vie restant de la créature attaquée
				//Faites attention aux requis d'une attaque

                }
			}
		}
        else {
            //La créature adverse est déjà vaincue
            std::cout << "Attaque " << pouvoir.getNom() << " a échouée" << endl;
        }
    }

}

int Creature::experienceGagner(const Creature& creature)    //a modifier
{
	if (creature.getPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.getNiveau() + 1 - niveau_) * ((creature.getAttaque() + 5 - attaque_) *
		 (creature.getDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) { //on peut lvl up
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotale_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else {
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::information(){
    cout << "Nom : "<< this->getNom() <<endl;
    cout << "Niveau : "<< this->getNiveau() <<endl;
    cout << "Experience totale : "<< this->getExperience() <<endl;
    cout << "Expérience nécessaire pour le prochain niveau: "<< this->getExperienceNecessaire() <<endl;
    cout << "Pouvoir : "<< this->getPouvoir() <<endl;
    cout << "Points de vie restants : "<< this->getPointDeVie() << "/" << this->getPointDeVieTotal() << endl;
    cout << "Attaque : "<< this->getAttaque() <<endl;
    cout << "Defense : "<< this->getDefense() <<endl;
    cout << "Energie restante : "<< this->getEnergie() << "/"<< this->getEnergieTotale <<  endl;
}
