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

	//Métodos para acessar as informações do monstro combatido
	string getNome();
	int getHabilidade();
	int getEnergia();

	//Métodos de drop do monstro, caso derrotado
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
	Item* itemDrop; //ponteiro para mostrar que ele pode dropar um item ou não

	
};