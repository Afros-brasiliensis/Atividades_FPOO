#pragma once
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Personagem {
public: 
	
	Personagem();
	Personagem(string nome, int habilidade, int energia, int sorte);
	~Personagem();

	string getNome();
	void tomarDano(int dano);
	void curar(int cura);
	int getHabilidade(); 
	int getEnergia();
	bool usarSorte(); //tenta usar a sorte, retornando true se conseguir
	int getSorte(); 
	bool estaVivo(); //retorna true se energia > 0
	int getTesouro();
	int getProvisoes();
	int getBonusForcaAtaque();
	int getBonusDano();
	void equiparArma(int indiceDoInventario); 
	void desequiparArma();
	vector<Item> getInventario();

	//M�todos para funcionamento do invent�rio
	void adicionarItem(Item &item);
	void adicionarProvisao(int quantidade);
	void usarProvisao(); //recupera 4 pontos de vida
	void adicionarTesouro(int valor);
	void mostrarInventario();
	

private: 
	
	string nome;
	int habilidade; 
	int energia;
	int sorte; 
	int tesouro; //valor n�merico, como moedas de ouro 
	int provisoes; //n�mero de provis�es
	int armaEquipada; 
	int energiaMaxima;
	vector<Item> inventario; //itens do personagem, o vetor armazena itens do tipo Item e aloca dinamincamente

};