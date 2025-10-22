// main.cpp
#include <iostream>
#include "Loja.h"
#include "Smartphone.h"
#include "Laptop.h"
#include "Tablet.h"

// Certifique-se que seus produtos têm os getters (getNome, getPreco, getCodigoDeBarras)
// e setters (setNome, setPreco, etc) e o 'imprimeProduto()'

using namespace std;

int main() {
    cout << "--- INICIO DO TESTE COMPLETO ---" << endl;

    // 1. Cria a Loja (usa o construtor Loja(string))
    Loja minhaLoja("Loja de Teste");

    // 2. Teste: Adicionar Produtos (Item 3)
    cout << "\n--- Teste: Adicionar Produtos ---" << endl;
    Produto* p1 = new Smartphone("Galaxy S25", 5000.0, 111, "Ultra", 512);
    Produto* p2 = new Laptop("Inspiron 15", 3500.0, 222, "Dell", 15.6);
    Produto* p3 = new Tablet("iPad Air", 6000.0, 333, "Apple", 10.0);
    Produto* p4 = new Smartphone("Produto Duplicado", 100.0, 111, "Erro", 64); // Cód. duplicado

    minhaLoja.adicionarProduto(p1);
    minhaLoja.adicionarProduto(p2);
    minhaLoja.adicionarProduto(p3);
    minhaLoja.adicionarProduto(p4); // Deve falhar e mostrar "Produto ja existe"

    // 3. Teste: Listar Informações (Item 2)
    cout << "\n--- Teste: Listar Informacoes (infoLoja) ---" << endl;
    minhaLoja.infoLoja(); // Deve listar 3 produtos

    // 4. Teste: Buscar Produto (Item 1)
    cout << "\n--- Teste: Buscar Produto ---" << endl;
    minhaLoja.buscarProduto(222); // Deve encontrar o Laptop
    minhaLoja.buscarProduto(999); // Deve dar "nao encontrado"

    // 5. Teste: Calcular Valor Total (Item 6)
    cout << "\n--- Teste: Calcular Valor Total do Estoque ---" << endl;
    minhaLoja.calcularValorEstoque(); // Deve imprimir o total (5000 + 3500 + 6000 = 14500)

    // 6. Teste: Aplicar Desconto (Item 7)
    cout << "\n--- Teste: Aplicar Desconto (10% no produto 111) ---" << endl;
    minhaLoja.aplicarDesconto(111, 10.0);
    minhaLoja.buscarProduto(111); // Deve mostrar o Galaxy S25 com preço 4500.0

    // 7. Teste: Verificar Estoque (Item 8)
    cout << "\n--- Teste: Verificar Estoque ---" << endl;
    minhaLoja.verificaEstoque(333); // Deve dizer "Quantidade disponivel: 1"
    minhaLoja.verificaEstoque(999); // Deve dizer "Produto esgotado"

    // 8. Teste: Listar Acima de Valor (Item 10)
    cout << "\n--- Teste: Listar Acima de 4000 ---" << endl;
    minhaLoja.listarProdutosAcimaDeValor(4000.0); // Deve listar o S25 (4500) e o iPad (6000)

    // 9. Teste: Simular Venda (Item 9)
    cout << "\n--- Teste: Simular Venda (vendendo o iPad '333') ---" << endl;
    minhaLoja.simularVenda(333);
    minhaLoja.simularVenda(999); // Deve dar erro de "nao disponivel"

    // 10. Teste: Editar Produto (Item 5)
    cout << "\n--- Teste: Editar Produto (Galaxy S25 '111') ---" << endl;
    minhaLoja.editarProduto(111); // Vai pedir os dados no console
    minhaLoja.buscarProduto(111); // Mostra os dados atualizados

    // 11. Teste Final: Listar tudo
    cout << "\n--- Teste Final: Estado da Loja ---" << endl;
    minhaLoja.infoLoja(); // Deve mostrar os produtos restantes após as operações

    cout << "\n--- FIM DO TESTE COMPLETO ---" << endl;
    return 0;
}