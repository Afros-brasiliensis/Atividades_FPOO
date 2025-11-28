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
    Nodo<T>* getInicio() const;
};

template <typename T>
Fila<T>::Fila(){
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
}

template <typename T>
Fila<T>::~Fila(){
    while(!isEmpty()){
        pop();
    }
}

template <typename T>
void Fila<T>::push(const T& object){
    Nodo<T>* novoNodo = new Nodo<T>(object);
    if(isEmpty()){
        this->inicio = novoNodo;
        this->fim = novoNodo;
    }
    else{
        novoNodo->setAnterior(fim);
        fim->setProximo(novoNodo);
        fim = novoNodo;
    }
    tamanho++;
}

template <typename T>
void Fila<T>::pop(){
    if(isEmpty()){
        cout << "Fila vazia, nao eh possivel remover esse elemento" << endl;
    }
    else{
        Nodo<T>* auxiliar = inicio;
        inicio = inicio->getProximo();
        if(inicio != nullptr){
            inicio->setAnterior(nullptr);
        }else{
            fim = nullptr;
        }
        
        delete auxiliar;
        tamanho--;
    }
}

template <typename T>
const T& Fila<T>::front() const{
    if(isEmpty()){
        cout << "Fila vazia." << endl;
        static T empty = T();  // Static ensures it persists
        return empty;
    }
    else{
        return inicio->getValor();
    }
}

template <typename T>
const T& Fila<T>::back() const {
    if(isEmpty()){
        cout << "Fila vazia." << endl;
        static T empty = T();  // Static ensures it persists
        return empty;
    }
    else{
        return fim->getValor();
    }
}

template <typename T>
bool Fila<T>::isEmpty() const{
    return tamanho == 0;
}

template <typename T>
int Fila<T>::getTamanho() const{
    return tamanho;
}

template <typename T>
Nodo<T>* Fila<T>::getInicio() const {
    return inicio;
}