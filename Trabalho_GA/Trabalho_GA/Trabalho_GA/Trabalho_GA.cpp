#include <iostream>
#include "Item.h"

int main() {
    Item espada("Espada Rúnica", ItemType::WEAPON, true, 0, 2);
    Item runa("Runa da Coragem", ItemType::MAGIA, false, 1, 0);
    Item comida("Provisao", ItemType::CONSUMIVEL, false, 0, 0);

    std::cout << espada.toString() << "\n";
    std::cout << runa.toString() << "\n";
    std::cout << comida.toString() << "\n";

    return 0;
}
