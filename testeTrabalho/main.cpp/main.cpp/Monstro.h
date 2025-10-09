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
		sorte(0),
		tesouroDrop(0),
		provisoesDrop(0),
		itemDrop(nullptr) //inicia como nulo, indicando que n�o h� item drop
	{
	}
	Monstro(string nome, int habilidade, int energia);
	~Monstro() {
		delete itemDrop; //libera a mem�ria alocada para o item, se houver
	}

	//M�todos para acessar as informa��es do monstro combatido
	string getNome();
	int getHabilidade();
	int getEnergia();
	bool isFugaPermitida();
	int getTesouro();
	Item* getItemDrop(); //retorna ponteiro para o item drop, ou nullptr se n�o houver
	bool estaVivo(); //retorna true se energia > 0
	int getSorte();

	//M�todos de drop do monstro, caso derrotado
	void setHabilidade(int valor);
	void setEnergia(int valor);
	void setNome(string nome);
	void setTesouro(int valor); 
	void setItemDrop(Item &item);
	void setProvisoes(int quantidade);
	void setSorte(int valor);
	void setFugaPermitida(bool permitida);
	void tomarDano(int dano); 


private: 
	string nome;
	int habilidade;
	int energia;
	bool fugaPermitida = true;
	int sorte;

	//itens se ele for morto
	int tesouroDrop; 
	int provisoesDrop;
	Item* itemDrop; //ponteiro para mostrar que ele pode dropar um item ou n�o	
};