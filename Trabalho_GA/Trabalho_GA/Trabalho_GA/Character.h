#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Personagem {

private: 
	
	//Atributos
	int habilidade;
	int energia;
	int sortea;
	

public:

	//Construtor
	Personagem();
	//Construtor com parametros
	Personagem(int habilidade, int energia, int sorte);
	//Destrutor
	~Personagem();
	
	//Metodos para obtenção de atributos
	int getHabilidade();
	int getEnergia();
	int getSorte();

	//Metodos para modificar atributos
	void setHabilidade(int habilidade);
	void setEnergia(int energia);
	void setSorte(int sorte);

	//Metodos de combate e inventario
	void testarSorte();
	


};

