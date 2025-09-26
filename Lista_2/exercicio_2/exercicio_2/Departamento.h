#pragma once
#include <string>
#include "Funcionario.h"

const int MAX_FUNCIONARIOS = 100;

class Departamento {
private:
    std::string nome;
    Funcionario* funcionarios[MAX_FUNCIONARIOS];
    int numFuncionarios;

public:
    Departamento(const std::string& nome);
    std::string getNome() const;
    void adicionarFuncionario(Funcionario* funcionario);
    void darAumento(double percentual);
    void removerFuncionario(Funcionario* funcionario);
    Funcionario* getFuncionario(const std::string& nome) const;
    void imprime() const;
};