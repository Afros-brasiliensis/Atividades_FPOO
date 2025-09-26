#pragma once
#include "atleta.h"
#include "esporte.h"
#include <string>
#include <iostream>

using namespace std;

#define TAMANHO_MAXIMO_ATLETAS 10

class Equipe {
private:
	string nome;
	//Associa��o com atleta (1 equipe tem v�rios atletas)
	Atleta *atletas[TAMANHO_MAXIMO_ATLETAS];
	//Associa��o com esporte (1 equipe tem 1 esporte)
	Esporte esporte;


public:

	// Construtor padr�o
	Equipe();
	//Construtor com parametros
	Equipe(string nome, Esporte esporte);
	// Destrutor
	~Equipe();
	//Adiciona atleta na posi�ao pos do vetor de atletas
	void adicionarAtleta(int pos, Atleta* atleta);
	
	//Getters
	string getNome();
	Atleta* getAtletas(int j);
	Esporte getEsporte();
	// M�todos
	void imprime_info();

	
};