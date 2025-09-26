#include "Departamento.h"
#include <iostream>

Departamento::Departamento(const std::string& nome) : nome(nome), numFuncionarios(0) {
    for (int i = 0; i < MAX_FUNCIONARIOS; ++i) {
        funcionarios[i] = nullptr;
    }
}

std::string Departamento::getNome() const {
    return nome;
}

void Departamento::adicionarFuncionario(Funcionario* funcionario) {
    if (numFuncionarios < MAX_FUNCIONARIOS) {
        funcionarios[numFuncionarios] = funcionario;
        numFuncionarios++;
    }
    else {
        std::cout << "Limite de funcionarios no departamento " << nome << " atingido." << std::endl;
    }
}

void Departamento::darAumento(double percentual) {
    std::cout << "Dando aumento de " << percentual << "% aos funcionarios do departamento " << nome << ":" << std::endl;
    for (int i = 0; i < numFuncionarios; ++i) {
        if (funcionarios[i] != nullptr) {
            funcionarios[i]->aumentarSalario(percentual);
        }
    }
}

void Departamento::removerFuncionario(Funcionario* funcionario) {
    for (int i = 0; i < numFuncionarios; ++i) {
        if (funcionarios[i] == funcionario) {
            // Move o último funcionário para a posição do removido
            funcionarios[i] = funcionarios[numFuncionarios - 1];
            funcionarios[numFuncionarios - 1] = nullptr;
            numFuncionarios--;
            std::cout << "Funcionario " << funcionario->getNome() << " removido do departamento " << nome << "." << std::endl;
            return;
        }
    }
    std::cout << "Funcionario " << funcionario->getNome() << " nao encontrado no departamento " << nome << "." << std::endl;
}

Funcionario* Departamento::getFuncionario(const std::string& nome) const {
    for (int i = 0; i < numFuncionarios; ++i) {
        if (funcionarios[i] != nullptr && funcionarios[i]->getNome() == nome) {
            return funcionarios[i];
        }
    }
    return nullptr;
}

void Departamento::imprime() const {
    std::cout << "Departamento: " << nome << " (" << numFuncionarios << " funcionarios)" << std::endl;
    for (int i = 0; i < numFuncionarios; ++i) {
        if (funcionarios[i] != nullptr) {
            funcionarios[i]->imprime();
        }
    }
}