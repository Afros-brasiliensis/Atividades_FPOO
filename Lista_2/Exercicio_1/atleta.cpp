#pragma once

#include "atleta.h"

using namespace std;

//Construtor padr�o
Atleta::Atleta() {
	nome = "Desconhecido";
		idade = 0;
}

Atleta::~Atleta() {}

Atleta::Atleta(string nome, int idade) {
	this->nome = nome;
	this->idade = idade;
}

string Atleta::getNome() {
	return nome;
}

int Atleta::getIdade() {
	return idade;
}

void Atleta::setNome(string nome) {
	this->nome = nome;
}

void Atleta::imprime_info() {
	cout << "O nome do atleta �: " << getNome() << endl;
	cout << "A idade do atleta �: " << getIdade() << endl;
}