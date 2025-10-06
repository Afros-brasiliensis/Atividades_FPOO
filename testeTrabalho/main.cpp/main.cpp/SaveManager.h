#pragma once
#include "Player.h"
#include <string>

class SaveManager {
public:
    bool salvar(const Player& p, int cenaAtual, const std::string& fname);
    bool carregar(Player& p, int& cenaAtual, const std::string& fname = "");
    bool listarSaves() const;
};
