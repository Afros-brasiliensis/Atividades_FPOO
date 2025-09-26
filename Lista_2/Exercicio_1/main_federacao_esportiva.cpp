#include "equipe.h"
#include "esporte.h"
#include "atleta.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

	Esporte volei("Volei", "Coletivo");
	Equipe time("SESI-SP", volei);

	Atleta a1("Afros", 25);
	Atleta a2("Murilo", 30);
	Atleta a3("Lucarelli", 28);
	Atleta a4("Lucao", 26);

	time.adicionarAtleta(0, &a1);
	time.adicionarAtleta(1, &a2);
	time.adicionarAtleta(2, &a3);
	time.adicionarAtleta(3, &a4);

	time.imprime_info();

	time.getAtletas(1)->setNome("Murilo Endres");
	cout << "\nDepois da alteração:\n" << endl;
	time.imprime_info();

	return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
