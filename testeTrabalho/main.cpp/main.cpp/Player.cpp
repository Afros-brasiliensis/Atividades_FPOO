#include "Player.h"
#include <iostream>
#include <random>
#include <limits>

static int randInt(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

Player::Player()
    : nome(""), habilidade(6), energia(12), sorte(6), mago(false), vivo(true) {
}

Player::Player(const std::string& n)
    : nome(n), habilidade(6), energia(12), sorte(6), mago(false), vivo(true) {
}

void Player::distribuirPontosManual() {
    // Definindo as constantes (mínimo e o total de pontos extras)
    const int PONTOS_BASE_HABILIDADE = 6;
    const int PONTOS_BASE_ENERGIA = 12;
    const int PONTOS_BASE_SORTE = 6;
    const int PONTOS_TOTAIS_EXTRAS = 12; // Os 12 pontos para distribuir acima dos mínimos

    int habilidade, energia, sorte;

    std::cout << "Você tem " << PONTOS_TOTAIS_EXTRAS << " pontos para distribuir." << std::endl;
    std::cout << "As bases (mínimos) dos seus atributos já são:" << std::endl;
    std::cout << "   Habilidade: " << PONTOS_BASE_HABILIDADE << " (Max 12)" << std::endl;
    std::cout << "   Energia: " << PONTOS_BASE_ENERGIA << " (Max 24)" << std::endl;
    std::cout << "   Sorte: " << PONTOS_BASE_SORTE << " (Max 12)" << "\n" << std::endl;

    while (true) {
        std::cout << "--- Digite os VALORES FINAIS dos atributos ---" << std::endl;

        std::cout << "Digite Habilidade (6-12): ";
        std::cin >> habilidade;

        std::cout << "Digite Energia (12-24): ";
        std::cin >> energia;

        std::cout << "Digite Sorte (6-12): ";
        std::cin >> sorte;

        // Limpa o buffer para evitar problemas na próxima iteração
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // 1. VALIDAÇÃO DOS LIMITES MÍNIMO E MÁXIMO
        // Verifica se os valores inseridos pelo usuário estão dentro dos limites estabelecidos
        bool limites_validos = (habilidade >= 6 && habilidade <= 12) &&
            (energia >= 12 && energia <= 24) &&
            (sorte >= 6 && sorte <= 12);

        if (!limites_validos) {
            std::cout << "\n[ERRO DE LIMITE] Distribuição inválida. Um ou mais valores estão fora do intervalo (ex: Habilidade deve ser 6-12)." << "\n" << std::endl;
            continue; // Volta para o início do loop
        }

        // 2. CÁLCULO DA SOMA DOS PONTOS EXTRAS
        // Calcula quantos pontos extras (acima do mínimo) foram usados
        int pontos_extras_usados = (habilidade - PONTOS_BASE_HABILIDADE) +
            (energia - PONTOS_BASE_ENERGIA) +
            (sorte - PONTOS_BASE_SORTE);

        // 3. VALIDAÇÃO DA SOMA TOTAL
        if (pontos_extras_usados == PONTOS_TOTAIS_EXTRAS) {
            // Se as entradas estiverem nos limites E a soma dos pontos extras for 12
            // Atribua os valores finais à classe Player (aqui é só um exemplo)
            // this->habilidade = habilidade;
            // this->energia = energia;
            // this->sorte = sorte;
            std::cout << "\nDistribuição VÁLIDA! " << PONTOS_TOTAIS_EXTRAS << "/12 pontos usados." << "\n" << std::endl;
            break; // Sai do loop
        }
        else {
            // Caso a soma dos pontos extras não seja 12
            std::cout << "\n[ERRO DE PONTOS] Distribuição inválida. Você usou " << pontos_extras_usados
                << " dos " << PONTOS_TOTAIS_EXTRAS << " pontos disponíveis. Tente novamente." << "\n" << std::endl;
        }
    }


    std::cout << "Deseja ser mago? (1 = Sim, 0 = Não): ";
    int x;
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    mago = (x == 1);
}

void Player::distribuirPontosAleatorio() {
    habilidade = 6 + randInt(0, 6); // 6..12
    energia = 12 + randInt(0, 12);  // 12..24
    sorte = 6 + randInt(0, 6);      // 6..12

    std::cout << "Distribuição aleatória: "
        << "H=" << habilidade << " E=" << energia << " S=" << sorte << "\n";

    std::cout << "Deseja ser mago? (1 = Sim, 0 = Não): ";
    int x;
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    mago = (x == 1);
}

bool Player::testarSorte() {
    int roll = randInt(1, 12);
    bool sucesso = (roll <= sorte);
    sorte = std::max(0, sorte - 1);
    std::cout << "Teste de sorte: rolou " << roll
        << " contra S=" << (sorte + 1)
        << " -> " << (sucesso ? "SUCESSO" : "FALHA") << "\n";
    return sucesso;
}

void Player::usarProvisao() {
    if (inventario.provisoes > 0) {
        inventario.provisoes--;
        energia += 4;
        std::cout << "Você usou uma provisão. Energia atual: " << energia << "\n";
    }
    else {
        std::cout << "Você não possui provisões.\n";
    }
}

void Player::receberDano(int d) {
    energia -= d;
    if (energia <= 0) {
        vivo = false;
        energia = 0;
    }
}

bool Player::estaVivo() const {
    return vivo;
}

void Player::mostrarInventario() const {
    inventario.listar();
    std::cout << "Atributos -> "
        << "H:" << habilidade
        << " E:" << energia
        << " S:" << sorte
        << (mago ? " (Mago)\n" : "\n");
}

int Player::atacarFA() const {
    int base = randInt(1, 10) + habilidade;

    for (const auto& it : inventario.itens)
        if (it.tipo == 'w') // arma
            base += it.bonusFA;
    return base;
}
