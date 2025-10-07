#pragma once
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Personagem {
public: 
	Personagem();
	Personagem(int habilidade, int energia, int sorte);
	~Personagem();

	void tomarDano(int dano);
	void curar(int cura);
	int getHabilidade(); 
	int getEnergia();
	bool usarSorte(); //tenta usar a sorte, retornando true se conseguir
	int getSorte(); 

	//Métodos para funcionamento do inventário
	void adicionarItem(Item &item);
	void usarProvisao(); //recupera 4 pontos de vida
	void adicionarTesouro(int valor);
	void mostrarInventario();

private: 
	int habilidade; 
	int energia;
	int sorte; 
	int tesouro; //valor númerico, como moedas de ouro 
	int provisoes; //número de provisões
	vector<Item> inventario; //itens do personagem, o vetor armazena itens do tipo Item e aloca dinamincamente

};