#pragma once
#include <string>
#include "Item.h"

class Monster {
public:
    Monster();

    std::string nome;
    int habilidade;
    int energia;
    int sorte;
    int tesouro;
    int provisoes;
    Item itemDrop; // item que o monstro pode dropar

    int atacarFA() const; // calcula Força de Ataque (1d10 + habilidade)
};
