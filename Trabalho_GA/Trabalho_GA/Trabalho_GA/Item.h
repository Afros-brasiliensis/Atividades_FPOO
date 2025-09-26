#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

class Item {

	private: 

		//Atributos
		string nome;
		bool equipado;
		char tipo; //arma, armadura, consumivel, artefato - w = arma, a = armadura, c = consumivel, art = artefato
		char raridade; //comum, raro, épico, lendário, mítico
	//Construtor
		Item();
		//Construtor com parametros
		Item(string n, bool equipado, char tipo, char raridade);

}