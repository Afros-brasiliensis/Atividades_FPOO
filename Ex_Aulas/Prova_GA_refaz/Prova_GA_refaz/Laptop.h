#pragma once
#include "Produto.h"

class Laptop : public Produto {

private: 
	//Atributos
	string marca;
	int tamanhoTela; // em polegadas

public:
	//Construtores e Destrutor
	Laptop();
	Laptop(string nome, float preco, int codigoDeBarras, string marca, int tamanhoTela);
	~Laptop();

	//Getters
	string getMarca();
	int getTamanhoTela();

	//Setters
	void setMarca(string marca);
	void setTamanhoTela(int tamanhoTela);

	void imprimeProduto() override;

};