#pragma once
#include "FuncionarioCaixa.h"

template<typename Type>
class Empresa {
private:
	string nome;
	FuncionarioCaixa<Type>* funcionarios;
	int quantidadeFuncionarios;
	
public:

	Empresa();
	Empresa(string nome, int quantidadeFuncionarios);
	~Empresa();

	string getNome();
	void setNome(string nome);

	FuncionarioCaixa<Type> getFuncionarioCaixa();
	void setFuncionarioCaixa(int indice, FuncionarioCaixa<Type> funcionarioCaixa);

	void imprimirDadosEmpresa();

};

template<typename Type>
Empresa<Type>::Empresa() {
	this->quantidadeFuncionarios = 0;
	this->funcionarios = nullptr;
}

template<typename Type>
Empresa<Type>::Empresa(string nome, int quantidadeFuncionarios) {
	this->nome = nome;
	this->funcionarios = new FuncionarioCaixa<Type>[quantidadeFuncionarios];
	this->quantidadeFuncionarios = quantidadeFuncionarios;
}

template<typename Type>
Empresa<Type>::~Empresa() {
	delete[] this->funcionarios;
}

template<typename Type>
string Empresa<Type>::getNome() {
	return this->nome;
}

template<typename Type>
void Empresa<Type>::setNome(string nome) {
	this->nome = nome;
}

template<typename Type>
FuncionarioCaixa<Type> Empresa<Type>::getFuncionarioCaixa() {
	if(this->quantidadeFuncionarios == 0){
		return this->funcionarios[0];
	} else {
		cout<< "Nenhum funcionario cadastrado!"<< endl;
		return FuncionarioCaixa<Type>();
	}
}

template<typename Type>
void Empresa<Type>::setFuncionarioCaixa(int indice, FuncionarioCaixa<Type> funcionarioCaixa) {
	if (indice < 0 || indice >= this->quantidadeFuncionarios) {
		cout << "Indice invalido!" << endl;
		return;
	}
	this->funcionarios[indice] = funcionarioCaixa;

}

template<typename Type>
void Empresa<Type>::imprimirDadosEmpresa() {
	cout << "Empresa: " << this->nome << endl;
	for (int i = 0; i < this->quantidadeFuncionarios; i++) {
		cout << "Funcionario " << i + 1 << ": " << this->funcionarios[i].getNome() << endl;
		cout << "Endereco: " << this->funcionarios[i].getEndereco() << endl;
	}
}



