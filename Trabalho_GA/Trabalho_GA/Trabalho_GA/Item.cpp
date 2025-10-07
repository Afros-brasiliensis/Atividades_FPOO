#include "Item.h"

Item::Item() 
    : nome(""), tipo(ItemType::COMUM), usavelEmCombate(false), ForcaAtaque(0), BonusDano(0) {}

// Construtor parametrizado
Item::Item(const std::string& n, ItemType t, bool usable, int fa, int dmg)
    : nome(n), tipo(t), usavelEmCombate(usable), ForcaAtaque(fa), BonusDano(dmg) {}

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

	string desc = nome + " [" + typeToString(tipo) + "]";

	if (ForcaAtaque != 0) {
		desc += " | FA: ";
		desc += (ForcaAtaque > 0 ? "+" : "");
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

string Item::getNome() const {
	return nome;
}

ItemType Item::getTipo() const {
	return tipo;
}

bool Item::isUsavelEmCombate() const {
	return usavelEmCombate;
}

int Item::getForcaAtaque() const {
	return ForcaAtaque;
}

int Item::getBonusDano() const {
	return BonusDano;
}
