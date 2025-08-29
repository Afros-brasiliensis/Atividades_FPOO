#pragma once


#include <iostream>
#include <string>

using namespace std;

class Retangulo {
public:
	//Construtor padr�o
	Retangulo();
	//Destrutor
	~Retangulo();

	//M�todos
	//Fun��es que v�o realizar os processos
	void setBase(float base);
	void setAltura(float altura);

	float getBase();
	float getAltura();

	double calculaArea();

private:
	//dados e vari�veis que v�o ser utilizados para realizar os c�lculos
	float base;
	float altura;
	float area;
};