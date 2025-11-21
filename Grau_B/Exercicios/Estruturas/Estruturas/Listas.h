#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;

// ================================================================
// LISTA DUPLAMENTE ENCADEADA
// front()  -> primeiro elemento     (inicio)
// back()   -> último elemento       (fim)
//
// Cada Nodo tem:
//   valor, ponteiro para ANTERIOR, ponteiro para PROXIMO
//
// A lista mantém dois ponteiros principais:
//   - inicio -> aponta para o PRIMEIRO nodo
//   - fim    -> aponta para o ÚLTIMO nodo
// ================================================================

template <typename T>
class Lista {
private:
    Nodo<T>* inicio;   // ponteiro para o primeiro nodo
    Nodo<T>* fim;      // ponteiro para o último nodo
    int tamanho;       // quantidade de elementos

public:
    Lista();
    ~Lista();

    void push_front(const T& object);  // insere NO INÍCIO
    void push_At(int index, const T& value);
    void push_back(const T& object);   // insere NO FIM

    void pop_front();                  // remove DO INÍCIO
	void pop_At(int index);
    void pop_back();                   // remove DO FIM

    T& front();   
    T& at(int index);
    T& back();                         // retorna valor do fim

    bool isEmpty() const;
    int getTamanho() const;
};

// ================================================================
// CONSTRUTOR
// Começa com lista vazia: sem início, sem fim, tamanho 0
// ================================================================

template <typename T>
Lista<T>::Lista() {
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
}

// ================================================================
// DESTRUTOR
// Remove sempre do início até esvaziar
// ================================================================

template <typename T>
Lista<T>::~Lista() {
    while (!isEmpty()) {
        pop_front();
    }
}

// ================================================================
// PUSH_FRONT — INSERIR NO INÍCIO
//
// CASO 1 — Lista vazia:
//   inicio = novo
//   fim = novo
//
// CASO 2 — Lista com elementos:
//   novo.proximo = inicio
//   novo.anterior = nullptr
//   inicio.anterior = novo
//   inicio = novo
//
// EXEMPLO:
//
// Antes: inicio ? [A] ? [B] ? [C] ? fim
// push_front(X)
// Depois: inicio ? [X] ? [A] ? [B] ? [C] ? fim
// ================================================================

template <typename T>
void Lista<T>::push_front(const T& object) {
    Nodo<T>* novoNodo = new Nodo<T>(object);

    if (isEmpty()) {
        // Primeiro elemento da lista
        this->inicio = novoNodo;
        this->fim = novoNodo;
    }
    else {
        // novo será o primeiro nodo
        novoNodo->setAnterior(nullptr);     // não tem ninguém antes
        novoNodo->setProximo(inicio);       // aponta para o antigo início

        inicio->setAnterior(novoNodo);      // antigo início aponta de volta
        inicio = novoNodo;                  // atualiza o ponteiro inicio
    }

    tamanho++;
}

// ================================================================
// PUSH_BACK — INSERIR NO FIM
//
// CASO 1 — Lista vazia:
//   inicio = novo
//   fim = novo
//
// CASO 2 — Lista com elementos:
//   novo.anterior = fim
//   novo.proximo = nullptr
//   fim.proximo = novo
//   fim = novo
//
// EXEMPLO:
//
// Antes: inicio ? [A] ? [B] ? [C] ? fim
// push_back(X)
// Depois: inicio ? [A] ? [B] ? [C] ? [X] ? fim
// ================================================================

template <typename T>
void Lista<T>::push_back(const T& object) {
    Nodo<T>* novoNodo = new Nodo<T>(object);

    if (isEmpty()) {
        this->inicio = novoNodo;
        this->fim = novoNodo;
    }
    else {
        novoNodo->setAnterior(fim);     // vem depois do antigo fim
        novoNodo->setProximo(nullptr);  // é o novo último elemento

        fim->setProximo(novoNodo);      // antigo fim aponta para o novo
        fim = novoNodo;                 // atualiza o ponteiro fim
    }

    tamanho++;
}

// ================================================================
// POP_FRONT — REMOVER DO INÍCIO
//
// CASO 1 — Lista vazia: nada a remover
//
// CASO 2 — Lista com elementos:
//   aux = inicio
//   inicio = inicio.proximo
//
//   se inicio existe:
//        inicio.anterior = nullptr
//   senão:
//        fim = nullptr   // lista ficou vazia
// ================================================================

template <typename T>
void Lista<T>::pop_front() {
    if (isEmpty()) {
        cout << "Lista vazia, nao eh possivel remover esse elemento\n";
        return;
    }

    Nodo<T>* aux = inicio;
    inicio = inicio->getProximo(); // desloca o início

    if (inicio != nullptr) {
        inicio->setAnterior(nullptr);
    } else {
        fim = nullptr; // lista virou vazia
    }

    delete aux;
    tamanho--;
}

// ================================================================
// POP_BACK — REMOVER DO FIM
//
// CASO 1 — Lista vazia
//
// CASO 2 — Lista com elementos:
//   aux = fim
//   fim = fim.anterior
//
//   se fim existe:
//        fim.proximo = nullptr
//   senão:
//        inicio = nullptr  // lista ficou vazia
// ================================================================

template <typename T>
void Lista<T>::pop_back() {
    if (isEmpty()) {
        cout << "Lista vazia, nao eh possivel remover esse elemento\n";
        return;
    }

    Nodo<T>* aux = fim;
    fim = fim->getAnterior(); // move o fim para trás

    if (fim != nullptr) {
        fim->setProximo(nullptr);
    } else {
        inicio = nullptr; // ficou vazia
    }

    delete aux;
    tamanho--;
}

// ================================================================
// FRONT — retorna o valor do PRIMEIRO nodo
// ================================================================

template <typename T>
T& Lista<T>::front() {
    if (isEmpty()) {
        cout << "Lista vazia.\n";
        static T vazio = T();
        return vazio;
    }
    return inicio->getValor();
}

// ================================================================
// BACK — retorna o valor do ÚLTIMO nodo
// ================================================================

template <typename T>
T& Lista<T>::back() {
    if (isEmpty()) {
        cout << "Lista vazia.\n";
        static T vazio = T();
        return vazio;
    }
    return fim->getValor();
}

// ================================================================
// UTILS
// ================================================================

template <typename T>
bool Lista<T>::isEmpty() const {
    return tamanho == 0;
}

template <typename T>
int Lista<T>::getTamanho() const {
    return tamanho;
}

// ==================== ACESSO POR ÍNDICE ====================

template <typename T>
T& Lista<T>::at(int index) {
    if (index < 0 || index >= tamanho) {
        cout << "Indice fora do intervalo em Lista::at\n";
        static T vazio = T();
        return vazio;
    }

    Nodo<T>* atual = inicio;
    int i = 0;
    while (i < index && atual != nullptr) {
        atual = atual->getProximo();
        i++;
    }

    return atual->getValor();
}

// ==================== INSERIR EM POSIÇÃO ====================

template <typename T>
void Lista<T>::push_At(int index, const T& value) {
    if (index <= 0) {
        // insere no início
        push_front(value);
    }
    else if (index >= tamanho) {
        // insere no fim
        push_back(value);
    }
    else {
        // insere no meio
        Nodo<T>* atual = inicio;
        int i = 0;
        while (i < index && atual != nullptr) {
            atual = atual->getProximo();
            i++;
        }

        // atual é o nodo que está NA posição index
        Nodo<T>* anterior = atual->getAnterior();
        Nodo<T>* novo = new Nodo<T>(value);

        novo->setAnterior(anterior);
        novo->setProximo(atual);

        anterior->setProximo(novo);
        atual->setAnterior(novo);

        tamanho++;
    }
}

// ==================== REMOVER EM POSIÇÃO ====================

template <typename T>
void Lista<T>::pop_At(int index) {
    if (index < 0 || index >= tamanho) {
        cout << "Indice fora do intervalo em Lista::removeAt\n";
        return;
    }

    if (index == 0) {
        pop_front();
    }
    else if (index == tamanho - 1) {
        pop_back();
    }
    else {
        Nodo<T>* atual = inicio;
        int i = 0;
        while (i < index && atual != nullptr) {
            atual = atual->getProximo();
            i++;
        }

        Nodo<T>* anterior = atual->getAnterior();
        Nodo<T>* proximo = atual->getProximo();

        anterior->setProximo(proximo);
        proximo->setAnterior(anterior);

        delete atual;
        tamanho--;
    }
}
