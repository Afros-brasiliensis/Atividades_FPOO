#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Cena.h" // Inclui o seu arquivo de cabecalho

// Funcao auxiliar para dividir strings (usada para Item e Vitoria/Derrota)
vector<string> split(const string& s, char delimiter) {
	vector<string> tokens;
	// ... (implementacao da funcao split, como na resposta anterior)
	string token;
	size_t start = 0;
	size_t end = s.find(delimiter);
	while (end != string::npos) {
		tokens.push_back(s.substr(start, end - start));
		start = end + 1;
		end = s.find(delimiter, start);
	}
	tokens.push_back(s.substr(start, end));
	return tokens;
}

// O construtor Cena() e o destrutor ~Cena() nao sao implementados aqui,
// pois voce ja os implementou diretamente no arquivo Cena.h

bool Cena::carregar(int numeroCena) {
	// Limpa dados de uma cena anterior
	delete this->item;
	this->item = nullptr;
	delete this->inimigo;
	this->inimigo = nullptr;

	this->textoPrincipal.clear();
	this->textoEscolhas.clear(); // Usando o nome do seu header
	this->cenasDestino.clear();   // Usando o nome do seu header
	this->cenaVitoria = -1;
	this->cenaDerrota = -1;

	ifstream arquivo("cenas/" + to_string(numeroCena) + ".txt");
	if (!arquivo.is_open()) {
		cerr << "Erro: Nao foi possivel abrir o arquivo da cena " << numeroCena << endl;
		return false;
	}

	string linha;
	bool isMonstroScene = false;

	// Variaveis temporarias para criar o Monstro
	string tempNome;
	int tempHabilidade = 0;
	int tempEnergia = 0;

	while (getline(arquivo, linha)) {
		if (linha.empty()) continue;

		if (linha[0] == '#') {
			size_t posDoisPontos = linha.find(':');
			if (posDoisPontos != string::npos) {
				string strNumero = linha.substr(1, posDoisPontos - 1);
				string texto = linha.substr(posDoisPontos + 2);
				cenasDestino.push_back(stoi(strNumero));
				textoEscolhas.push_back(texto);
			}
		}
		else if (linha.rfind("I: ", 0) == 0) {
			vector<string> dadosItem = split(linha.substr(3), ';');
			if (dadosItem.size() == 5) {
				Item* novoItem = new Item(dadosItem[0], dadosItem[1][0], stoi(dadosItem[2]), stoi(dadosItem[3]), stoi(dadosItem[4]));
				if (this->inimigo != nullptr) {
					this->inimigo->setItemDrop(*novoItem);
					delete novoItem;
				}
				else {
					this->item = novoItem;
				}
			}
		}
		else if (linha.rfind("N: ", 0) == 0) {
			isMonstroScene = true;
			tempNome = linha.substr(3);
		}
		else if (isMonstroScene) { // Se ja sabemos que e uma cena de monstro
			if (linha.rfind("H: ", 0) == 0) {
				tempHabilidade = stoi(linha.substr(3));
			}
			else if (linha.rfind("E: ", 0) == 0) {
				tempEnergia = stoi(linha.substr(3));
				// Agora que temos N, H e E, podemos criar o objeto Monstro
				this->inimigo = new Monstro(tempNome, tempHabilidade, tempEnergia);
			}
			else if (this->inimigo != nullptr) { // Garante que o monstro ja foi criado
				if (linha.rfind("T: ", 0) == 0) {
					this->inimigo->setTesouro(stoi(linha.substr(3)));
				}
				else if (linha.rfind("P: ", 0) == 0) {
					this->inimigo->setProvisoes(stoi(linha.substr(3)));
				}
				else if (linha.rfind("FUGIR: ", 0) == 0) {
					this->inimigo->setFugaPermitida(linha.substr(7) == "N" ? false : true);
				}
				else if (linha.find(':') != string::npos && linha.find(" ") == string::npos) { // Linha de vitoria/derrota (ex: "12:13")
					vector<string> destinos = split(linha, ':');
					if (destinos.size() == 2) {
						this->cenaVitoria = stoi(destinos[0]);
						this->cenaDerrota = stoi(destinos[1]);
					}
				}
				else {
					textoPrincipal += linha + "\n";
				}
			}
		}
		else {
			textoPrincipal += linha + "\n";
		}
	}

	arquivo.close();
	return true;
}

// --- METODOS GETTER ---
string Cena::getTexto() { return this->textoPrincipal; }
Item* Cena::getItem() { return this->item; }
bool Cena::isCenaDeCombate() { return this->inimigo != nullptr; }
Monstro* Cena::getInimigo() { return this->inimigo; }
int Cena::getCenaVitoria() { return this->cenaVitoria; }
int Cena::getCenaDerrota() { return this->cenaDerrota; }
const vector<string>& Cena::getTextoEscolhas() { return this->textoEscolhas; }
const vector<int>& Cena::getCenasDestino() { return this->cenasDestino; }