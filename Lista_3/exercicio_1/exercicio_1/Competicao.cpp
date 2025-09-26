#include "Competicao.h"

Competicao::Competicao(const std::string& nome, int dia, int mes, int ano)
    : nome(nome), data(dia, mes, ano) {
}

std::string Competicao::getNome() const {
    return nome;
}

Data Competicao::getData() const {
    return data;
}

void Competicao::imprime_data() const {
    data.imprime_data();
}