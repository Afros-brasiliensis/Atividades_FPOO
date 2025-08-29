#include "esporte.h"

// Construtor padrão	
Esporte::Esporte() {
	nome = "";
	modalidades = "";

//Destrutor
Esporte::~Esporte() {}

//Setters
void Esporte::setNome(string nome) {
	this->nome = nome;

void Esporte::setModalidades(string modalidades) {
	this->modalidades = modalidades;

//Getters 

string Esporte::getNome() {
	return nome;

`string Esporte::getModalidades() {
	return modalidades;
}
