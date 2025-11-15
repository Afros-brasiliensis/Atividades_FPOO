#include <iostream>
#include "Empresa.h"
#include "FuncionarioCaixa.h"
#include "Calculadora.h"

using namespace std;

int main() {
    // Calculadoras (uma pra cada funcionário)
    Calculadora<int> calc1;  // pode setar cor/memória se quiser
    Calculadora<int> calc2;

    // Funcionário 1
    FuncionarioCaixa<int> f1;
    f1.setNome("Joao");
    f1.setEndereco("Rua A, 123");
    f1.setCalculadora(calc1);

    // Funcionário 2
    FuncionarioCaixa<int> f2;
    f2.setNome("Maria");
    f2.setEndereco("Rua B, 456");
    f2.setCalculadora(calc2);

    // Operações com a calculadora do primeiro funcionário: 2+2, 5-4, 2x3
    cout << "[Calc do " << f1.getNome() << "] 2 + 2 = " << f1.somarFC(2, 2) << '\n';
    cout << "[Calc do " << f1.getNome() << "] 5 - 4 = " << f1.subtrairFC(5, 4) << '\n';
    cout << "[Calc do " << f1.getNome() << "] 2 x 3 = " << f1.multiplicarFC(2, 3) << '\n';

    // Operações com a calculadora do segundo funcionário: 6/3, 7+2, 8x3
    cout << "[Calc do " << f2.getNome() << "] 6 / 3 = " << f2.dividirFC(6, 3) << '\n';
    cout << "[Calc do " << f2.getNome() << "] 7 + 2 = " << f2.somarFC(7, 2) << '\n';
    cout << "[Calc do " << f2.getNome() << "] 8 x 3 = " << f2.multiplicarFC(8, 3) << '\n';

    // Empresa com 2 funcionários
    Empresa<int> empresa("Supermercado Goats", 2);
    empresa.setFuncionarioCaixa(0, f1);
    empresa.setFuncionarioCaixa(1, f2);

    // Imprime dados da empresa
    cout << "\n=== DADOS DA EMPRESA ===\n";
    empresa.imprimirDadosEmpresa();

    return 0;
}
