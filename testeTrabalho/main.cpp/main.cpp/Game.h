#pragma once
#include <string>
#include "Player.h"
#include "Cena.h"
#include "SaveManager.h"
#include "Batalha.h"

class Game {
public:
    Game();
    void run(); // ponto de entrada principal do jogo

private:
    Player player;
    Scene currentScene;
    SaveManager saver;

    void menuInicial();
    void novoJogo();
    void carregarJogo();
    void credits();
    void carregarCena(int id);
};
