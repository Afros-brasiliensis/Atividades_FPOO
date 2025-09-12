#pragma once

#include <iostream>
#include <string>

using namespace std;

class Atleta {
private:
	string nome;
	float idade;

public:

	//Construtor
	Atleta();
	~Atleta();

	//Getters
	string getNome();
	float getIdade();
			
	//Setters

	void setNome(string nome);
	void setIdade(float idade);

	void imprime_info(string nome, float idade);

}
