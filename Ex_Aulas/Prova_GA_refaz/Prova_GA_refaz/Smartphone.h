#pragma once
#include "Produto.h"

class Smartphone : public Produto {

private:
	//Atributos
	string modelo;
	int armazenamento; // em GB

public:
	//Construtores e Destrutor
	Smartphone();
	Smartphone(string nome, float preco, int codigoDeBarras, string modelo, int armazenamento);
	~Smartphone();

	//Getters
	string getModelo();
	int getArmazenamento();

	//Setters
	void setModelo(string modelo);
	void setArmazenamento(int armazenamento);

	void imprimeSmartphone();
};