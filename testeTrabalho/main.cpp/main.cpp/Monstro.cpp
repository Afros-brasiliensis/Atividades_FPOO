#include "Monstro.h"
#include <random>

static int randIntStatic(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

Monster::Monster()
    : nome(""), habilidade(6), energia(10), sorte(6),
    tesouro(0), provisoes(0), itemDrop() {
}

int Monster::atacarFA() const {
    return randIntStatic(1, 10) + habilidade;
}
