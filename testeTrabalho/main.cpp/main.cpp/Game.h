#pragma once
#include "Personagem.h"
#include "Cena.h"
#include <vector>

class Jogo {
public:
	Jogo();
	~Jogo();
	void iniciar(); //inicia o jogo, carregando o personagem e a primeira cena
	

private:

	//Funcoes para cada tela de jogo
	void telaDeAbertura();
	void criarNovoJogo();
	void carregarJogoSalvo();
	void exibirCreditos();
	void telaDeInventario();
	void telaPrincipalDoJogo();
	void telaDeCombate(Monstro* inimigo);

	//Funcoes de logica de jogo
	void processarEscolha(int escolha);
	void executarCombate();

	//Funcoes de persistencia
	void salvarProgresso();
	bool carregar();

	Personagem* jogador; //ponteiro para o personagem do jogador
	Cena cenaAtual; //cena atual do jogo
	int numeroCenaAtual; //numero da cena atual
	vector<int> cenasVisitadas; //para rastrear as cenas visitadas

};