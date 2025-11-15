#include <iostream>
#include "Pilhas.h"
using namespace std;

int main() {
    Pilha<int> pilha;

    cout << "Adicionando elementos..." << endl;
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    cout << "Tamanho atual: " << pilha.getTamanho() << endl;
    cout << "Topo atual: " << pilha.top() << endl;

    cout << "Procurando valor 20: " << (pilha.Find(20) ? "encontrado!" : "não encontrado!") << endl;
    cout << "Procurando valor 50: " << (pilha.Find(50) ? "encontrado!" : "não encontrado!") << endl;

    cout << "\nRemovendo topo..." << endl;
    pilha.pop();
    cout << "Novo topo: " << pilha.top() << endl;
    cout << "Tamanho: " << pilha.getTamanho() << endl;

    cout << "\nEsvaziando pilha..." << endl;
    while (!pilha.isEmpty()) {
        cout << "Removendo " << pilha.top() << endl;
        pilha.pop();
    }

    cout << "\nPilha vazia? " << (pilha.isEmpty() ? "Sim" : "Não") << endl;

    return 0;
}
