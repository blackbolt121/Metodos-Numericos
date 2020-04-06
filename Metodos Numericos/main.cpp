#include <iostream>
#include "buscarEnPolinomio.h"
using namespace std;
int main() {
	list<float> coeficientes = buscarEnPolinomio::coeficientes("1x^2+2x+1");
	for (float a : coeficientes) {
		cout << a << endl;
	}
	return 0;
}