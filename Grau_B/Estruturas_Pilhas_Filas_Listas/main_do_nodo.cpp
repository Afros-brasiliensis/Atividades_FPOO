#include "Nodo.h"
#include <iostream>

int main(){
    Nodo<int> nodo1(10);
    Nodo<int> nodo2(20);

    nodo1.setProximo(&nodo2);
    nodo2.setAnterior(&nodo1);

    // Testando os valores
    std::cout << "Valor do nodo1: " << nodo1.getValor() << std::endl;
    std::cout << "Valor do nodo2: " << nodo2.getValor() << std::endl;

    // Testando os ponteiros
    if(nodo1.getProximo() == &nodo2){
        std::cout << "nodo1 aponta para nodo2 corretamente." << std::endl;
    } else {
        std::cout << "Erro: nodo1 nao aponta para nodo2." << std::endl;
    }

    if(nodo2.getAnterior() == &nodo1){
        std::cout << "nodo2 aponta para nodo1 corretamente." << std::endl;
    } else {
        std::cout << "Erro: nodo2 nao aponta para nodo1." << std::endl;
    }

    return 0;  
    
}