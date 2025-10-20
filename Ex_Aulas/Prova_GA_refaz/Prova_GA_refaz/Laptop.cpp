#include "Laptop.h"

Laptop::Laptop() : Produto() {
	marca = "";
	tamanhoTela = 0;
}

Laptop::Laptop(string nome, float preco, int codigoDeBarras, string marca, int tamanhoTela) {
	this->setNome(nome);
	this->setPreco(preco);
	this->setCodigoDeBarras(codigoDeBarras);
	this->marca = marca;
	this->tamanhoTela = tamanhoTela;
}

Laptop::~Laptop() {
}

string Laptop::getMarca() {
	return marca;
}

int Laptop::getTamanhoTela() {
	return tamanhoTela;
}

void Laptop::setMarca(string marca) {
	this->marca = marca;
}

void Laptop::setTamanhoTela(int tamanhoTela) {
	this->tamanhoTela = tamanhoTela;
}
