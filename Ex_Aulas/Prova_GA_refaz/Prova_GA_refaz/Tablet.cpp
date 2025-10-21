#include "Tablet.h"

Tablet::Tablet() : Produto() {
	marca = "";
	duracaoBateria = 0.0;
}

Tablet::Tablet(string nome, float preco, int codigoDeBarras, string marca, float duracaoBateria) {
	this->setNome(nome);
	this->setPreco(preco);
	this->setCodigoDeBarras(codigoDeBarras);
	this->marca = marca;
	this->duracaoBateria = duracaoBateria;
}

Tablet::~Tablet() {
}

string Tablet::getMarca() {
	return marca;
}

float Tablet::getDuracaoBateria() {
	return duracaoBateria;
}

void Tablet::setMarca(string marca) {
	this->marca = marca;
}

void Tablet::setDuracaoBateria(float duracaoBateria) {
	this->duracaoBateria = duracaoBateria;
}

void Tablet::imprimeTablet() {
	this->imprimeProduto();
	cout << "Marca: " << this->getMarca() << endl;
	cout << "Duracao da Bateria: " << this->getDuracaoBateria() << " horas" << endl;
}