#include <iostream>
#include "Fila.h"   // troque para o nome do arquivo onde está a Fila
using namespace std;

int main() {

    Fila<int> fila;

    cout << "=========== Teste Inicial ===========" << endl;
    cout << "Fila vazia? " << (fila.isEmpty() ? "sim" : "nao") << endl;
    cout << "Tamanho: " << fila.getTamanho() << endl;

    cout << "\n=========== Teste push() ===========" << endl;
    fila.push(10);
    fila.push(20);
    fila.push(30);

    cout << "Depois de inserir 10, 20, 30:" << endl;
    cout << "Fila vazia? " << (fila.isEmpty() ? "sim" : "nao") << endl;
    cout << "Tamanho: " << fila.getTamanho() << endl;
    cout << "front(): " << fila.front() << endl;
    cout << "back(): " << fila.back() << endl;

    //cout << "\n=========== Modificar front() ===========" << endl;
    //cout << "Alterando front() para 99..." << endl;
    //fila.front() = 99;
    //cout << "Novo front(): " << fila.front() << endl;

    cout << "\n=========== Teste pop() ===========" << endl;
    fila.pop();
    cout << "Depois de 1 pop():" << endl;
    cout << "front(): " << fila.front() << endl;
    cout << "back(): " << fila.back() << endl;
    cout << "Tamanho: " << fila.getTamanho() << endl;

    fila.pop();
    fila.pop();

    cout << "\n=========== Fila vazia ===========" << endl;
    cout << "Fila vazia? " << (fila.isEmpty() ? "sim" : "nao") << endl;
    cout << "Tamanho: " << fila.getTamanho() << endl;

    cout << "\n=========== pop() em fila vazia ===========" << endl;
    fila.pop();

    cout << "\n=========== front() em fila vazia ===========" << endl;
    fila.front();   // vai imprimir mensagem do teu método

    cout << "\n=========== back() em fila vazia ===========" << endl;
    fila.back();    // vai imprimir mensagem do teu método

    return 0;
}
