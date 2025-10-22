#include "Loja.h"
#include "Smartphone.h"
#include "Tablet.h"
#include "Laptop.h"
#include "Produto.h"


Loja::Loja() {
	nomeLoja = "Loja Padr�o";
	quantidadeProdutos = 0;
}

Loja::Loja(string nomeLoja) {
	this->nomeLoja = nomeLoja;
	this->quantidadeProdutos = 0;

	for (int i = 0; i < MAX_PRODUTOS; i++) {
		this->estoque[i] = nullptr;
	}
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

void Loja::removerProduto(int codigoDeBarras){
	for (int i = 0; i < quantidadeProdutos; i++){
		if (estoque[i]->getCodigoDeBarras() == codigoDeBarras){
			delete estoque[i];
			for(int j = i; j < quantidadeProdutos - 1; j++){
				estoque[i] = estoque[j + 1];
			}
			quantidadeProdutos--;
			cout << "Produto removido com sucesso!" << endl;
			return;
			
		}
	}
}

void Loja::editarProduto(int codigoDeBarras){
	if (quantidadeProdutos == 0){
		cout << "Estoque vazio! Nao ha produtos para editar." << endl;
		return;
	}
	int indiceParaEditar = -1;
	for (int i = 0; i < quantidadeProdutos; i++){
		if (estoque[i]->getCodigoDeBarras() == codigoDeBarras){
			indiceParaEditar = i;
			break;
		}
	}

	if (indiceParaEditar == -1){
		cout << "ERRO: Produto com codigo de barras " << codigoDeBarras << " nao encontrado no estoque." << endl;
		return;
	}

	Produto* produto = this->estoque[indiceParaEditar];

	cout << "Editando produto: " << produto->getNome() << endl;

	string novoNome;
	float novoPreco;

	cout << "Digite o novo nome do produto: ";
	getline(cin, novoNome);
	cout << "Digite o novo preco do produto: ";
	cin >> novoPreco;
	cin.ignore();
	if (novoNome != "") {
		produto->setNome(novoNome);
	}
	if (novoPreco >= 0) {
		produto->setPreco(novoPreco);
	}

	if(Smartphone* smartphone = dynamic_cast<Smartphone*>(produto)){
		string novoModelo;
		int novoArmazenamento;

		cout << "Digite o novo modelo do smartphone: ";
		getline(cin, novoModelo);
		cout << "Digite o novo armazenamento do smartphone (em GB): ";
		cin >> novoArmazenamento;
		cin.ignore();
		smartphone->setModelo(novoModelo);
		smartphone->setArmazenamento(novoArmazenamento);
	}

	else if(Tablet* tablet = dynamic_cast<Tablet*>(produto)){
		string novaMarca;
		float novaDuracaoBateria;
		cout << "Digite a nova marca do tablet: ";
		getline(cin, novaMarca);
		cout << "Digite a nova duracao da bateria do tablet (em horas): ";
		cin >> novaDuracaoBateria;
		cin.ignore();
		tablet->setMarca(novaMarca);
		tablet->setDuracaoBateria(novaDuracaoBateria);
	}

	else if(Laptop* laptop = dynamic_cast<Laptop*>(produto)){
		string novaMarca;
		int novoTamanhoTela;
		cout << "Digite a nova marca do laptop: ";
		getline(cin, novaMarca);
		cout << "Digite o novo tamanho da tela do laptop (em polegadas): ";
		cin >> novoTamanhoTela;
		cin.ignore();
		laptop->setMarca(novaMarca);
		laptop->setTamanhoTela(novoTamanhoTela);
	}

}

void Loja::buscarProduto(int codigoDeBarras) {
	for (int i = 0; i < quantidadeProdutos; i++) {
		if (estoque[i]->getCodigoDeBarras() == codigoDeBarras) {
			cout << "Produto encontrado:" << endl;
			estoque[i]->imprimeProduto();
			return;
		}
	}
	cout << "Produto com codigo de barras " << codigoDeBarras << " nao encontrado no estoque." << endl;
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

void Loja::calcularValorEstoque() {
	float valorTotal = 0.0;

	for (int i = 0; i < this->quantidadeProdutos; i++) {
		valorTotal += this->estoque[i]->getPreco();
	}

	cout << "O valor total do estoque e: R$ " << valorTotal << endl;
	
}

void Loja::aplicarDesconto(int codigoDeBarras, float percentualDesconto) {
	if(percentualDesconto < 0 || percentualDesconto > 100) {
		cout << "Percentual de desconto invalido!" << endl;
		return;
	}
	for (int i = 0; i < this->quantidadeProdutos; i++) {
		if (this->estoque[i]->getCodigoDeBarras() == codigoDeBarras) {
			float precoAtual = this->estoque[i]->getPreco();
			float desconto = precoAtual * (percentualDesconto / 100);
			float novoPreco = precoAtual - desconto;
			this->estoque[i]->setPreco(novoPreco);

			cout << "Desconto aplicado! Novo preco do produto: R$ " << novoPreco << endl;

			return;
		}
	}
}

void Loja::verificaEstoque(int codigoDeBarras) {
	for (int i = 0; i < this->quantidadeProdutos; i++) {
		if (this->estoque[i]->getCodigoDeBarras() == codigoDeBarras) {
			cout << "Produto com codigo de barras " << codigoDeBarras << " esta em estoque. " << endl;
			return;
		}
	}
	cout << "Produto com codigo de barras " << codigoDeBarras << " nao esta em estoque. " << endl;
}

void Loja::simularVenda(int codigoDeBarras) {
	int indiceVenda = -1;

	
	for (int i = 0; i < this->quantidadeProdutos; i++) {
		if (this->estoque[i]->getCodigoDeBarras() == codigoDeBarras) {
			indiceVenda = i;
			break;
		}
	}

	
	if (indiceVenda == -1) {
		cout << "ERRO: Venda nao pode ser concluida. Produto nao disponivel." << endl; 
		return;
	}

	cout << "\n--- Venda Realizada ---" << endl;
	cout << "Produto: " << this->estoque[indiceVenda]->getNome() << endl; 
	cout << "Preco: R$ " << this->estoque[indiceVenda]->getPreco() << endl; 
	cout << "Valor Total da Venda: R$ " << this->estoque[indiceVenda]->getPreco() << endl; 

	this->removerProduto(codigoDeBarras); 
}

void Loja::listarProdutosAcimaDeValor(float valorMinimo) {
	bool encontrou = false;
	cout << "Produtos com preco acima de R$ " << valorMinimo << ":" << endl;
	for (int i = 0; i < this->quantidadeProdutos; i++) {
		if (this->estoque[i]->getPreco() > valorMinimo) {
			this->estoque[i]->imprimeProduto();
			encontrou = true;
		}
	}
	if (!encontrou) {
		cout << "Nenhum produto encontrado com preco acima de R$ " << valorMinimo << "." << endl;
	}
}