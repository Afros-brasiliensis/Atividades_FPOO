#include "Item.h"

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

	string desc = nome	+ " [" + typeToString(tipo) + "]";

	if (ForcaAtaque != 0) {
		desc += " | FA: ";
		desc += ( ForcaAtaque > 0 ? "+" : "");
		desc += to_string(ForcaAtaque);
	}

	if (BonusDano != 0) {
		desc += " | Dano: ";
		desc += (BonusDano > 0 ? "+" : "");
		desc += to_string(BonusDano);
	}

	if (usavelEmCombate) {
		desc += " | (Usável em combate)";
	}

	return desc;

}