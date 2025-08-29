#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Esporte {
private:

	// Atributos
	string nome;
	string modalidades;

public:

	// Construtor padr�o
	Esporte();
	// Destrutor
	~Esporte();

	//Setters 
	void setNome(string nome);
	void setModalidades(string modalidades);

	//Getters
	string getNome();
	string getModalidades();
	
	// M�todos
	void imprime_info();

