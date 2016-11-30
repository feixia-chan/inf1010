#ifndef EXCEPTIONCREATUREMORTE_H
#define EXCEPTIONCREATUREMORTE_H

#include <exception>

using namespace std;
class ExceptionCreatureMorte : public runtime_error
{
    // lancée lors de l’échec de l’attaque sur une créature car celle-ci n’a plus de point de vie.
public:
 ExceptionCreatureMorte(string what_arg = "");
static int obtenirValeurCompteur(){return compteur_;}
private:
 static int compteur_;


};

int ExceptionCreatureMorte::compteur_=0; //init de l`attribut statique

ExceptionCreatureMorte::ExceptionCreatureMorte(string what_arg) : runtime_error(what_arg)
{
    compteur_++;
}


#endif // EXCEPTIONCREATUREMORTE_H
