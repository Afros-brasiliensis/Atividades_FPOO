#include "Produto.h"

Produto::Produto() {
	nome = "";
	preco = 0.0;
	codigoDeBarras = 0;
}

Produto::Produto(string nome, float preco, int codigoDeBarras) {
	this->nome = nome;
	this->preco = preco;
	this->codigoDeBarras = codigoDeBarras;
}

Produto::~Produto() {
}

string Produto::getNome() {
	return nome;
}

float Produto::getPreco() {
	return preco;
}

int Produto::getCodigoDeBarras(){
	return codigoDeBarras;
}

void Produto::setNome(string nome) {
	this->nome = nome;
}

void Produto::setPreco(float preco) {
	this->preco = preco;
}

void Produto::setCodigoDeBarras(int codigoDeBarras) {
	this->codigoDeBarras = codigoDeBarras;
}

bool Produto::produtoIgual(Produto a, Produto b) {
	return (a.getCodigoDeBarras() == b.getCodigoDeBarras());
}


