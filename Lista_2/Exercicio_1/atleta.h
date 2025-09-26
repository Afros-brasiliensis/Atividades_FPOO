#pragma once

#include <string>
#include <iostream>

using namespace std;

class Atleta {
private:
	string nome;
	int idade;

public:
	// Construtor padr�o
	Atleta();
	//Construtor com par�metros
	Atleta(string nome, int idade);
	// Destrutor
	~Atleta();
	//Setters 
	void setNome(string nome);
	//Getters
	string getNome();
	int getIdade();
	// M�todos
	void imprime_info();

};