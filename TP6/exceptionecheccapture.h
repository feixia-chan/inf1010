#ifndef EXCEPTIONECHECCAPTURE_H
#define EXCEPTIONECHECCAPTURE_H

#include <exception>

using namespace std;
class ExceptionEchecCapture : public runtime_error
{
    //lancée lors de l’échec d’une attaque à cause du manque d’énergie de la créature
public:
 ExceptionEchecCapture(string what_arg = "");

};

ExceptionEchecCapture::ExceptionEchecCapture(string what_arg) : runtime_error(what_arg)
{
}


#endif // EXCEPTIONECHECCAPTURE_H
