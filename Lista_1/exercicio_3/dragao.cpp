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

void Dragao::setTipo(string tipo) {
	this->tipo = tipo;
}

void Dragao::setIdade(int idade) {
	this->idade = idade;
}

//Getters

string Dragao::getNome() {
	return nome;
}

string Dragao::getCor() {
	return cor;
}

string Dragao::getPoder() {
	return poder;
}

string Dragao::getReino() {
	return reino;
}

string Dragao::getTipo() {
	return tipo;
}

int Dragao::getIdade() {
	return idade;
}

//Imprimir informacoes do dragao

void Dragao::imprime_info() {
	cout << "Nome: " << nome << endl;
	cout << "Cor: " << cor << endl;
	cout << "Poder: " << poder << endl;
	cout << "Reino: " << reino << endl:
	cout << "Tipo: " << tipo << endl;
	cout << "Idade: " << idade << " anos" << endl;
	if (eh_jovem()) {
		cout << "O dragao eh jovem." << endl;
	}
	else {
		cout << "O dragao eh ancião." << endl;
	}
}
//Descobre se o dragao eh jovem

bool Dragao::eh_jovem() {
	return idade < 128;
}
