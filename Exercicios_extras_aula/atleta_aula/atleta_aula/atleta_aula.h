#pragma once

#include <iostream>
#include <string>

using namespace std;

class Atleta {
private: 
	//Atributos
	string nome;
	float idade;

public:
	//Construtor
	Atleta();
	//Destrutor
	~Atleta();

	//Getters
	
	string getNome();
	float getIdade();

	//Setters

	void setNome(string nome);
	void setIdade(float  idade);

	void imprime_info(string nome, float idade);

};