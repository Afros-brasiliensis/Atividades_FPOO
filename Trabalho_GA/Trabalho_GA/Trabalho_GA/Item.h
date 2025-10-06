#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

enum class ItemType {COMUM, WEAPON, ARMADURA, MAGIA, CONSUMIVEL};

struct Item {

		//Atributos
		string nome;
		ItemType tipo;
		bool usavelEmCombate;
		int ForcaAtaque; 
		int BonusDano;

		Item(); //Construtor sem parâmetros
		Item(const string &n, ItemType t, bool usavel, int fa = 0, int dmg = 0);//Construtor com parametros

		static string typeToString(ItemType t); //Converte ItemType para string
		static ItemType charToType(char c); //Converte char para ItemType
		string toString() const;
}