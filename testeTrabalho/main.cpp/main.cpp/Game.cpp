#include "Game.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

Jogo::Jogo() : jogador(nullptr), numeroCenaAtual(0) {
	// Inicializa o gerador de números aleatórios
	srand(time(nullptr)) ;
}

Jogo::~Jogo() {
	delete jogador;
}

void Jogo::iniciar() {
	//Tenta carregar um jogo salvo
	if (!carregar()) {
		//Se nao conseguir, mostra a tela de abertura
		telaDeAbertura();
	}
}

void Jogo::telaDeAbertura() {
	int escolha = 0;
	while (escolha != 4) {
		cout << "==============================" << endl;
		cout << "      AVENTURA FANTASTICA     " << endl;
		cout << "==============================" << endl;
		cout << "1. Novo Jogo" << endl;
		cout << "2. Carregar Jogo Salvo" << endl;
		cout << "3. Creditos" << endl;
		cout << "4. Sair" << endl;
		cout << "Escolha uma opcao: ";
		cin >> escolha;
		switch (escolha) {
		case 1:
			criarNovoJogo();
			telaPrincipalDoJogo();
			break;
		case 2:
			if (carregar()) {
				telaPrincipalDoJogo();
			}
			else {
				cout << "Nenhum jogo salvo encontrado." << endl;
			}
			break;
		case 3:
			exibirCreditos();
			break;
		case 4:
			cout << "Saindo do jogo. Ate a proxima!" << endl;
			break;
		default:
			cout << "Opcao invalida. Tente novamente." << endl;
		}
	}
}	

void Jogo::criarNovoJogo() {
	cout << "\n -- Criando um Novo Jogo -- \n" << endl;
	jogador = new Personagem();

	telaDeInventario();

	numeroCenaAtual = 1; //Comeca na cena 1
	cenasVisitadas.push_back(numeroCenaAtual);

	telaPrincipalDoJogo();

}