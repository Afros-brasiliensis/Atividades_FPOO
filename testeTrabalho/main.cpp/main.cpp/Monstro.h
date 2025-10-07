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
	bool isFugaPermitida();
	bool estaVivo(); //retorna true se energia > 0

	//M�todos de drop do monstro, caso derrotado
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
	Item* itemDrop; //ponteiro para mostrar que ele pode dropar um item ou n�o

	
};