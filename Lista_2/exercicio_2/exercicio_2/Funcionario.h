#pragma once
#include <string>
#include "Data.h"

class Funcionario {
private:
    std::string nome;
    double salario;
    Data dataDeAdmissao;

public:
    Funcionario(const std::string& nome, double salario, const Data& data);
    std::string getNome() const;
    double getSalario() const;
    void aumentarSalario(double percentual);
    void imprime() const;
};