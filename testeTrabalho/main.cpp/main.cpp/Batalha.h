#pragma once
#include "Player.h"
#include "Monstro.h"

// Classe responsável por resolver os combates
class Battle {
public:
    // Retorna:
    //  1 → vitória do jogador
    //  0 → derrota ou fuga
    int iniciarBatalha(Player& p, Monster& m);
};
