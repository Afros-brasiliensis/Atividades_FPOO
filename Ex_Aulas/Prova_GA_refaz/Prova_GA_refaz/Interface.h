#pragma once
#include "Loja.h"

class Interface {
private: 
	Loja loja;
	
	void exibirMenu();

	void processarAdicionarProduto();

	void processarRemoverProduto();

	void processarBuscarProduto();

	void processarEditarProduto();

	void processarCalcularValorEstoque();

	void processarAplicarDesconto();

	void processarVerificaEstoque();

	void processarSimularVenda();

	void processarListarProdutosAcimaDeValor();

	void processarInfoLoja();

	int lerInt(string prompt);
	float lerFloat(string prompt);
	string lerString(string prompt);

public:
	Interface();

	void iniciar();

};