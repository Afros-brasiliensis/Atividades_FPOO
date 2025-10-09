#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Monstro.h"
using namespace std;

class Cena {
public:
	Cena() :
		textoPrincipal(""),
		item(nullptr),
		inimigo(nullptr),
		cenaVitoria(0),
		cenaDerrota(0)
	{
	}

	~Cena() {
		delete item;
		delete inimigo;
	}
	
	bool carregar(int numeroCena); //para carregar a cena a partir de um arquivo

	//M�todos para obter as informa��es da cena
	string getTexto(); 
	bool isCenaDeCombate();
	Monstro* getInimigo(); 
	int getCenaVitoria(); //retornam o n�mero da pr�xima cena em caso de vit�ria ou derrota
	int getCenaDerrota();
	Item* getItem(); //retorna o item encontrado na cena se tiver

	//Escolhas
	const vector<string>& getTextoEscolhas();
	const vector<int>& getCenasDestino(); 

private: 

	string textoPrincipal;
	Item* item; //os ponteiros nesse caso servem para entender o que h� ou n�o na cena
	Monstro* inimigo; //exemplo: se o ponteiro for nulo, n�o h� um inimigo na cena e ela � de explora��o

	vector<string> textoEscolhas;
	vector<int> cenasDestino; //n�meros das cenas destino para cada escolha

	int cenaVitoria; //n�mero da cena para onde ir em caso de vit�ria no combate
	int cenaDerrota;

};