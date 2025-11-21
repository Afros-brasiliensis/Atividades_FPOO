#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

using namespace std;

/**
 * Simula a gestão de uma pilha de pratos sujos ao longo de vários turnos.
 * Em cada turno, um número aleatório de pratos é "lavado" (adicionado)
 * e um número aleatório de pratos é "seco" (removido).
 *
 * @param turnos O número de turnos a simular.
 * @return O número final de pratos na pilha.
 */
int simularCozinha(int turnos) {
    int pilha = 0; // pratos sujos na pilha, inicialmente 0

    for (int t = 1; t <= turnos; t++) {
        // Gera números aleatórios:
        // rand() % N + 1 gera números inteiros entre 1 e N.
        int lavados = rand() % 5 + 1; // lava entre 1 e 5 pratos
        int secos = rand() % 3 + 1;   // seca entre 1 e 3 pratos

        // Atualiza a pilha:
        pilha += lavados; // adiciona pratos lavados
        pilha -= secos;   // remove pratos secos (secagem)

        // A pilha não pode ter um número negativo de pratos.
        if (pilha < 0) {
            pilha = 0; // Garante que a pilha mínima é 0
        }

        // Exibe o estado do turno:
        cout << "Turno " << t << ": "
            << lavados << " pratos lavados, "
            << secos << " pratos secos, "
            << pilha << " pratos na pilha." << endl;
    }

    return pilha; // Retorna o saldo final da pilha
}

int main() {
    // Inicializa o gerador de números aleatórios
    // Isso deve ser feito uma única vez no início do programa.
    srand(time(0));

    int num_turnos = 10;
    cout << "--- Iniciando Simulação por " << num_turnos << " Turnos ---" << endl;

    int pratos_finais = simularCozinha(num_turnos);

    cout << "--- Simulação Concluída ---" << endl;
    cout << "Resultado Final: " << pratos_finais << " pratos restantes na pilha." << endl;

    return 0;
}