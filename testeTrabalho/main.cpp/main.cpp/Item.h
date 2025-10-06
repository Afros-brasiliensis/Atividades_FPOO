#pragma once
#include <string>

struct Item {
    std::string nome;
    char tipo; // 'c' = comum, 'r' = armadura, 'w' = arma
    bool combate; // pode ser usado em combate?
    int bonusFA;  // bônus de Força de Ataque (positivo/negativo)
    int bonusDano; // bônus/redução de dano (positivo/negativo)

    Item();
    Item(const std::string& n, char t, bool c, int fa, int dano);
    static Item parseFromString(const std::string& s); // formato: nome;tipo;combate;FA;dano
};
