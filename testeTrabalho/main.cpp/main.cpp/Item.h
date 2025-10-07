#pragma once
#include <string>
using namespace std; 

class Item {
public: 
	Item();
	Item(string nome, char tipo, bool combate, int fa, int dano);
	~Item();

	string getNome();
	char getTipo();
	int getBonusForcaAtaque();
	int getBonusDano(); 

private: 
	string nome;
	char tipo; //'c' (comum), 'r' (armadura), 'w' (arma)
	bool podeUsarEmCombate; 
	int bonusForcaAtaque;
	int bonusDano;

};