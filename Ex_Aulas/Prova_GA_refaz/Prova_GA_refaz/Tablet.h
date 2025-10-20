#pragma once
#include "Produto.h"

class Tablet : public Produto {
private:
	//Atributos
	string marca;
	float duracaoBateria; // em horas

public:

	//Construtores e Destrutor

	Tablet();
	Tablet(string nome, float preco, int codigoDeBarras, string marca, float duracaoBateria);
	~Tablet();

	//Getters
	string getMarca();

	float getDuracaoBateria();

	//Setters

	void setMarca(string marca);

	void setDuracaoBateria(float duracaoBateria);
};