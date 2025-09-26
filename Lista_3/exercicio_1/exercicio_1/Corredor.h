#pragma once
#include "Atleta.h"
#include "Competicao.h"

class Corredor : public Atleta {
private:
    double peso;
    Competicao competicao;

public:
    Corredor(const std::string& nome, int idade, double peso, const std::string& nomeCompeticao, int dia, int mes, int ano);

    double getPeso() const;
    Competicao getCompeticao() const;

    void imprime_competicao() const;

    void imprime_info() const override;
};