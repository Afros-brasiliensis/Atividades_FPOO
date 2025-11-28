#include "Nodo.h"

template <typename T>
class Lista {
private:
    Nodo<T>* inicio;
    Nodo<T>* fim;
    T tamanho;

public:
    Lista();
    ~Lista();

    void push_front(const T& object);  // Adiciona no início
    void push_back(const T& object);   // Adiciona no final

    void pop_front();  // Remove do início
    void pop_back();   // Remove do final

    T& front();   // Retorna o elemento do início
    T& back();    // Retorna o elemento do final

    bool isEmpty() const;  // Verifica se a lista está vazia
    T getTamanho() const;  // Retorna o tamanho da lista
};

template <typename T>
Lista<T>::Lista() {
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
}

template <typename T>
Lista<T>::~Lista() {
    while (!isEmpty()) {
        pop_front();
    }
}

template <typename T>
void Lista<T>::push_front(const T& object) {
    Nodo<T>* novoNodo = new Nodo<T>(object);
    if (isEmpty()) {
        this->inicio = novoNodo;
        this->fim = novoNodo;
    }
    else {
        novoNodo->setProximo(inicio);  // Aponta o novo nó para o início da lista
        inicio->setAnterior(novoNodo);  // Atualiza o início para apontar de volta para o novo nó
        inicio = novoNodo;  // Muda o início para o novo nó
    }

    tamanho++;
}

template <typename T>
void Lista<T>::push_back(const T& object) {
    Nodo<T>* novoNodo = new Nodo<T>(object);
    if (isEmpty()) {
        this->inicio = novoNodo;
        this->fim = novoNodo;
    }
    else {
        fim->setProximo(novoNodo);  // O fim atual aponta para o novo nó
        novoNodo->setAnterior(fim);  // O novo nó aponta de volta para o fim
        fim = novoNodo;  // Atualiza o fim para o novo nó
    }

    tamanho++;
}

template <typename T>
void Lista<T>::pop_front() {
    if (isEmpty()) {
        std::cout << "Lista vazia, não é possível remover o elemento." << std::endl;
    }
    else {
        Nodo<T>* auxiliar = inicio;
        inicio = inicio->getProximo();
        if (inicio != nullptr) {
            inicio->setAnterior(nullptr);
        }
        else {
            fim = nullptr;  // Se a lista ficou vazia, ajusta o fim também
        }

        delete auxiliar;
        tamanho--;
    }
}

template <typename T>
void Lista<T>::pop_back() {
    if (isEmpty()) {
        std::cout << "Lista vazia, não é possível remover o elemento." << std::endl;
    }
    else {
        Nodo<T>* auxiliar = fim;
        fim = fim->getAnterior();
        if (fim != nullptr) {
            fim->setProximo(nullptr);
        }
        else {
            inicio = nullptr;  // Se a lista ficou vazia, ajusta o início também
        }

        delete auxiliar;
        tamanho--;
    }
}

template <typename T>
T& Lista<T>::front() {
    if (isEmpty()) {
        throw std::runtime_error("Lista vazia.");
    }
    return inicio->getValor();
}

template <typename T>
T& Lista<T>::back() {
    if (isEmpty()) {
        throw std::runtime_error("Lista vazia.");
    }
    return fim->getValor();
}

template <typename T>
bool Lista<T>::isEmpty() const {
    return tamanho == 0;
}

template <typename T>
T Lista<T>::getTamanho() const {
    return tamanho;
}
