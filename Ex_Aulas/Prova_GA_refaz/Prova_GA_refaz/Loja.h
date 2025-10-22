#pragma once
#include "Produto.h"

const int MAX_PRODUTOS = 100;

class Loja {
private:

	string nomeLoja;

	Produto* estoque[MAX_PRODUTOS];

	int quantidadeProdutos;

public:

	Loja();
	Loja(string nomeLoja);
	~Loja();

	string getNomeLoja();

	void setNomeLoja(string nomeLoja);

	void adicionarProduto(Produto* produto);

	void removerProduto(int codigoDeBarras);

	void buscarProduto(int codigoDeBarras);

	void infoLoja();

	void editarProduto(int codigoDeBarras);

	void calcularValorEstoque();

	void aplicarDesconto(int codigoDeBarras, float percentualDesconto);

	void verificaEstoque(int codigoDeBarras);

	void simularVenda(int codigoDeBarras);

	void listarProdutosAcimaDeValor(float valorMinimo);

};

