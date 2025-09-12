// Exercicio_atleta_aula.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include "atleta_aula.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

	Atleta atleta;

	//Entrada de dados
	string nome;
	float idade;

	cout << "Digite o nome do atleta: ";
	getline(cin, nome);
	cout << "Digite a idade do atleta: ";
	cin >> idade;
	//Setando os valores
	atleta.setNome(nome);
	atleta.setIdade(idade);

	cout << endl;

	cout << "---------------------------------" << endl;

	cout << "Informacoes do atleta:" << endl;
	atleta.imprime_info(atleta.getNome(), atleta.getIdade());


	
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
