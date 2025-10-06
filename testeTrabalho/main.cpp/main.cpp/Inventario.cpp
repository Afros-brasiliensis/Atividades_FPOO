#include "Inventario.h"
#include <iostream>

Inventory::Inventory() : tesouro(0), provisoes(0) {}

void Inventory::adicionar(const Item& it) {
    itens.push_back(it);
}

bool Inventory::temItem(const std::string& nome) const {
    for (const auto& i : itens)
        if (i.nome == nome)
            return true;
    return false;
}

bool Inventory::remover(const std::string& nome) {
    for (size_t k = 0; k < itens.size(); ++k) {
        if (itens[k].nome == nome) {
            itens.erase(itens.begin() + k);
            return true;
        }
    }
    return false;
}

void Inventory::listar() const {
    std::cout << "\n--- Inventário ---\n";
    std::cout << "Tesouro: " << tesouro << " moedas\n";
    std::cout << "Provisões: " << provisoes << "\n";

    if (itens.empty()) {
        std::cout << "(sem itens)\n";
    }
    else {
        for (const auto& it : itens) {
            std::cout << "- " << it.nome
                << " [tipo=" << it.tipo
                << ", combate=" << (it.combate ? "sim" : "não")
                << ", FA=" << it.bonusFA
                << ", dano=" << it.bonusDano << "]\n";
        }
    }
}
