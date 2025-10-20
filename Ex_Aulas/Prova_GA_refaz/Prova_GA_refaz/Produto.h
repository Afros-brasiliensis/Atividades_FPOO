#pragma once
#include <string>
#include <iostream>

using namespace std;

class Produto {

private:

	string nome;
	float preco;
	int codigoDeBarras;

public:

	Produto();
	Produto(string nome, float preco, int codigoDeBarras);
	~Produto();

	string getNome();
	float getPreco();
	int getCodigoDeBarras();

	void setNome(string nome);
	void setPreco(float preco);
	void setCodigoDeBarras(int codigoDeBarras);

	bool produtoIgual(Produto a, Produto b);




};