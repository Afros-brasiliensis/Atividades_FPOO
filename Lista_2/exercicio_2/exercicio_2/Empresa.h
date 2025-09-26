#pragma once
#include <string>
#include "Departamento.h"

const int MAX_DEPARTAMENTOS = 10;

class Empresa {
private:
    std::string nome;
    std::string cnpj;
    Departamento* departamentos[MAX_DEPARTAMENTOS];
    int numDepartamentos;

public:
    Empresa(const std::string& nome, const std::string& cnpj);
    void adicionarDepartamento(Departamento* departamento);
    Departamento* getDepartamento(const std::string& nome) const;
    void transferirFuncionario(Funcionario* funcionario, Departamento* deptoOrigem, Departamento* deptoDestino);
    void imprime() const;
};