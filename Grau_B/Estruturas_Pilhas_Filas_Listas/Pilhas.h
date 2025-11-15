#include "Nodo.h"

template <typename T>

class Pilha{
    private:
        Nodo<T>* topo;
        Nodo<T>* base;
        int tamanho;

    public: 
        Pilha();//Construtor
        ~Pilha();//Destrutor

        void push(T object);//Adiciona um elemento no topo da pilha
        T pop();//Remove o elemento do topo da pilha
        T top();//Retorna o elemento do topo da pilha sem remover
        bool Find();//Verifica se a pilha esta vazia
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
void Pilha<T>::push()<T object>{
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

}