#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

using namespace std;

class ObjetMagique
{
    public:
        //Constructeurs
        ObjetMagique();
        ObjetMagique(string nom, int bonus);
        //Destructeur
        ~ObjetMagique();
        //Accesseurs
        string getNom() const;
        int getBonus() const;
        //Modificateurs
        void setNom(const string& nom);
        void setBonus(const int& bonus);
        //Affichage
        void afficher() const;

    private:
        //Attributs
        string nom_;
        int bonus_;
};

#endif // OBJETMAGIQUE_H
