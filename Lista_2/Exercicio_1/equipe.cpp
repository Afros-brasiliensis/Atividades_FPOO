#include "equipe.h"

Equipe::Equipe() {
	nome = "Default";
	esporte = Esporte();
	for (int i = 0; i < TAMANHO_MAXIMO_ATLETAS; i++) {
		atletas[i] = nullptr;  // Inicializa os ponteiros como nullptr
	}
}

Equipe::Equipe(string nome, Esporte esporte) {
	this->nome = nome;
	this->esporte = esporte;
	for (int i = 0; i < TAMANHO_MAXIMO_ATLETAS; i++) {
		atletas[i] = nullptr;  // Inicializa os ponteiros como nullptr
	}
}

Equipe::~Equipe() {}

void Equipe::adicionarAtleta(int pos, Atleta* atleta) {
	if (pos >= 0 && pos < TAMANHO_MAXIMO_ATLETAS) {
		atletas[pos] = atleta;
	}
}

string Equipe::getNome() {
	return nome;
}

Atleta* Equipe::getAtletas(int pos){
	return atletas[pos];
}

Esporte Equipe::getEsporte() {
	return esporte;
}

void Equipe::imprime_info() {
	cout << "O nome da equipe é: " << getNome() << endl;
	cout << "O nome e modalidade do esporte são: "
		<< getEsporte().getNome() << " E: " << getEsporte().getModalidade() << endl;
	cout << "Seus atletas são: " << endl;
	for (int i = 0; i < TAMANHO_MAXIMO_ATLETAS; i++) {
		if (getAtletas(i) != nullptr && getAtletas(i)->getIdade() != 0) {
			cout << getAtletas(i)->getNome() << endl;
		}
		else {
			break;
		}
		cout << "E suas idades são, respectivamente: " << endl;
		if (getAtletas(i) != nullptr && getAtletas(i)->getIdade() != 0) {
			cout << getAtletas(i)->getIdade() << endl;
		}
		else {
			break;
		}
	}
}
