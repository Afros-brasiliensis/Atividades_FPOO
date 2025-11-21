#include "Nodo.h"
#include <iostream>
using namespace std;

template <typename T>
class Pilha{
    private:
        Nodo<T>* topo;
        Nodo<T>* base;
        T tamanho;

    public: 
        Pilha();//Construtor
        ~Pilha();//Destrutor

        void push(const T& object);//Adiciona um elemento no topo da pilha
        void pop();//Remove o elemento do topo da pilha
        T top();//Retorna o elemento do topo da pilha sem remover
        bool Find(const T& object);//Acha um valor dentro da pilha
        bool isEmpty();//Verifica se a pilha esta vazia

        int getTamanho();//Retorna o tamanho da pilha
};

template <typename T>
Pilha<T>::Pilha(){
    this->topo = nullptr;
    this->base = nullptr;
    this->tamanho = 0;
}

template <typename T>
Pilha<T>::~Pilha(){
    while(!isEmpty()){
        pop();
    }
}

template <typename T>
void Pilha<T>::push(const T& object){
    Nodo<T>* novoNodo = new Nodo<T>(object);
    if(isEmpty()){
        this->base = novoNodo;
        this->topo = novoNodo;
    }
    else{
        novoNodo->setAnterior(topo);
        topo->setProximo(novoNodo);
        topo = novoNodo;
    }
    tamanho++;
}

template <typename T>
void Pilha<T>::pop(){
    if(isEmpty()){
        cout << "Pilha vazia, não é possível remover esse elemento" << endl;
    }
    else{
        Nodo<T>* auxiliar = topo;
        topo = topo->getAnterior();

        if(topo != nullptr){
            topo->setProximo(nullptr);
        }
        else{
            base = nullptr; // A pilha ta vazia
        }
        delete auxiliar;
        tamanho--;
    }
}

template <typename T>
T Pilha<T>::top(){
    if(isEmpty()){
        cout << "Pilha vazia." << endl;
        return T();
    }
    else{
        return topo->getValor();
    }
}

template <typename T>
bool Pilha<T>::Find(const T& object){
    if(isEmpty()){
        return false;
    }
    Nodo<T>* auxiliar = topo;
    do {
        if(auxiliar->getValor() == object){
            return true;
        }
        auxiliar = auxiliar->getAnterior();
    }
    while(auxiliar != nullptr);
    return false;
}

template <typename T>
int Pilha<T>::getTamanho(){
    return tamanho;
}


template <typename T>
bool Pilha<T>::isEmpty(){
    return tamanho == 0;
}

