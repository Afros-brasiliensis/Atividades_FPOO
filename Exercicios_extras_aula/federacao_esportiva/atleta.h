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
	// Construtor padrão
	Atleta();
	// Destrutor
	~Atleta();
	//Setters 
	void setNome(string nome);
	void setIdade(int idade);
	//Getters
	string getNome();
	int getIdade();
	// Métodos
	void imprime_info();

}