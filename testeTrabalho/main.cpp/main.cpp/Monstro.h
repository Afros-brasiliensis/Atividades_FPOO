#pragma once
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Monstro {
public:
	
	Monstro();
	Monstro(string nome, int habilidade, int energia);
	~Monstro(); 

	//M�todos para acessar as informa��es do monstro combatido
	string getNome();
	int getHabilidade();
	int getEnergia();

	//M�todos de drop do monstro, caso derrotado
	void setTesouro(int valor); 
	void setProvisoes(int quantidade);
	void setItemDrop(Item &item);

private: 
	string nome;
	int habilidade;
	int energia;

	//itens se ele for morto
	int tesouroDrop; 
	int provisoesDrop;
	Item* itemDrop; //ponteiro para mostrar que ele pode dropar um item ou n�o

	
};