#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Pilhas.h"
#include "Listas.h"

using namespace std;

struct Carta {
    string valor;  // "A", "2", ..., "10", "J", "Q", "K"
    string naipe;  // "Ouros", "Espadas", "Copas", "Paus"
};

string cartaToString(const Carta& c) {
    return c.valor + " de " + c.naipe;
}

// Monta um baralho padrão de 52 cartas em um array
void montarBaralho(Carta baralho[], int tamanho) {
    string valores[13] = { "A", "2", "3", "4", "5", "6", "7",
                           "8", "9", "10", "J", "Q", "K" };
    string naipes[4] = { "Ouros", "Espadas", "Copas", "Paus" };

    int k = 0;
    for (int n = 0; n < 4; ++n) {
        for (int v = 0; v < 13; ++v) {
            baralho[k].valor = valores[v];
            baralho[k].naipe = naipes[n];
            k++;
        }
    }
}

// Embaralha o array (Fisher-Yates simples)
void embaralhar(Carta baralho[], int tamanho) {
    for (int i = tamanho - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

// Mostra as cartas retiradas (lista)
void mostrarCartas(const Lista<Carta>& lista) {
    // como at() não é const, vamos fazer um cast feio mas funcional
    Lista<Carta>& ref = const_cast<Lista<Carta>&>(lista);

    cout << "===== Cartas retiradas =====\n";
    for (int i = 0; i < ref.getTamanho(); ++i) {
        cout << i << " - " << cartaToString(ref.at(i)) << "\n";
    }
    if (ref.getTamanho() == 0) {
        cout << "(nenhuma carta retirada ainda)\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int TOTAL_CARTAS = 52;
    Carta baralhoArray[TOTAL_CARTAS];

    montarBaralho(baralhoArray, TOTAL_CARTAS);
    embaralhar(baralhoArray, TOTAL_CARTAS);

    // Baralho organizado em pilha
    Pilha<Carta> baralho;

    // Empilha todas as cartas
    for (int i = 0; i < TOTAL_CARTAS; ++i) {
        baralho.push(baralhoArray[i]);
    }

    // Lista das cartas retiradas
    Lista<Carta> retiradas;

    char opcao;

    do {
        cout << "\n===== MENU BARALHO =====\n";
        cout << "1 - Retirar uma carta do baralho\n";
        cout << "2 - Mostrar cartas retiradas\n";
        cout << "3 - Reordenar cartas retiradas\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == '1') {
            if (baralho.isEmpty()) {
                cout << "Baralho vazio, nao ha mais cartas.\n";
            }
            else {
                Carta c = baralho.top();
                baralho.pop();
                retiradas.push_back(c);
                cout << "Voce retirou: " << cartaToString(c) << "\n";
            }
        }
        else if (opcao == '2') {
            mostrarCartas(retiradas);
        }
        else if (opcao == '3') {
            if (retiradas.getTamanho() == 0) {
                cout << "Nao ha cartas retiradas para reordenar.\n";
            }
            else {
                mostrarCartas(retiradas);

                int origem, destino;
                cout << "Digite o indice da carta que deseja mover: ";
                cin >> origem;
                cout << "Digite a nova posicao dessa carta: ";
                cin >> destino;

                if (origem < 0 || origem >= retiradas.getTamanho()) {
                    cout << "Indice de origem invalido.\n";
                }
                else {
                    // ajusta destino para ficar no intervalo valido
                    if (destino < 0) destino = 0;
                    if (destino > retiradas.getTamanho() - 1)
                        destino = retiradas.getTamanho() - 1;

                    Carta cartaMovida = retiradas.at(origem);
                    retiradas.pop_At(origem);
                    retiradas.push_At(destino, cartaMovida);

                    cout << "Nova ordem:\n";
                    mostrarCartas(retiradas);
                }
            }
        }

    } while (opcao != '0');

    cout << "Encerrando programa do baralho...\n";
    return 0;
}
