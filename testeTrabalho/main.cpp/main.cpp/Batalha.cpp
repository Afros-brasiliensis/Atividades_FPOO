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
    std::cout << "Você enfrenta um " << m.nome << "!\n";

    while (p.estaVivo() && m.energia > 0) {
        std::cout << "\nSua Energia: " << p.energia
            << " | Energia do inimigo: " << m.energia << "\n";
        std::cout << "1. Atacar\n2. Testar sorte\n3. Fugir\n4. Usar provisão\nEscolha: ";

        int escolha;
        std::cin >> escolha;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (escolha == 4) { // usar provisão
            p.usarProvisao();
            continue;
        }

        if (escolha == 3) { // tentar fugir
            int chance = randInt(1, 2);
            if (chance == 1) {
                std::cout << "Você conseguiu fugir da batalha!\n";
                return 0;
            }
            else {
                std::cout << "Você tentou fugir, mas o inimigo o alcançou!\n";
            }
        }

        if (escolha == 2) { // testar sorte
            bool sucesso = p.testarSorte();
            if (sucesso) {
                std::cout << "Você teve sorte! Causou dano extra!\n";
                m.energia -= 4;
            }
            else {
                std::cout << "Sua sorte falhou! Você foi atingido.\n";
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
                // soma bônus de armas
                for (const auto& it : p.inventario.itens)
                    if (it.tipo == 'w') dano += it.bonusDano;

                std::cout << "Você acerta e causa " << dano << " de dano!\n";
                m.energia -= dano;
            }
            else if (faPlayer < faMonster) {
                int dano = 2;
                // aplica redução de dano por armadura
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
        std::cout << "\n=== Vitória! ===\n";
        std::cout << "Você derrotou o " << m.nome << "!\n";

        // recompensas
        if (m.tesouro > 0) {
            p.inventario.tesouro += m.tesouro;
            std::cout << "+ " << m.tesouro << " moedas de ouro\n";
        }

        if (m.provisoes > 0) {
            p.inventario.provisoes += m.provisoes;
            std::cout << "+ " << m.provisoes << " provisões\n";
        }

        if (!m.itemDrop.nome.empty()) {
            p.inventario.adicionar(m.itemDrop);
            std::cout << "Você obteve o item: " << m.itemDrop.nome << "\n";
        }

        return 1; // vitória
    }

    if (!p.estaVivo()) {
        std::cout << "\nVocê foi derrotado...\n";
        return 0;
    }

    return 0;
}
