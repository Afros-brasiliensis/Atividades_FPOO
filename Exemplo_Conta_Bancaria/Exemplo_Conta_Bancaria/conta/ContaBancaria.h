#pragma once
#include <string>
#include <iostream>

using namespace std;

enum tipoDeConta {contaCorrente, contaConjunta, contaJuridica, poupanca};

class ContaBancaria {
public:
	//Construtor padrão
	ContaBancaria();
	//Destrutor
	~ContaBancaria();

	//Métodos
	bool abrir(int numeroConta, int numeroAgencia, string nome, string senha, tipoDeConta tipo);
	bool alteraSenha(string novaSenha, string velhaSenha);
	void depositar(float valor);
	bool sacar(float valor, string senha);
	float consultarSaldo(string senha);
	void fechar();

private:
	int numeroDaConta;
	int numeroDaAgencia;
	string nomeCliente;
	string senhaAtual;
	tipoDeConta tipoDaConta;
	float saldo, limite;
	bool ativa;
};
