#include "Item.h"
#include <sstream>
#include <vector>
#include <stdexcept>

Item::Item() : nome(""), tipo('c'), combate(false), bonusFA(0), bonusDano(0) {}
Item::Item(const std::string& n, char t, bool c, int fa, int dano)
    : nome(n), tipo(t), combate(c), bonusFA(fa), bonusDano(dano) {
}

static std::vector<std::string> split(const std::string& s, char sep) {
    std::vector<std::string> out;
    std::string cur;
    for (char ch : s) {
        if (ch == sep) {
            out.push_back(cur);
            cur.clear();
        }
        else cur.push_back(ch);
    }
    out.push_back(cur);
    return out;
}

Item Item::parseFromString(const std::string& s) {
    // esperado: nome;tipo;combate;FA;dano
    auto parts = split(s, ';');
    std::string nome = parts.size() > 0 ? parts[0] : "";
    char tipo = 'c';
    if (parts.size() > 1 && !parts[1].empty()) tipo = parts[1][0];

    bool combate = false;
    if (parts.size() > 2) {
        std::string c = parts[2];
        combate = (c != "0" && c != "false");
    }

    int fa = 0;
    int dano = 0;
    try {
        if (parts.size() > 3 && !parts[3].empty()) fa = std::stoi(parts[3]);
    }
    catch (const std::exception&) { fa = 0; }

    try {
        if (parts.size() > 4 && !parts[4].empty()) dano = std::stoi(parts[4]);
    }
    catch (const std::exception&) { dano = 0; }

    return Item(nome, tipo, combate, fa, dano);
}
