#ifndef EXCEPTIONATTAQUEECHOUEE_H
#define EXCEPTIONATTAQUEECHOUEE_H

#include <exception>

using namespace std;
class ExceptionAttaqueEchouee : public runtime_error
{
    //lancée lors de l’échec d’une attaque à cause du manque d’énergie de la créature
public:
 ExceptionAttaqueEchouee(string what_arg = "");

};

ExceptionAttaqueEchouee::ExceptionAttaqueEchouee(string what_arg) : runtime_error(what_arg)
{
}



#endif // EXCEPTIONATTAQUEECHOUEE_H
