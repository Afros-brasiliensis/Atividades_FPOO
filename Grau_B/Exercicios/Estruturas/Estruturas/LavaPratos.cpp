#include "LavaPratos.h"


int simularCozinha(int turnos) {

	int pilha = 0; // pratos sujos na pilha

	for (int t = 1; t <= turnos; t++) {
		int lavados = rand() % 5 + 1; // lava entre 1 e 5 pratos
		int secos = rand() % 3 + 1; // seca entre 1 e 3 pratos

		pilha += lavados; //adiciona pratos lavados
		pilha -= secos; //remove pratos secos

		if (pilha < 0) {
			pilha = 0; // nao pode ter pratos negativos
		}

		cout << "Turno " << t << ": "
			<< lavados << " pratos lavados, "
			<< secos << " pratos secos, "
			<< pilha << " pratos na pilha." << endl;
	}
	return pilha;
}
