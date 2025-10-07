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

	telaDeInventario(true);

	numeroCenaAtual = 1; //Comeca na cena 1
	cenasVisitadas.push_back(numeroCenaAtual);

	telaPrincipalDoJogo();

}

void Jogo::carregarJogoSalvo() {
	cout << "\n -- Carregando Jogo Salvo -- \n" << endl;
	if (carregar()) {
		cout << "Jogo carregado com sucesso!" << endl;

		telaDeInventario(false);

		telaPrincipalDoJogo();
	}
	else {
		cout << "Nenhum jogo salvo encontrado." << endl;
	}
}

void Jogo::exibirCreditos() {
	cout << "\n -- Creditos -- \n" << endl;
	cout << "Desenvolvido por:" << endl;
	cout << "Athos Nunes Kolling" << endl;
	cout << "Gustavo Sbardelotto Rezende" << endl;
	cout << "Obrigado por jogar!" << endl;
}

void Jogo::telaDeInventario(bool criandoPersonagem)//implementar criacao de personagem
{
	if (criandoPersonagem) {
		cout << "\n --- Criacao de Personagem ---" << endl;

		int habilidade = 6;
		int energia = 12;
		int sorte = 6;
		int pontosParaDistribuir = 12;

		while (pontosParaDistribuir > 0)
		{
			cout << "Voce tem " << pontosParaDistribuir << "pontos para distribur" << endl;
			cout << "\n Atributos atuais: " << endl;
			cout << "1. HABILIDADE: " << habilidade << " (Max: 12)" << endl;
			cout << "2. ENERGIA:    " << energia << " (Max: 24)" << endl;
			cout << "3. SORTE:      " << sorte << " (Max: 12)" << endl;

			cout << "\n Em qual atributo voce quer adicionar pontos? (Digite 1, 2 ou 3, \n para habilidade, energia ou sorte respectivamente" << endl;
			int escolhaAtributo;
			cin >> escolhaAtributo;

			if (escolhaAtributo < 1 || escolhaAtributo > 3) {
				cout << "Opcao invalida. Tente novamente" << endl;
				continue;
			}
			cout << "Quantos pontos voce deseja adicionar?";
			int pontosAdicionar;
			cin >> pontosAdicionar;


			//Validar os pontos aplicados
			if (pontosAdicionar <= 0) {
				cout << "Voce deve adicionar um numero positivo de pontos." << endl;
				continue;
			}
			if (pontosAdicionar > pontosParaDistribuir) {
				cout << "Voce nao tem pontos suficientes!" << endl;
				continue;
			}
			//Adicao de pontos
			switch (escolhaAtributo) {
			case 1: //Habilidade
				if (habilidade + pontosAdicionar > 12) {
					cout << "Nao e possivel ultrapassar o valor maximo de 12 pontos." << endl;
				}
				else {
					habilidade += pontosAdicionar;
					pontosParaDistribuir -= pontosAdicionar;
				}
				break;

			case 2: //Energia
				if (energia + pontosAdicionar > 24) {
					cout << "Nao e possivel ultrapassar o valor maximo de 24 pontos." << endl;
				}
				else {
					energia += pontosAdicionar;
					pontosParaDistribuir -= pontosAdicionar;
				}
			case 3://Sorte
				if (sorte + pontosAdicionar > 12) {
					cout << "Nao e possivel ultrapassar o valor maximo de 12 pontos." << endl;
				}
				else {
					sorte += pontosAdicionar;
					pontosParaDistribuir -= pontosAdicionar;
				}
				break;
			}
		}


		cout << "\n --- Personagem Criado ---" << endl;

	}

}

	void Jogo::telaPrincipalDoJogo() {
	bool jogoAtivo = true;
	while (jogoAtivo) {}//fazer logica de leitura de cenas, escolhas, etc

	if (cenaAtual == nullptr) {
		cout << "Cena nao carregada. Encerrando o jogo." << endl;
		break;
	}
	salvarProgresso();

	system("cls"); //limpa a tela

	cenaAtual.carregar(numeroCenaAtual);
	cout << "\n" << cenaAtual.getTexto() << "\n" << endl;
	//utilizar a logica de leitura de cena aqui.


	int escolha;
	cout << "Escolha uma opcao: ";
	cin >> escolha;

	processarEscolha(escolha);
	//Condicao para terminar o jogo, se necessario
}

	void Jogo::telaDeCombate(Monstro* inimigo) {
		cout << "\n -- Combate Iniciado! -- \n" << endl;
		cout << "Voce esta enfrentando: " << inimigo->getNome() << endl;

		while(jogador->estaVivo() && inimigo->estaVivo()) {
			cout << "Sua Energia: " << jogador->getEnergia() << " | Energia do " << inimigo->getNome() << ": " << inimigo->getEnergia() << endl;
			cout << "O que voce faz?" << endl;
			cout << "1. Atacar" << endl;
			cout << "2. Usar Sorte" << endl;
			cout << "3. Tentar Fugir" << endl;

			int escolha;
			cin >> escolha;
			switch (escolha) {
			case 1:
				executarCombate();
				break;
			case 2: 
				//logica de usar sorte
			case 3:
				cout << "Voce tentou fugir..." << endl;

		}
}


