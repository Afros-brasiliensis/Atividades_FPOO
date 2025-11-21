#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;

template <typename T>
class Fila {
private:
    Nodo<T>* inicio;
    Nodo<T>* fim;
    int tamanho;
public:
    Fila();//Construtor
    ~Fila();//Destrutor

    void push(const T& object);//Adiciona um elemento no fim da fila
    void pop();//Remove o elemento do inicio da fila
    const T& front() const;//Retorna o elemento do inicio da fila
    const T& back() const;//Retorna o elemento do fim da fila
    bool isEmpty() const;//Retorna se a fila esta vazia
    int getTamanho() const;//Retorna o tamanho da fila

};

template <typename T>
Fila<T>::Fila() {
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
}

template <typename T>
Fila<T>::~Fila() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Fila<T>::push(const T& object) {
    Nodo<T>* novoNodo = new Nodo<T>(object);
    if (isEmpty()) {
        this->inicio = novoNodo;
        this->fim = novoNodo;
    }
    else {
        novoNodo->setAnterior(fim);
        fim->setProximo(novoNodo);
        fim = novoNodo;
    }
    tamanho++;
}

template <typename T>
void Fila<T>::pop() {
    if (isEmpty()) {
        cout << "Fila vazia, nao eh possivel remover esse elemento" << endl;
    }
    else {
        Nodo<T>* auxiliar = inicio;
        inicio = inicio->getProximo();
        if (inicio != nullptr) {
            inicio->setAnterior(nullptr);
        }
        else {
            fim = nullptr;
        }

        delete auxiliar;
        tamanho--;
    }
}

template <typename T>
const T& Fila<T>::front() const {
    if (isEmpty()) {
        cout << "Fila vazia." << endl;
        static T empty = T();  // Static ensures it persists
        return empty;
    }
    else {
        return inicio->getValor();
    }
}

template <typename T>
const T& Fila<T>::back() const {
    if (isEmpty()) {
        cout << "Fila vazia." << endl;
        static T empty = T();  // Static ensures it persists
        return empty;
    }
    else {
        return fim->getValor();
    }
}

template <typename T>
bool Fila<T>::isEmpty() const {
    return tamanho == 0;
}

template <typename T>
int Fila<T>::getTamanho() const {
    return tamanho;
}
//Exercicios de simulacao de filas

int main() {
    srand(time(0));

    Fila<int> fila;
    int turnos;

    cout << "Digite o numero de iteracoes: ";
    cin >> turnos;

    int totalChegadas = 0;
    int totalSaidas = 0;

    for (int i = 1; i <= turnos; i++) {

        // Chegam de 2 a 5 pessoas
        int chegadas = rand() % 4 + 2;
        totalChegadas += chegadas;

        for (int c = 0; c < chegadas; c++) {
            fila.push(rand() % 100);
        }

        // Saem 0 a 2 pessoas
        int saidas = rand() % 3;
        totalSaidas += saidas;

        for (int s = 0; s < saidas; s++) {
            if (!fila.isEmpty()) fila.pop();
        }

        cout << "Iteracao " << i
            << " | Chegadas: " << chegadas
            << " | Saidas: " << saidas
            << " | Tamanho atual: " << fila.getTamanho()
            << endl;
    }

    cout << "\nTotal de chegadas: " << totalChegadas
        << " | Media: " << (double)totalChegadas / turnos << endl;

    cout << "Total de saidas: " << totalSaidas
        << " | Media: " << (double)totalSaidas / turnos << endl;

    return 0;
}

// Simulacao do estacionamento usando fila

int main() {
    Fila<int> estacionamento;

    char comando;
    int placa;

    while (true) {
        cout << "(C)hegada, (S)air carro, (V)isualizar, (X)sair do programa: ";
        cin >> comando;

        if (comando == 'C' || comando == 'c') {
            cout << "Placa: ";
            cin >> placa;
            estacionamento.push(placa);
        }
        else if (comando == 'S' || comando == 's') {
            cout << "Placa a remover: ";
            cin >> placa;

            Fila<int> aux;

            // Retira todos até achar a placa
            bool encontrou = false;
            while (!estacionamento.isEmpty()) {
                if (estacionamento.front() == placa) {
                    estacionamento.pop();
                    encontrou = true;
                    break;
                }
                else {
                    aux.push(estacionamento.front());
                    estacionamento.pop();
                }
            }

            // Carros que deram a volta voltam pro fim
            while (!aux.isEmpty()) {
                estacionamento.push(aux.front());
                aux.pop();
            }

            if (!encontrou) cout << "Carro nao encontrado.\n";
        }
        else if (comando == 'V' || comando == 'v') {
            Fila<int> aux = estacionamento;

            cout << "Estacionamento: ";
            while (!aux.isEmpty()) {
                cout << aux.front() << " ";
                aux.pop();
            }
            cout << endl;
        }
        else if (comando == 'X' || comando == 'x') {
            break;
        }
    }
}
