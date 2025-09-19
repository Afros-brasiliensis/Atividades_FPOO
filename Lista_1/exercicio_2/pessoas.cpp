#include "pessoas.h"

//Construtor padrão
Pessoa::Pessoa() {
	nome = "";
	idade = 0;
	altura = 0;
	qnt_irmaos = 0;
	endereco = "";
}
//Destrutor
Pessoa::~Pessoa() {
}
//Setters
void Pessoa::setNome(string nome) {
	this->nome = nome;
}
void Pessoa::setIdade(float idade) {
	this->idade = idade;
}
void Pessoa::setAltura(float altura) {
	this->altura = altura;
}
void Pessoa::setQntIrmaos(float qnt_irmaos) {
	this->qnt_irmaos = qnt_irmaos;
}
void Pessoa::setEndereco(string endereco) {
	this->endereco = endereco;
}

//Getters
string Pessoa::getNome() {
	return nome;
}
float Pessoa::getIdade() {
	return idade;
}
float Pessoa::getAltura() {
	return altura;
}
float Pessoa::getQntIrmaos() {
	return qnt_irmaos;
}
string Pessoa::getEndereco() {
	return endereco;
}
//Métodos
void Pessoa::imprime_info() {
	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
	cout << "Altura: " << altura << endl;
	cout << "Quantidade de Irmãos: " << qnt_irmaos << endl;
	cout << "Endereço: " << endereco << endl;
}
bool Pessoa::is_filho_unico() {
	if (qnt_irmaos == 0) {
		return true;
	} else {
		return false;
	}
}
