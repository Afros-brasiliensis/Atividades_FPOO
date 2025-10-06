#include "Item.h"
#include <sstream>
using namespace std; 

//Construtor padrão, todo mundo zerado
Item::Item() : nome(""), tipo(ItemType::COMUM), usavelEmCombate(false), ForcaAtaque(0), BonusDano(0) {

}

//Construtor com parâmetros

Item::Item(const string& n, ItemType t, bool usavel, int fa, int dmg) : nome(n), tipo(t), usavelEmCombate(usavel), ForcaAtaque(fa), BonusDano(dmg) {

}

string Item::typeToString(ItemType t) {
	switch (t) {
		case ItemType::WEAPON: return "Arma";
		case ItemType::ARMADURA: return "Armadura";
		case ItemType::MAGIA: return "Magia";
		case ItemType::CONSUMIVEL: return "Consumivel";
		default : return "Comum";

	}
}
ItemType Item::charToType(char c) {
	switch (c) {
		case 'w' : return ItemType::WEAPON;
		case 'a' : return ItemType::ARMADURA;
		case 'm' : return ItemType::MAGIA;
		case 'c' : return ItemType::CONSUMIVEL;
		default: return ItemType::COMUM;

	}
}

string Item::toString() const {

	ostringstream out;
	out << nome << " | " << typeToString(tipo) " | ";
	if (ForcaAtaque != 0)
		out << "Forca de Ataque: " << (ForcaAtaque > 0 ? "+" : "") << ForcaAtaque;
	if (BonusDano != 0)
		out << " | Bonus de Dano: " << (BonusDano > 0 ? "+" : "") << BonusDano;
	if (usavelEmCombate)
		out << " | Usavel em Combate";
	return out.str();
}