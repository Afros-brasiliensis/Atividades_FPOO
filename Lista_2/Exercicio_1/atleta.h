#pragma once

#include <string>
#include <iostream>

using namespace std;

class Atleta {
private:
	string nome;
	int idade;

public:
	// Construtor padrão
	Atleta();
	//Construtor com parâmetros
	Atleta(string nome, int idade);
	// Destrutor
	~Atleta();
	//Setters 
	void setNome(string nome);
	//Getters
	string getNome();
	int getIdade();
	// Métodos
	void imprime_info();

};