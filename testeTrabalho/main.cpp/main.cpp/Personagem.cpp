#include "Personagem.h" 
#include <iostream> 
#include <random> //para usar sorte
using namespace std;

Personagem::Personagem(string nome, int habilidade, int energia, int sorte) :
	nome(nome),
	habilidade(habilidade),
	energia(energia),
	sorte(sorte),
	tesouro(0),       // Comeca com 0 de tesouro
	provisoes(2),     // Comeca com 2 provisoes (pode ajustar)
	armaEquipada(nullptr),
	armaduraEquipada(nullptr)
{
}