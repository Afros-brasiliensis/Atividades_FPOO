#include "atleta_aula.h"

//Construtor
Atleta::Atleta() {
		nome = "";
		idade = 0;
}

Atleta::~Atleta() {
}

//Getters

string Atleta::getNome() {
	return nome;
}

float Atleta::getIdade() {
	return idade;
}

//Setters

void Atleta::setNome(string nome) {
	this->nome = nome;
}

void Atleta::setIdade(float idade) {
	this->idade = idade;
}

void Atleta::imprime_info(string nome, float idade) {
	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
}

