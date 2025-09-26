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
	//Associação com atleta (1 equipe tem vários atletas)
	Atleta *atletas[TAMANHO_MAXIMO_ATLETAS];
	//Associação com esporte (1 equipe tem 1 esporte)
	Esporte esporte;


public:

	// Construtor padrão
	Equipe();
	//Construtor com parametros
	Equipe(string nome, Esporte esporte);
	// Destrutor
	~Equipe();
	//Adiciona atleta na posiçao pos do vetor de atletas
	void adicionarAtleta(int pos, Atleta* atleta);
	
	//Getters
	string getNome();
	Atleta* getAtletas(int j);
	Esporte getEsporte();
	// Métodos
	void imprime_info();

	
};