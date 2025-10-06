#pragma once
#include <string>
#include <vector>
#include "Monstro.h"
#include "Player.h"

// Cada arquivo de cena (.txt) � lido e interpretado por esta classe
class Scene {
public:
    Scene();

    int id;
    std::string texto;
    std::vector<int> opcoesIds;  // IDs das pr�ximas cenas
    bool is_monster;             // define se � cena de combate
    Monster monster;             // se for cena de monstro
    Item item;                   // item encontrado, se houver
    int next_win;                // pr�xima cena em caso de vit�ria
    int next_lose;               // pr�xima cena em caso de derrota

    bool carregarCenaFromFile(int id);
    void mostrarCena() const;
    int lerEscolha() const;                   // retorna -1 para invent�rio
    int executarEscolha(int escolhaIndex, Player& player);

    int nextOnWin() const { return next_win; }
    int nextOnLose() const { return next_lose; }
};
