#pragma once
#include <string>

struct Item {
    std::string nome;
    char tipo; // 'c' = comum, 'r' = armadura, 'w' = arma
    bool combate; // pode ser usado em combate?
    int bonusFA;  // b�nus de For�a de Ataque (positivo/negativo)
    int bonusDano; // b�nus/redu��o de dano (positivo/negativo)

    Item();
    Item(const std::string& n, char t, bool c, int fa, int dano);
    static Item parseFromString(const std::string& s); // formato: nome;tipo;combate;FA;dano
};
