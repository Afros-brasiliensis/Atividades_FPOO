#pragma once
#include <vector>
#include <string>
#include "Item.h"

class Inventory {
public:
    Inventory();

    void adicionar(const Item& it);
    bool temItem(const std::string& nome) const;
    bool remover(const std::string& nome);
    void listar() const;

    std::vector<Item> itens;
    int tesouro;
    int provisoes;
};
