#include "Loja.h"
#include "Smartphone.h"
#include "Tablet.h"
#include "Laptop.h"


Loja::Loja() {
	nomeLoja = "Loja Padrão";
	quantidadeProdutos = 0;

	for (int i = 0; i < MAX_PRODUTOS; i++) {
		this->estoque[i] = nullptr;
	}
}

Loja::Loja(string nomeLoja) {
	this->nomeLoja = nomeLoja;
	quantidadeProdutos = 0;
}

Loja::~Loja() {
	for (int i = 0; i < quantidadeProdutos; i++) {
		delete estoque[i];
	}
}

void Loja::setNomeLoja(string nomeLoja) {
	this->nomeLoja = nomeLoja;
}

string Loja::getNomeLoja() {
	return nomeLoja;
}

void Loja::adicionarProduto(Produto* produto) {
	if(quantidadeProdutos >= MAX_PRODUTOS) {
		cout << "Estoque cheio! Nao e possivel adicionar mais produtos." << endl;
		return;
	}
	
	for (int i = 0; i < quantidadeProdutos; i++) {
		if(estoque[i]->produtoIgual(*estoque[i], *produto)) {
			cout << "Produto ja existe no estoque!" << endl;
			return;

		}
	}

	estoque[quantidadeProdutos] = produto;

	quantidadeProdutos++;

	cout << "Produto adicionado com sucesso!" << endl;
}


void Loja::infoLoja() {

	cout << "=============================================" << endl;
	cout << "Nome da Loja: " << this->nomeLoja << endl;
	cout << "Quantidade de Produtos no Estoque: " << this->quantidadeProdutos << endl;
	cout << "=============================================" << endl;

	if (this->quantidadeProdutos == 0) {
			cout << "Estoque vazio!" << endl;
			return;			
	}

	for (int i = 0; i < this->quantidadeProdutos; i++) {
		cout << "Item de estoque" << i + 1 << ":" << endl;
		this->estoque[i]->imprimeProduto();

	}

	cout << "=============================================" << endl;
}