#pragma once


#include <iostream>
#include <string>

using namespace std;

class Retangulo {
public:
	//Construtor padrão
	Retangulo();
	//Destrutor
	~Retangulo();

	//Métodos
	//Funções que vão realizar os processos
	void setBase(float base);
	void setAltura(float altura);

	float getBase();
	float getAltura();

	double calculaArea();

private:
	//dados e variáveis que vão ser utilizados para realizar os cálculos
	float base;
	float altura;
	float area;
};