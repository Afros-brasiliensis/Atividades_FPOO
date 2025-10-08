#include <iostream>
#include <cstdlib> 
#include "Personagem.h"

Personagem::Personagem() :
    nome(""),
    habilidade(0),
    energia(0),
    sorte(0),
    tesouro(0),
    provisoes(0),
    armaEquipada(nullptr) // Ponteiro da arma comeca nulo
{
}

Personagem::Personagem(string nome, int habilidade, int energia, int sorte) :
    nome(nome),
    habilidade(habilidade),
    energia(energia),
    sorte(sorte),
    tesouro(0),
    provisoes(2), 
    armaEquipada(nullptr) 
{
}

Personagem::~Personagem() {
}

string Personagem::getNome() { return this->nome; }
int Personagem::getHabilidade() { return this->habilidade; }
int Personagem::getEnergia() { return this->energia; }
int Personagem::getSorte() { return this->sorte; }
int Personagem::getTesouro() { return this->tesouro; }
int Personagem::getProvisoes() { return this->provisoes; }
vector<Item> Personagem::getInventario() { return this->inventario; }

int Personagem::getBonusForcaAtaque() {
    if (this->armaEquipada != nullptr) {
        return this->armaEquipada->getBonusForcaAtaque();
    }
    return 0;
}

int Personagem::getBonusDano() {
    if (this->armaEquipada != nullptr) {
        return this->armaEquipada->getBonusDano();
    }
    return 0;
}


// --- METODOS DE LOGICA ---

void Personagem::tomarDano(int dano) {
    this->energia -= dano;
    if (this->energia < 0) this->energia = 0;
}

void Personagem::curar(int cura) {
    this->energia += cura;
}

bool Personagem::usarSorte() {
    if (this->sorte <= 0) {
        return false;
    }
    // Lembre-se de chamar srand(time(nullptr)) uma vez no main.cpp
    int rolagem = rand() % 10 + 1; // Numero aleatorio de 1 a 10

    this->sorte--; // Cada vez que a sorte for usada, deve ser decrementada
    return rolagem <= this->sorte + 1;
}

bool Personagem::estaVivo() {
    return this->energia > 0;
}


// --- METODOS DE INVENTARIO E EQUIPAMENTO ---

void Personagem::adicionarItem(Item& item) {
    this->inventario.push_back(item);
}

void Personagem::usarProvisao() {
    if (this->provisoes > 0) {
        this->provisoes--;
        this->energia += 4; // Uma provisao recupera sempre 4 pontos de vida
        cout << "Voce usou uma provisao. Energia recuperada." << endl;
    }
    else {
        cout << "Voce nao tem mais provisoes!" << endl;
    }
}

void Personagem::adicionarTesouro(int valor) {
    this->tesouro += valor;
}

void Personagem::equiparArma(int indiceDoInventario) {
    if (indiceDoInventario < 0 || indiceDoInventario >= this->inventario.size()) {
        cout << "Selecao invalida." << endl;
        return;
    }

    Item& itemParaEquipar = this->inventario[indiceDoInventario];

    if (itemParaEquipar.getTipo() == 'w') { // 'w' para arma
        this->armaEquipada = &itemParaEquipar;
        cout << "Voce equipou: " << itemParaEquipar.getNome() << endl;
    }
    else {
        cout << "Este item nao e uma arma e nao pode ser equipado." << endl;
    }
}

void Personagem::mostrarInventario() {
    cout << "\n--- INVENTARIO DE " << this->nome << " ---" << endl;
    cout << "Habilidade: " << this->habilidade << " | Energia: " << this->energia << " | Sorte: " << this->sorte << endl;
    cout << "Tesouro: " << this->tesouro << " | Provisoes: " << this->provisoes << endl;
    cout << "--------------------" << endl;
    cout << "Equipamento:" << endl;
    cout << "  Arma: " << (this->armaEquipada ? this->armaEquipada->getNome() : "Nenhuma") << endl;
    cout << "--------------------" << endl;
    cout << "Itens na mochila:" << endl;
    if (this->inventario.empty()) {
        cout << "  (Vazia)" << endl;
    }
    else {
        for (size_t i = 0; i < this->inventario.size(); ++i) {
            cout << "  " << i + 1 << ". " << this->inventario[i].getNome() << endl;
        }
    }
    cout