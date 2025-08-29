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
	//Associação com atleta (1 equipe tem vários atletas)
	vector<Atleta> atletas;
	//Associação com esporte (1 equipe tem 1 esporte)
	Esporte esporte;

public:

	// Construtor padrão
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
	// Métodos
	void imprime_info();

	
};