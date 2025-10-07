#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Cena.h" // Inclui a definição da nossa classe

// --- FUNÇÃO AUXILIAR PARA DIVIDIR STRINGS ---
// Usada para interpretar a linha do item e a linha de vitória/derrota
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
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

// --- CONSTRUTOR E DESTRUTOR ---

Cena::Cena() {
    // Inicializa os ponteiros como nulos e os inteiros com um valor padrão
    this->item = nullptr;
    this->inimigo = nullptr;
    this->cenaVitoria = -1; // -1 indica que não foi definido
    this->cenaDerrota = -1;
}

Cena::~Cena() {
    // Liberta a memória alocada dinamicamente para evitar memory leaks
    delete this->item;
    delete this->inimigo;
}

// --- MÉTODO PRINCIPAL DE CARREGAMENTO ---

bool Cena::carregar(int numeroCena) {
    // Limpa dados de uma cena anterior
    delete this->item;
    this->item = nullptr;
    delete this->inimigo;
    this->inimigo = nullptr;

    this->textoPrincipal.clear();
    this->textosDasEscolhas.clear();
    this->cenasDeDestino.clear();
    this->cenaVitoria = -1;
    this->cenaDerrota = -1;

    ifstream arquivo("cenas/" + to_string(numeroCena) + ".txt");
    if (!arquivo.is_open()) {
        cerr << "Erro: Não foi possível abrir o arquivo da cena " << numeroCena << endl;
        return false;
    }

    string linha;
    bool isMonstro = false; // Flag para saber se estamos a ler os dados de um monstro

    while (getline(arquivo, linha)) {
        // Ignora linhas vazias
        if (linha.empty()) {
            continue;
        }

        // --- INTERPRETAÇÃO DA LINHA ---

        if (linha[0] == '#') { // É uma linha de escolha [cite: 108-110]
            size_t posDoisPontos = linha.find(':');
            if (posDoisPontos != string::npos) {
                string strNumero = linha.substr(1, posDoisPontos - 1);
                string texto = linha.substr(posDoisPontos + 2);
                cenasDeDestino.push_back(stoi(strNumero));
                textosDasEscolhas.push_back(texto);
            }
            [cite_start]
        }
        else if (linha.rfind("I: ", 0) == 0) { // É uma linha de item [cite: 107, 127, 141]
            vector<string> dadosItem = split(linha.substr(3), ';');
            if (dadosItem.size() == 5) {
                Item* novoItem = new Item(dadosItem[0], dadosItem[1][0], stoi(dadosItem[2]), stoi(dadosItem[3]), stoi(dadosItem[4]));
                if (isMonstro && this->inimigo != nullptr) {
                    this->inimigo->setItemDrop(*novoItem); // Assume que o Inimigo tem este método
                    delete novoItem; // A cópia foi feita, podemos apagar este
                }
                else {
                    this->item = novoItem;
                }
            }
            [cite_start]
        }
        else if (linha.rfind("N: ", 0) == 0) { // Nome do monstro, início de um bloco de monstro [cite: 120, 135]
            isMonstro = true;
            this->inimigo = new Inimigo(linha.substr(3), 0, 0); // Habilidade e Energia serão lidas depois
            [cite_start]
        }
        else if (linha.rfind("H: ", 0) == 0 && this->inimigo != nullptr) { // Habilidade do monstro [cite: 122, 136]
            this->inimigo->setHabilidade(stoi(linha.substr(3))); // Assume que o Inimigo tem este método
            [cite_start]
        }
        else if (linha.rfind("E: ", 0) == 0 && this->inimigo != nullptr) { // Energia do monstro [cite: 124, 138]
            this->inimigo->setEnergia(stoi(linha.substr(3))); // Assume que o Inimigo tem este método
            [cite_start]
        }
        else if (linha.rfind("S: ", 0) == 0 && this->inimigo != nullptr) { // Sorte do monstro [cite: 123, 137]
            this->inimigo->setSorte(stoi(linha.substr(3))); // Assume que o Inimigo tem este método
            [cite_start]
        }
        else if (linha.rfind("T: ", 0) == 0 && this->inimigo != nullptr) { // Tesouro do monstro [cite: 125, 139]
            this->inimigo->setTesouro(stoi(linha.substr(3))); // Assume que o Inimigo tem este método
            [cite_start]
        }
        else if (linha.rfind("P: ", 0) == 0 && this->inimigo != nullptr) { // Provisão do monstro [cite: 126, 140]
            this->inimigo->setProvisoes(stoi(linha.substr(3))); // Assume que o Inimigo tem este método
            [cite_start]
        }
        else if (isMonstro && linha.find(':') != string::npos) { // Linha de vitória/derrota [cite: 128, 142]
            vector<string> destinos = split(linha, ':');
            if (destinos.size() == 2) {
                this->cenaVitoria = stoi(destinos[0]);
                this->cenaDerrota = stoi(destinos[1]);
            }
        }
        else { // É texto normal da aventura
            textoPrincipal += linha + "\n";
        }
    }

    arquivo.close();
    return true;
}

// --- MÉTODOS GETTER ---

string Cena::getTexto() const {
    return this->textoPrincipal;
}

Item* Cena::getItem() const {
    return this->item;
}

bool Cena::isCenaDeCombate() const {
    return this->inimigo != nullptr;
}

Inimigo* Cena::getInimigo() const {
    return this->inimigo;
}

const vector<string>& Cena::getTextosDasEscolhas() const {
    return this->textosDasEscolhas;
}

const vector<int>& Cena::getCenasDeDestino() const {
    return this->cenasDeDestino;
}

int Cena::getCenaVitoria() const {
    return this->cenaVitoria;
}

int Cena::getCenaDerrota() const {
    return this->cenaDerrota;
}