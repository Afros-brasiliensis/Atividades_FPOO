#pragma once
#include "Atleta.h"
#include <string>

class Nadador : public Atleta {
private:
    std::string categoria;

public:
    Nadador(const std::string& nome, int idade, const std::string& categoria);

    std::string getCategoria() const;

    void imprime_info() const override;
};