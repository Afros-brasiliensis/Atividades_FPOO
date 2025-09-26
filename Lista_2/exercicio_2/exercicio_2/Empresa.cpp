#include "Empresa.h"
#include <iostream>

Empresa::Empresa(const std::string& nome, const std::string& cnpj)
    : nome(nome), cnpj(cnpj), numDepartamentos(0) {
    for (int i = 0; i < MAX_DEPARTAMENTOS; ++i) {
        departamentos[i] = nullptr;
    }
}

void Empresa::adicionarDepartamento(Departamento* departamento) {
    if (numDepartamentos < MAX_DEPARTAMENTOS) {
        departamentos[numDepartamentos] = departamento;
        numDepartamentos++;
    }
    else {
        std::cout << "Limite de departamentos da empresa " << nome << " atingido." << std::endl;
    }
}

Departamento* Empresa::getDepartamento(const std::string& nome) const {
    for (int i = 0; i < numDepartamentos; ++i) {
        if (departamentos[i] != nullptr && departamentos[i]->getNome() == nome) {
            return departamentos[i];
        }
    }
    return nullptr;
}

void Empresa::transferirFuncionario(Funcionario* funcionario, Departamento* deptoOrigem, Departamento* deptoDestino) {
    if (funcionario != nullptr && deptoOrigem != nullptr && deptoDestino != nullptr) {
        deptoOrigem->removerFuncionario(funcionario);
        deptoDestino->adicionarFuncionario(funcionario);
        std::cout << "Funcionario " << funcionario->getNome() << " transferido de " << deptoOrigem->getNome() << " para " << deptoDestino->getNome() << "." << std::endl;
    }
    else {
        std::cout << "Erro na transferencia. Um dos parametros e invalido." << std::endl;
    }
}

void Empresa::imprime() const {
    std::cout << "Empresa: " << nome << ", CNPJ: " << cnpj << std::endl;
    std::cout << "Departamentos:" << std::endl;
    for (int i = 0; i < numDepartamentos; ++i) {
        if (departamentos[i] != nullptr) {
            departamentos[i]->imprime();
        }
    }
}