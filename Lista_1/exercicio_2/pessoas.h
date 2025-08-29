#pragma once

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
public: 
	//Construtor padrão
	Pessoa();
	//Destrutor
	~Pessoa();

	//Setters
	void setNome(string nome);
	void setIdade(float idade);
	void setAltura(float altura);
	void setQntIrmaos(float qnt_irmaos);
	void setEndereco(string endereco);

	//Getters
	
	string getNome();
	float getIdade();
	float getAltura();
	float getQntIrmaos();
	string getEndereco();

	//Métodos
	void imprime_info();
	bool is_filho_unico();

private: 

	string nome;
	float idade;
	float altura;
	float qnt_irmaos;
	string endereco;

};