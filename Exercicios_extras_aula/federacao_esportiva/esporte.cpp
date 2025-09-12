#include "esporte.h"

using namespace std;

// Construtor padr�o	
Esporte::Esporte() {
	nome = "";
	modalidades = "";
}

//Destrutor
Esporte::~Esporte() {}

//Setters
void Esporte::setNome(string nome) {
	this->nome = nome;
}
void Esporte::setModalidades(string modalidades) {
	this->modalidades = modalidades;
}
//Getters 
string Esporte::getNome() {
	return nome;
}

string Esporte::getModalidades() {
	return modalidades;
}

//M�todos

void Esporte::imprime_info() {
	cout << "Nome do esporte: " << getNome() << endl;
	cout << "Modalidades: " << getModalidades() << endl;
}
