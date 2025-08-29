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

	// Construtor padrão
	Esporte();
	// Destrutor
	~Esporte();

	//Setters 
	void setNome(string nome);
	void setModalidades(string modalidades);

	//Getters
	string getNome();
	string getModalidades();
	
	// Métodos
	void imprime_info();

