#pragma once
#include "Listas.h"
#include <iostream>
using namespace std;

template <typename T>
class FilaPrioridade {
private:
    Lista<T> lista;

public:
    void pushNormal(const T& item) {
        lista.push_back(item);
    }

    void pushUrgente(const T& item) {
        lista.push_front(item);
    }

    void pop() {
        lista.pop_front();
    }

    T& front() {
        return lista.front();
    }

    bool isEmpty() const {
        return lista.isEmpty();
    }

    int size() const {
        return lista.getTamanho();
    }
};

int main() {
    FilaPrioridade<string> fila;

    fila.pushNormal("Pessoa A");
    fila.pushNormal("Pessoa B");
    fila.pushUrgente("URGENTE: Pessoa C");
    fila.pushNormal("Pessoa D");

    while (!fila.isEmpty()) {
        cout << "Atendendo: " << fila.front() << endl;
        fila.pop();
    }
}
