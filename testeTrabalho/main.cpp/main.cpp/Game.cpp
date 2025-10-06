#include "Game.h"
#include <iostream>
#include <limits>

Game::Game() {}

static int readInt() {
    int x;
    while (!(std::cin >> x)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Digite novamente: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return x;
}

void Game::run() {
    menuInicial();
}

void Game::menuInicial() {
    while (true) {
        std::cout << "\n=== InteractiveBook ===\n";
        std::cout << "1. Novo Jogo\n";
        std::cout << "2. Carregar Jogo\n";
        std::cout << "3. Créditos\n";
        std::cout << "4. Sair\n";
        std::cout << "Escolha: ";

        int opt = readInt();

        if (opt == 1) {
            novoJogo();
        }
        else if (opt == 2) {
            carregarJogo();
        }
        else if (opt == 3) {
            credits();
        }
        else if (opt == 4) {
            std::cout << "Encerrando o jogo...\n";
            break;
        }
        else {
            std::cout << "Opção inválida.\n";
        }
    }
}

void Game::novoJogo() {
    std::cout << "\nDigite o nome do personagem: ";
    std::string nome;
    std::getline(std::cin, nome);

    player = Player(nome);

    std::cout << "Escolha o modo de criação:\n";
    std::cout << "1. Distribuir pontos manualmente\n";
    std::cout << "2. Aleatório\n";
    std::cout << "Escolha: ";
    int modo = readInt();

    if (modo == 1) player.distribuirPontosManual();
    else player.distribuirPontosAleatorio();

    carregarCena(1);

    while (player.estaVivo()) {
        currentScene.mostrarCena();

        if (currentScene.is_monster) {
            // batalha
            Battle batalha;
            int resultado = batalha.iniciarBatalha(player, currentScene.monster);

            if (resultado == 1) {
                carregarCena(currentScene.nextOnWin());
            }
            else {
                if (!player.estaVivo()) {
                    std::cout << "Você morreu! Game over.\n";
                    break;
                }
                carregarCena(currentScene.nextOnLose());
            }
        }
        else {
            int escolha = currentScene.lerEscolha();

            if (escolha == -1) { // inventário
                player.mostrarInventario();
                std::cout << "Deseja salvar o jogo? (1 = sim, 0 = não): ";
                int salvar;
                salvar = readInt();
                if (salvar == 1) {
                    saver.salvar(player, currentScene.id, "data/saves/save1.txt");
                }
                continue;
            }

            int proxima = currentScene.executarEscolha(escolha, player);
            if (proxima <= 0) {
                std::cout << "Fim da história.\n";
                break;
            }

            saver.salvar(player, currentScene.id, "data/saves/save1.txt");
            carregarCena(proxima);
        }
    }

    std::cout << "Jogo encerrado.\n";
}

void Game::carregarJogo() {
    std::cout << "\n=== Carregar Jogo ===\n";
    if (!saver.listarSaves()) {
        std::cout << "Nenhum save encontrado.\n";
        return;
    }

    std::cout << "Digite o nome do save (ex: save1.txt): ";
    std::string fname;
    std::getline(std::cin, fname);

    int cena = 1;
    if (saver.carregar(player, cena, "data/saves/" + fname)) {
        std::cout << "Save carregado!\n";
        carregarCena(cena);
    }
    else {
        std::cout << "Falha ao carregar o save.\n";
    }
}

void Game::credits() {
    std::cout << "\n=== Créditos ===\n";
    std::cout << "Trabalho Prático Grau A - Programação Orientada a Objetos\n";
    std::cout << "Desenvolvido por: Athos Kolling\n";
    std::cout << "Baseado na série 'Aventuras Fantásticas'\n";
}

void Game::carregarCena(int id) {
    if (!currentScene.carregarCenaFromFile(id)) {
        std::cout << "Falha ao carregar cena " << id << ".\n";
    }
}
