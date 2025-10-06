#pragma once

#include <iostream>
#include <string>
using namespace std;

class Calculadora
{

private:
	
	double memoria;
	string cor;

public:

	//Construtor

	Calculadora();

	//Destrutor 
	~Calculadora();

	//Getters 

	double getMemoria();
	string getCor();

	//Setters

	void setMemoria(double memoria);
	void setCor(string cor);

	//Metodos

	void imprime_info();
	void zera_memoria();

}

