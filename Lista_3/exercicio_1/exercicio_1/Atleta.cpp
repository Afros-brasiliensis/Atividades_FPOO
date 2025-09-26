#include "Atleta.h"
#include <iostream>

Atleta::Atleta(const std::string& nome, int idade)
    : nome(nome), idade(idade) {
}

std::string Atleta::getNome() const {
    return nome;
}

int Atleta::getIdade() const {
    return idade;
}

void Atleta::imprime_info() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Idade: " << idade << " anos" << std::endl;
}