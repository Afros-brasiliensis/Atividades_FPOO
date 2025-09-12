#include "dragao.h"

//Construtor padrao
Dragao::Dragao() {
	nome = "";
	cor = "";
	poder = "";
	reino = "";
	tipo = "";
	idade = 0;
}

//Destrutor
Dragao::~Dragao() {
}

//Setters
void Dragao::setNome(string nome) {
	this->nome = nome;
}

void Dragao::setCor(string cor) {
	this->cor = cor;
}

void Dragao::setPoder(string poder) {
	this->poder = poder;
}

void Dragao::setReino(string reino) {
	this->reino = reino;
}