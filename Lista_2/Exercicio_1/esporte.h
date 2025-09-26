#pragma once

#include <string>
#include <iostream>

using namespace std;

class Esporte {
private:

	// Atributos
	string nome;
	string modalidade;

public:

	// Construtor padr�o
	Esporte();
	//Construtor com parametros
	Esporte(string nome, string modalidade);
	// Destrutor
	~Esporte();

	//Getters
	string getNome();
	string getModalidade();

};