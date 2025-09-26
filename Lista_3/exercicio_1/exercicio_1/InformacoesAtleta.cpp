#include "InformacoesAtleta.h"
#include <iostream>

void InformacoesAtleta::imprime_exclusivos_atleta(Atleta* a) {
    if (Nadador* n = dynamic_cast<Nadador*>(a)) {
        std::cout << "É um nadador, e sua categoria é: " << n->getCategoria() << std::endl;
    }
    else if (Corredor* c = dynamic_cast<Corredor*>(a)) {
        std::cout << "É um corredor, e o peso deste corredor é: " << c->getPeso() << std::endl;
    }
}

void InformacoesAtleta::imprime_informacoes_atleta(Atleta* a) {
    if (a) {
        a->imprime_info();
    }
    else {
        std::cout << "Ponteiro para atleta inválido." << std::endl;
    }
}