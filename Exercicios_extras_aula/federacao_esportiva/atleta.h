#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Atleta {
private:
	string nome;
	int idade;

public:
	// Construtor padr�o
	Atleta();
	// Destrutor
	~Atleta();
	//Setters 
	void setNome(string nome);
	void setIdade(int idade);
	//Getters
	string getNome();
	int getIdade();
	// M�todos
	void imprime_info();

}