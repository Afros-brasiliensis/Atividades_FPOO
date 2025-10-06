#include "Cena.h"
#include "Item.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

static std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

Scene::Scene()
    : id(0), texto(""), is_monster(false),
    next_win(-1), next_lose(-1) {
}

bool Scene::carregarCenaFromFile(int id_) {
    id = id_;
    std::string fname = "scenes/" + std::to_string(id) + ".txt";
    std::ifstream f(fname);
    if (!f.is_open()) {
        std::cout << "Erro ao abrir arquivo de cena: " << fname << "\n";
        return false;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(f, line)) lines.push_back(line);
    f.close();

    texto.clear();
    opcoesIds.clear();
    is_monster = false;
    next_win = next_lose = -1;

    if (lines.empty()) return false;

    size_t idx = 0;
    // verifica se é cena de monstro
    if (trim(lines[0]) == "m") {
        is_monster = true;
        idx = 1;
    }

    // lê o texto descritivo
    for (; idx < lines.size(); ++idx) {
        std::string l = trim(lines[idx]);
        if (l.empty()) continue;

        // se detectar início de parâmetros (N:, H:, etc.), interrompe leitura do texto
        if (l.rfind("N:", 0) == 0 || l.rfind("H:", 0) == 0 || l.rfind("S:", 0) == 0 ||
            l.rfind("E:", 0) == 0 || l.rfind("T:", 0) == 0 || l.rfind("P:", 0) == 0 ||
            l.rfind("I:", 0) == 0)
            break;

        texto += l + "\n";
    }

    // se for monstro, lê parâmetros
    for (; idx < lines.size(); ++idx) {
        std::string t = trim(lines[idx]);
        if (t.empty()) continue;

        if (t.rfind("N:", 0) == 0) monster.nome = trim(t.substr(2));
        else if (t.rfind("H:", 0) == 0) monster.habilidade = std::stoi(trim(t.substr(2)));
        else if (t.rfind("S:", 0) == 0) monster.sorte = std::stoi(trim(t.substr(2)));
        else if (t.rfind("E:", 0) == 0) monster.energia = std::stoi(trim(t.substr(2)));
        else if (t.rfind("T:", 0) == 0) monster.tesouro = std::stoi(trim(t.substr(2)));
        else if (t.rfind("P:", 0) == 0) monster.provisoes = std::stoi(trim(t.substr(2)));
        else if (t.rfind("I:", 0) == 0) {
            std::string rest = trim(t.substr(2));
            item = Item::parseFromString(rest);
            monster.itemDrop = item;
        }
        else {
            // caso 12;13 (vitória;derrota)
            size_t semi = t.find(';');
            if (semi != std::string::npos) {
                next_win = std::stoi(trim(t.substr(0, semi)));
                next_lose = std::stoi(trim(t.substr(semi + 1)));
            }
        }
    }

    // se não for monstro, tenta ler opções (#2:, 1:, etc.)
    if (!is_monster) {
        for (auto& l : lines) {
            std::string s = trim(l);
            if (s.empty()) continue;

            // formato “#2: Texto” ou “1: Texto”
            if (s[0] == '#') {
                size_t pos = 1;
                while (pos < s.size() && isdigit(s[pos])) pos++;
                int id = std::stoi(s.substr(1, pos - 1));
                opcoesIds.push_back(id);
            }
            else if (isdigit(s[0])) {
                size_t pos = 0;
                while (pos < s.size() && isdigit(s[pos])) pos++;
                if (pos < s.size() && s[pos] == ':') {
                    int id = std::stoi(s.substr(0, pos));
                    opcoesIds.push_back(id);
                }
            }
        }
    }

    return true;
}

void Scene::mostrarCena() const {
    std::cout << "\n--- Cena " << id << " ---\n";
    std::cout << texto << "\n";

    if (is_monster) {
        std::cout << "** Monstro: " << monster.nome
            << " (H=" << monster.habilidade
            << " E=" << monster.energia
            << " S=" << monster.sorte << ")\n";
        std::cout << "1. Atacar\n2. Fugir\n3. Usar item\n";
    }
    else {
        if (opcoesIds.empty())
            std::cout << "(Sem opções disponíveis)\n";
        else {
            for (size_t i = 0; i < opcoesIds.size(); ++i)
                std::cout << i + 1 << ". Ir para cena " << opcoesIds[i] << "\n";
        }
        std::cout << "0. Abrir inventário / salvar\n";
    }
}

int Scene::lerEscolha() const {
    int c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (!is_monster) {
        if (c == 0) return -1; // abrir inventário
        if (c >= 1 && (size_t)c <= opcoesIds.size())
            return c;
        return 1;
    }

    // se for cena de monstro
    if (c >= 1 && c <= 3) return c;
    return 1;
}

int Scene::executarEscolha(int escolhaIndex, Player& player) {
    if (is_monster) return -1; // controlado pela tela de batalha
    int idx = escolhaIndex - 1;
    if (idx < 0 || (size_t)idx >= opcoesIds.size()) return -1;
    return opcoesIds[idx];
}
