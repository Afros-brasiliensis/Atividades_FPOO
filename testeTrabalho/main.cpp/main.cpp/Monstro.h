#pragma once
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Monstro {
public:
	
	Monstro() :
		nome(""),
		habilidade(0),
		energia(0),
		tesouroDrop(0),
		provisoesDrop(0),
		itemDrop(nullptr) //inicia como nulo, indicando que não há item drop
	{
	}
	Monstro(string nome, int habilidade, int energia);
	~Monstro() {
		delete itemDrop; //libera a memória alocada para o item, se houver
	}

	//Métodos para acessar as informações do monstro combatido
	string getNome();
	int getHabilidade();
	int getEnergia();
	bool isFugaPermitida();
	bool estaVivo(); //retorna true se energia > 0

	//Métodos de drop do monstro, caso derrotado
	void setTesouro(int valor); 
	void setProvisoes(int quantidade);
	void setItemDrop(Item &item);
	void setFugaPermitida(bool permitida);


private: 
	string nome;
	int habilidade;
	int energia;
	bool fugaPermitida = true;

	//itens se ele for morto
	int tesouroDrop; 
	int provisoesDrop;
	Item* itemDrop; //ponteiro para mostrar que ele pode dropar um item ou não

	
};