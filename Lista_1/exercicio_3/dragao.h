#pragma once

#include <iostream>
#include <string>

using namespace std;

enum tipoDragao { Solar, Lunar, Gelo, Fogo, Marinho, Tempestade, Sombras, Terra, Guardiao, Celestial };

class Dragao {
private:
	string nome;
	string cor;
	string poder;
	string reino;
	int idade;

public:

	//Construtor
	Dragao();
	//Construtor com parâmetros
	Dragao(string nome, string cor, string poder, string reino, string tipo, int idade);
	//Destrutor
	~Dragao();

	//Setters

	void setNome(string nome);
	void setCor(string cor);
	void setPoder(string poder);
	void setReino(string reino);
	void setTipo(string tipo);
	void setIdade(int idade);

	//Getters

	string getNome();
	string getCor();
	string getPoder();
	string getReino();
	string getTipo();
	int getIdade();

	//Imprimir informacoes do dragao

	void imprime_info();

	//Descobre se o dragao eh jovem

	bool eh_jovem();