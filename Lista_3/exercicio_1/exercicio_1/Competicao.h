#pragma once
#include "Data.h"
#include <string>
#include <iostream>

class Competicao {
private:
    std::string nome;
    Data data;

public:
    Competicao(const std::string& nome, int dia, int mes, int ano);

    std::string getNome() const;
    Data getData() const;

    void imprime_data() const;
};