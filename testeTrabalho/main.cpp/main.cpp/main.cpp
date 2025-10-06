#include <iostream>
#include "Game.h"

int main() {
    std::cout << "=====================================\n";
    std::cout << "      InteractiveBook RPG (v1.0)\n";
    std::cout << "=====================================\n\n";

    Game game;
    game.run();

    std::cout << "\nObrigado por jogar!\n";
    return 0;
}
