#include "Batalha.h"
#include <iostream>
#include <random>
#include <limits>

static int randInt(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

int Battle::iniciarBatalha(Player& p, Monster& m) {
    std::cout << "\n=== BATALHA INICIADA ===\n";
    std::cout << "Voc� enfrenta um " << m.nome << "!\n";

    while (p.estaVivo() && m.energia > 0) {
        std::cout << "\nSua Energia: " << p.energia
            << " | Energia do inimigo: " << m.energia << "\n";
        std::cout << "1. Atacar\n2. Testar sorte\n3. Fugir\n4. Usar provis�o\nEscolha: ";

        int escolha;
        std::cin >> escolha;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (escolha == 4) { // usar provis�o
            p.usarProvisao();
            continue;
        }

        if (escolha == 3) { // tentar fugir
            int chance = randInt(1, 2);
            if (chance == 1) {
                std::cout << "Voc� conseguiu fugir da batalha!\n";
                return 0;
            }
            else {
                std::cout << "Voc� tentou fugir, mas o inimigo o alcan�ou!\n";
            }
        }

        if (escolha == 2) { // testar sorte
            bool sucesso = p.testarSorte();
            if (sucesso) {
                std::cout << "Voc� teve sorte! Causou dano extra!\n";
                m.energia -= 4;
            }
            else {
                std::cout << "Sua sorte falhou! Voc� foi atingido.\n";
                p.receberDano(3);
            }
        }

        if (escolha == 1) { // ataque normal
            int faPlayer = p.atacarFA();
            int faMonster = m.atacarFA();

            std::cout << "FA Jogador = " << faPlayer
                << " | FA Monstro = " << faMonster << "\n";

            if (faPlayer > faMonster) {
                int dano = 2;
                // soma b�nus de armas
                for (const auto& it : p.inventario.itens)
                    if (it.tipo == 'w') dano += it.bonusDano;

                std::cout << "Voc� acerta e causa " << dano << " de dano!\n";
                m.energia -= dano;
            }
            else if (faPlayer < faMonster) {
                int dano = 2;
                // aplica redu��o de dano por armadura
                for (const auto& it : p.inventario.itens)
                    if (it.tipo == 'r') dano -= it.bonusDano;
                if (dano < 0) dano = 0;

                std::cout << "O inimigo te acerta e causa " << dano << " de dano!\n";
                p.receberDano(dano);
            }
            else {
                std::cout << "Ambos erraram o ataque!\n";
            }
        }
    }

    if (m.energia <= 0) {
        std::cout << "\n=== Vit�ria! ===\n";
        std::cout << "Voc� derrotou o " << m.nome << "!\n";

        // recompensas
        if (m.tesouro > 0) {
            p.inventario.tesouro += m.tesouro;
            std::cout << "+ " << m.tesouro << " moedas de ouro\n";
        }

        if (m.provisoes > 0) {
            p.inventario.provisoes += m.provisoes;
            std::cout << "+ " << m.provisoes << " provis�es\n";
        }

        if (!m.itemDrop.nome.empty()) {
            p.inventario.adicionar(m.itemDrop);
            std::cout << "Voc� obteve o item: " << m.itemDrop.nome << "\n";
        }

        return 1; // vit�ria
    }

    if (!p.estaVivo()) {
        std::cout << "\nVoc� foi derrotado...\n";
        return 0;
    }

    return 0;
}
