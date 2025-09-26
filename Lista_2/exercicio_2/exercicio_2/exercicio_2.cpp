#include <iostream>
#include "Empresa.h"

int main() {
    // 1. Criar uma empresa
    Empresa minhaEmpresa("TechCorp S.A.", "12.345.678/0001-90");

    // 2. Adicionar departamentos
    Departamento* deptoVendas = new Departamento("Vendas");
    Departamento* deptoTI = new Departamento("TI");
    minhaEmpresa.adicionarDepartamento(deptoVendas);
    minhaEmpresa.adicionarDepartamento(deptoTI);

    // 3. Adicionar funcionários aos departamentos
    Funcionario* f1 = new Funcionario("Alice", 3000.0, Data(10, 1, 2022));
    Funcionario* f2 = new Funcionario("Bob", 3500.0, Data(15, 2, 2021));
    Funcionario* f3 = new Funcionario("Carlos", 5000.0, Data(20, 3, 2023));

    deptoVendas->adicionarFuncionario(f1);
    deptoVendas->adicionarFuncionario(f2);
    deptoTI->adicionarFuncionario(f3);

    std::cout << "--- Estado Inicial da Empresa ---" << std::endl;
    minhaEmpresa.imprime();
    std::cout << std::endl;

    // 4. Dar aumento a todos os funcionários de um departamento
    deptoVendas->darAumento(10);
    std::cout << std::endl;
    std::cout << "--- Apos Aumento no Departamento de Vendas ---" << std::endl;
    minhaEmpresa.imprime();
    std::cout << std::endl;

    // 5. Transferir um funcionário de um departamento para outro
    minhaEmpresa.transferirFuncionario(f2, deptoVendas, deptoTI);
    std::cout << std::endl;
    std::cout << "--- Apos Transferencia de Funcionario ---" << std::endl;
    minhaEmpresa.imprime();
    std::cout << std::endl;

    // Limpeza de memória
    delete f1;
    delete f2;
    delete f3;
    delete deptoVendas;
    delete deptoTI;

    return 0;
}