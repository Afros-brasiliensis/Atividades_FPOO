#include "Funcionario.h"
#include <iostream>

Funcionario::Funcionario(const std::string& nome, double salario, const Data& data)
    : nome(nome), salario(salario), dataDeAdmissao(data) {
}

std::string Funcionario::getNome() const {
    return nome;
}

double Funcionario::getSalario() const {
    return salario;
}

void Funcionario::aumentarSalario(double percentual) {
    salario += salario * (percentual / 100.0);
}

void Funcionario::imprime() const {
    std::cout << "Nome: " << nome << ", Salario: " << salario << ", Data de Admissao: ";
    dataDeAdmissao.imprime();
    std::cout << std::endl;
}