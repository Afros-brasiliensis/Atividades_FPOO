#include "Monstro.h"
#include "Item.h"

Monstro::Monstro(string nome, int habilidade, int energia) :
	nome(nome),
	habilidade(habilidade),
	energia(energia),
	tesouroDrop(0),
	provisoesDrop(0),
	itemDrop(nullptr) //inicia como nulo, para indicar que não há drop
{

}

//getters
string Monstro::getNome() {
	return this->nome;
}
int Monstro::getHabilidade() {
	return this->habilidade;
}
int Monstro::getEnergia() {
	return this->energia;
}
bool Monstro::isFugaPermitida() {
	return this->fugaPermitida;
}
bool Monstro::estaVivo() {
	return this->energia > 0;
}

//setters
void Monstro::setTesouro(int valor) {
	this->tesouroDrop = valor;
}

void Monstro::setProvisoes(int quantidade) {
	this->provisoesDrop = quantidade;
}

void Monstro::setItemDrop(Item &item) {
	delete this->itemDrop; //apaga a memória do item antigo, se houver. Evita memory leak
	this->itemDrop = new Item(item); //cria uma cópia nova e permanente do item na memória dinamica
}

void Monstro::setFugaPermitida(bool permitida) {
	this->fugaPermitida = permitida;
}