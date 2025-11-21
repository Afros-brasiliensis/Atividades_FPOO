#include <iostream>
#include <ctime>
#include <cstdlib>
#include "LavaPratos.h"   // já declara simularCozinha(int)

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int turnos = 10; // numero de turnos a simular

    int pratos = simularCozinha(turnos);

    cout << "\nPratos restantes ao final: " << pratos << endl;

    return 0;
}
