#include "Interface.h"
#include "Smartphone.h"
#include "Tablet.h"
#include "Laptop.h"

Interface::Interface() {
	loja = Loja("Minha Loja");

}

void Interface::exibirMenu() {
	cout << "===== Menu da Loja =====" << endl;
	cout << "1. Adicionar Produto" << endl;
	cout << "2. Remover Produto" << endl;
	cout << "3. Buscar Produto" << endl;
	cout << "4. Editar Produto" << endl;
	cout << "5. Calcular Valor do Estoque" << endl;
	cout << "6. Aplicar Desconto" << endl;
	cout << "7. Verificar Estoque" << endl;
	cout << "8. Simular Venda" << endl;
	cout << "9. Listar Produtos Acima de um Valor" << endl;
	cout << "10. Informacoes da Loja" << endl;
	cout << "0. Sair" << endl;
	cout << "=========================" << endl;
}

void Interface::iniciar() {
	int opcao;
	do {
		exibirMenu();
		opcao = lerInt("\nDigite a opcao desejada: ");
		switch (opcao) {
		case 1:
			processarAdicionarProduto();
			break;
		case 2:
			processarRemoverProduto();
			break;
		case 3:
			processarBuscarProduto();
			break;
		case 4:
			processarEditarProduto();
			break;
		case 5:
			processarCalcularValorEstoque();
			break;
		case 6:
			processarAplicarDesconto();
			break;
		case 7:
			processarVerificaEstoque();
			break;
		case 8:
			processarSimularVenda();
			break;
		case 9:
			processarListarProdutosAcimaDeValor();
			break;
		case 10:
			processarInfoLoja();
			break;
		case 0:
			cout << "Saindo do programa. Obrigado por usar a Loja!" << endl;
			break;
		default:
			cout << "Opcao invalida! Tente novamente." << endl;
		}
		if (opcao != 0) {
			cout << "\nPressione Enter para continuar...";
			cin.ignore(1000, '\n');
			cin.get();
		}
	} while (opcao != 0);
}

void Interface::processarAdicionarProduto() {
	cout << "\n--- Adicionar Produto ---" << endl;
	int tipo = lerInt("Escolha o tipo de produto (1-Smartphone, 2-Tablet, 3-Laptop): ");

	int codigoDeBarras = lerInt("Digite o codigo de barras: ");
	string nome = lerString("Digite o nome do produto: ");
	float preco = lerFloat("Digite o preco do produto: ");

	Produto* novoProduto = nullptr;

	if (tipo == 1) {
		string modelo = lerString("Digite o modelo do smartphone: ");
		int armazenamento = lerInt("Digite o armazenamento do smartphone (em GB): ");
		novoProduto = new Smartphone(nome, preco, codigoDeBarras, modelo, armazenamento);
	}
	else if (tipo == 2) {
		string marca = lerString("Digite a marca do tablet: ");
		float duracaoBateria = lerFloat("Digite a duracao da bateria do tablet (em horas): ");
		novoProduto = new Tablet(nome, preco, codigoDeBarras, marca, duracaoBateria);
	}
	else if (tipo == 3) {
		string marca = lerString("Digite a marca do laptop: ");
		int tamanhoTela = lerInt("Digite o tamanho da tela do laptop (em polegadas): ");
		novoProduto = new Laptop(nome, preco, codigoDeBarras, marca, tamanhoTela);
	}
	else {
		cout << "Tipo de produto invalido!" << endl;
		return;
	}

	loja.adicionarProduto(novoProduto);
}

void Interface::processarRemoverProduto() {
	cout << "\n--- Remover Produto ---" << endl;
	int codigoDeBarras = lerInt("Digite o codigo de barras do produto a ser removido: ");
	loja.removerProduto(codigoDeBarras);
}

void Interface::processarBuscarProduto() {
	cout << "\n--- Buscar Produto ---" << endl;
	int codigoDeBarras = lerInt("Digite o codigo de barras do produto a ser buscado: ");
	loja.buscarProduto(codigoDeBarras);
}

void Interface::processarEditarProduto() {
	cout << "\n--- Editar Produto ---" << endl;
	int codigoDeBarras = lerInt("Digite o codigo de barras do produto a ser editado: ");
	loja.editarProduto(codigoDeBarras);
}

void Interface::processarInfoLoja() {
	cout << "\n--- Informacoes da Loja ---" << endl;
	loja.infoLoja();
}

void Interface::processarCalcularValorEstoque() {
	cout << "\n--- Calcular Valor do Estoque ---" << endl;
	loja.calcularValorEstoque();
}

void Interface::processarAplicarDesconto() {
	cout << "\n--- Aplicar Desconto ---" << endl;
	int codigoDeBarras = lerInt("Digite o codigo de barras do produto: ");
	float percentualDesconto = lerFloat("Digite o percentual de desconto: ");
	loja.aplicarDesconto(codigoDeBarras, percentualDesconto);
}

void Interface::processarVerificaEstoque() {
	cout << "\n--- Verificar Estoque ---" << endl;
	int codigoDeBarras = lerInt("Digite o codigo de barras do produto: ");
	loja.verificaEstoque(codigoDeBarras);
}

void Interface::processarSimularVenda() {
	cout << "\n--- Simular Venda ---" << endl;
	int codigoDeBarras = lerInt("Digite o codigo de barras do produto a ser vendido: ");
	loja.simularVenda(codigoDeBarras);
}

void Interface::processarListarProdutosAcimaDeValor() {
	cout << "\n--- Listar Produtos Acima de um Valor ---" << endl;
	float valorMinimo = lerFloat("Digite o valor minimo: ");
	loja.listarProdutosAcimaDeValor(valorMinimo);
}

int Interface::lerInt(string prompt) {
	int valor;
	cout << prompt;
	while(!(cin >> valor)) {
		cout << "Entrada invalida. Por favor, digite um numero inteiro." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cin.ignore(1000, '\n');
	return valor;
}

float Interface::lerFloat(string prompt) {
	float valor;
	cout << prompt;
	while (!(cin >> valor)) {
		cout << "Entrada invalida. Por favor, digite um numero inteiro." << endl;
		cin.ignore(1000, '\n');
	}
	cin.ignore(1000, '\n');
	return valor;
}

string Interface::lerString(string prompt) {
	string valor;
	cout << prompt;
	cin >> valor;
	cin.ignore(1000, '\n');
	return valor;
}


