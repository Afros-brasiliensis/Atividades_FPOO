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

        void push_front(const T& object);
        void push_back(const T& object);

        void pop_front();
        void pop_back();

        T& front();
        T& back();

        bool isEmpty() const;
        T getTamanho() const;
};

template <typename T>
Lista<T>::Lista(){
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
}

template <typename T>
Lista<T>::~Lista(){
    while(!isEmpty()){
        pop_front();
    }
}

template <typename T>
Lista<T>::push_front(const T& object){
    Nodo<T>* novoNodo = new Nodo<T>(valor);
    if(isEmpty()){
        this->inicio = novoNodo;
        this->fim = novoNodo;
    }
    else{
        novoNodo->setProixmo(inicio);
        inicio->setAnterior(novoNodo);
        inicio = novoNodo;
    }

    tamanho++;
}



