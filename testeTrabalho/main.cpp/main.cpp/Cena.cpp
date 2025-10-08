#include "Cena.h"
#include <fstream>
#include <iostream>
#include <sstream> // Usado para dividir strings de forma eficiente

// --- FUN��O AUXILIAR PARA DIVIDIR STRINGS ---
// Usada para interpretar a linha do item (separada por ';')
static vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// --- CONSTRUTOR E DESTRUTOR ---

Cena::Cena() :
    textoPrincipal(""),
    item(nullptr),
    inimigo(nullptr),
    cenaVitoria(0),
    cenaDerrota(0)
{
}

Cena::~Cena() {
    delete item;
    delete inimigo;
}

// --- M�TODO PRINCIPAL DE CARREGAMENTO ---

bool Cena::carregar(int numeroCena) {
    // 1. Limpa os dados da cena anterior para evitar lixo de mem�ria
    delete item;
    item = nullptr;
    delete inimigo;
    inimigo = nullptr;
    textoPrincipal.clear();
    textoEscolhas.clear();
    cenasDestino.clear();
    cenaVitoria = 0;
    cenaDerrota = 0;

    // 2. Abre o arquivo da cena (ex: "cenas/1.txt")
    ifstream arquivo("scenes/" + to_string(numeroCena) + ".txt");
    if (!arquivo.is_open()) {
        cerr << "Erro: Nao foi possivel abrir o arquivo da cena " << numeroCena << endl;
        return false; // Retorna false se o arquivo n�o existir (pode ser o fim do jogo)
    }

    string linha;
    bool lendoMonstro = false;

    // 3. L� o arquivo linha por linha
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;

        // 4. Interpreta cada tipo de linha de acordo com as regras do PDF

        // Linha de ESCOLHA (come�a com '#') [cite: 101, 108, 109, 110]
        if (linha[0] == '#') {
            size_t posDoisPontos = linha.find(':');
            string numStr = linha.substr(1, posDoisPontos - 1);
            string texto = linha.substr(posDoisPontos + 2); // Pula o ':' e o espa�o
            cenasDestino.push_back(stoi(numStr));
            textoEscolhas.push_back(texto);
        }
        // Linha de ITEM (come�a com 'I:') [cite: 107, 127, 141, 143]
        else if (linha.rfind("I:", 0) == 0) {
            vector<string> dados = split(linha.substr(2), ';'); // Pula o "I:"
            // nome;tipo;combate;FA;dano
            if (dados.size() == 5) {
                Item* novoItem = new Item(dados[0], dados[1][0], stoi(dados[2]), stoi(dados[3]), stoi(dados[4]));
                if (lendoMonstro && inimigo) {
                    inimigo->setItemDrop(*novoItem); // Define o item que o monstro dropa
                    delete novoItem; // A c�pia foi feita, podemos deletar o tempor�rio
                }
                else {
                    this->item = novoItem; // Item encontrado na cena
                }
            }
        }
        // Linha de NOME DO MONSTRO (come�a com 'N:') [cite: 120, 135]
        else if (linha.rfind("N:", 0) == 0) {
            lendoMonstro = true;
            inimigo = new Monstro(linha.substr(2), 0, 0); // Cria o monstro, stats v�m depois
        }
        // Linha de HABILIDADE do monstro [cite: 122, 136]
        else if (lendoMonstro && linha.rfind("H:", 0) == 0) {
            // Supondo que voc� crie um m�todo setHabilidade em Monstro
            // inimigo->setHabilidade(stoi(linha.substr(2)));
        }
        // Linha de ENERGIA do monstro [cite: 124, 138]
        else if (lendoMonstro && linha.rfind("E:", 0) == 0) {
            // Supondo que voc� crie um m�todo setEnergia em Monstro
            // inimigo->setEnergia(stoi(linha.substr(2)));
        }
        // Linha de VIT�RIA/DERROTA (ex: "12:13") [cite: 128, 142]
        else if (lendoMonstro && linha.find(':') != string::npos) {
            size_t posDoisPontos = linha.find(':');
            this->cenaVitoria = stoi(linha.substr(0, posDoisPontos));
            this->cenaDerrota = stoi(linha.substr(posDoisPontos + 1));
        }
        // Se n�o for nenhuma das anteriores, � texto da hist�ria
        else {
            textoPrincipal += linha + "\n";
        }
    }

    arquivo.close();
    return true;
}

// --- M�TODOS GETTER ---

string Cena::getTexto() {
    return this->textoPrincipal;
}

bool Cena::isCenaDeCombate() {
    return this->inimigo != nullptr;
}

Monstro* Cena::getInimigo() {
    return this->inimigo;
}

int Cena::getCenaVitoria() {
    return this->cenaVitoria;
}

int Cena::getCenaDerrota() {
    return this->cenaDerrota;
}

Item* Cena::getItem() {
    return this->item;
}

const vector<string>& Cena::getTextoEscolhas() {
    return this->textoEscolhas;
}

const vector<int>& Cena::getCenasDestino() {
    return this->cenasDestino;
}