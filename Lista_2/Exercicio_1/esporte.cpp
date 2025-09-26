#include "esporte.h"

using namespace std;

// Construtor padrão	
Esporte::Esporte() {
	nome = "Desconhecido";
	modalidade = "Desconhecido";
}

//Construtor com parametros
Esporte::Esporte(string nome, string modalidade) {
	this->nome = nome;
	this->modalidade = modalidade;
}

//Destrutor
Esporte::~Esporte() {}

//Setters

//Getters 
string Esporte::getNome() {
	return nome;
}

string Esporte::getModalidade() {
	return modalidade;
}
