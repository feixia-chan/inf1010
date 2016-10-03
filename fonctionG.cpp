/**********
 * ENONCE *
 **********
 * 1/ Modifiez la fonction 'inverser' afin de la rendre générique.
 *
 * 2/ La fonction obtenue peut-elle accepter n'importe quel type?
 *    non car les deux objets créés ont chacuns leur type : il faut un constructeur par copie et il faut que = soit surchargé
 */

#include <iostream>
using namespace std;

template <typename T>
void inverser(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

int main() {
	int aInt = 2;
	int bInt = 4;
	cout << "'aInt' est: " << aInt << ", et 'bInt' est: " << bInt << endl;
	inverser(aInt, bInt);
	cout << "'aInt' est: " << aInt << ", et 'bInt' est: " << bInt << endl;

	string aStr = "a";
	string bStr = "b";
	cout << "'aStr' est: " << aStr << ", et 'bStr' est: " << bStr << endl;
	// La ligne suivante devrait fonctionner!
	inverser(aStr, bStr);
	cout << "'aStr' est: " << aStr << ", et 'bStr' est: " << bStr << endl;
}