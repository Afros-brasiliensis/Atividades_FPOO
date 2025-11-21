#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Listas.h"

using namespace std;

// Estrutura representando um combatente de RPG
struct Combatente {
    string nome;
    int iniciativa;
};

// Insere o combatente na lista de forma ORDENADA por iniciativa (maior primeiro)
// Se a iniciativa for igual à de outro, entra depois (ordem estável)
void inserirOrdenadoPorIniciativa(Lista<Combatente>& lista, const Combatente& c) {
    int n = lista.getTamanho();

    // procurar posição onde a iniciativa do novo é MAIOR que a da lista
    int pos = 0;
    while (pos < n && lista.at(pos).iniciativa >= c.iniciativa) {
        pos++;
    }
    // pos é a posição onde vamos inserir
    lista.push_At(pos, c);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Lista<Combatente> ordem;
    const int NUM_COMBATENTES = 10;

    // Cria e insere os 10 combatentes
    for (int i = 0; i < NUM_COMBATENTES; ++i) {
        Combatente c;
        c.nome = "Combatente " + to_string(i + 1);
        c.iniciativa = rand() % 10 + 1; // 1..10

        inserirOrdenadoPorIniciativa(ordem, c);
    }

    cout << "===== Ordem de combate (maior iniciativa primeiro) =====\n";
    for (int i = 0; i < ordem.getTamanho(); ++i) {
        const Combatente& c = ordem.at(i);
        cout << i << " - " << c.nome
            << " (iniciativa = " << c.iniciativa << ")\n";
    }

    return 0;
}
