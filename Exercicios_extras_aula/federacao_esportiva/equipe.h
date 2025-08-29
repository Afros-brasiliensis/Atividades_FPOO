#pragma once
#include "atleta.h"
#include "esporte.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Equipe {
private:
	string nome;
	//Associa��o com atleta (1 equipe tem v�rios atletas)
	vector<Atleta> atletas;
	//Associa��o com esporte (1 equipe tem 1 esporte)
	Esporte esporte;

public:

	// Construtor padr�o
	Equipe();
	// Destrutor
	~Equipe();
	//Setters 
	void setNome(string nome);
	void setAtletas(vector<Atleta> atletas);
	void setEsporte(Esporte esporte);
	//Getters
	string getNome();
	vector<Atleta> getAtletas();
	Esporte getEsporte();
	// M�todos
	void imprime_info();

	
};