#include "ContaBancaria.h"


ContaBancaria::ContaBancaria(void)
{
	ativa = false;
	saldo = 0;
	limite = 1000;
}


ContaBancaria::~ContaBancaria(void)
{
}

bool ContaBancaria::abrir(int numeroConta, int numeroAgencia, string nome, string novaSenha, tipoDeConta tipo)
{
	if(ativa == false)
	{
		numeroDaConta = numeroConta;
		numeroDaAgencia = numeroAgencia;
		nomeCliente = nome;
		senhaAtual = novaSenha;
		tipoDaConta = tipo;
		ativa = true;
		return true;
	}
	else
		return false;
	
}

bool ContaBancaria::alteraSenha(string novaSenha, string velhaSenha)
{
	if(ativa == true && senhaAtual == velhaSenha)
	{
		senhaAtual = novaSenha;
		return true;
	}
	return false;
}

void ContaBancaria::depositar(float valor)
{
	saldo += valor;
}

bool ContaBancaria::sacar(float valor, string senha)
{
	if(ativa && senha == senhaAtual)
	{
		if(valor < saldo + limite)
		{
			saldo -= valor;
			return true;
		}
	}
	return false;
}

float ContaBancaria::consultarSaldo(string senha)
{
	if(ativa == true && senha == senhaAtual)
	{
		return saldo;
	}
	return -9999;
}

void ContaBancaria::fechar()
{
	saldo = 0;
	ativa = false;
}