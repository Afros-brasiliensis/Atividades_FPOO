#include "SaveManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#if defined(_WIN32)
#include <windows.h>
#else
#include <dirent.h>
#endif

bool SaveManager::salvar(const Player& p, int cenaAtual, const std::string& fname) {
    std::ofstream f(fname);
    if (!f.is_open()) return false;

    f << "NOME:" << p.nome << "\n";
    f << "HABILIDADE:" << p.habilidade << "\n";
    f << "ENERGIA:" << p.energia << "\n";
    f << "SORTE:" << p.sorte << "\n";
    f << "TESOURO:" << p.inventario.tesouro << "\n";
    f << "PROVISOES:" << p.inventario.provisoes << "\n";
    f << "CENA_ATUAL:" << cenaAtual << "\n";

    // Salva todos os itens em uma linha
    f << "ITENS:";
    for (size_t i = 0; i < p.inventario.itens.size(); ++i) {
        const auto& it = p.inventario.itens[i];
        f << it.nome << ";" << it.tipo << ";" << (it.combate ? "1" : "0")
            << ";" << it.bonusFA << ";" << it.bonusDano;
        if (i + 1 < p.inventario.itens.size()) f << ",";
    }
    f << "\n";

    f.close();
    std::cout << "Jogo salvo em " << fname << "!\n";
    return true;
}

bool SaveManager::carregar(Player& p, int& cenaAtual, const std::string& fname) {
    std::string caminho = fname;
    if (caminho.empty()) caminho = "data/saves/save1.txt";

    std::ifstream f(caminho);
    if (!f.is_open()) {
        std::cout << "Arquivo de save não encontrado: " << caminho << "\n";
        return false;
    }

    std::string linha;
    while (std::getline(f, linha)) {
        if (linha.rfind("NOME:", 0) == 0) p.nome = linha.substr(5);
        else if (linha.rfind("HABILIDADE:", 0) == 0) p.habilidade = std::stoi(linha.substr(11));
        else if (linha.rfind("ENERGIA:", 0) == 0) p.energia = std::stoi(linha.substr(8));
        else if (linha.rfind("SORTE:", 0) == 0) p.sorte = std::stoi(linha.substr(6));
        else if (linha.rfind("TESOURO:", 0) == 0) p.inventario.tesouro = std::stoi(linha.substr(8));
        else if (linha.rfind("PROVISOES:", 0) == 0) p.inventario.provisoes = std::stoi(linha.substr(10));
        else if (linha.rfind("CENA_ATUAL:", 0) == 0) cenaAtual = std::stoi(linha.substr(11));
        else if (linha.rfind("ITENS:", 0) == 0) {
            std::string data = linha.substr(6);
            std::stringstream ss(data);
            std::string itemStr;
            p.inventario.itens.clear();
            while (std::getline(ss, itemStr, ',')) {
                if (!itemStr.empty()) {
                    p.inventario.itens.push_back(Item::parseFromString(itemStr));
                }
            }
        }
    }

    f.close();
    p.vivo = true;
    std::cout << "Jogo carregado de " << caminho << "!\n";
    return true;
}

bool SaveManager::listarSaves() const {
    std::string dir = "data/saves/";
    bool encontrou = false;

#if defined(_WIN32)
    WIN32_FIND_DATAA fd;
    HANDLE hFind = FindFirstFileA((dir + "*.txt").c_str(), &fd);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                std::cout << " - " << fd.cFileName << "\n";
                encontrou = true;
            }
        } while (FindNextFileA(hFind, &fd));
        FindClose(hFind);
    }
#else
    DIR* dp = opendir(dir.c_str());
    if (dp) {
        struct dirent* entry;
        while ((entry = readdir(dp)) != nullptr) {
            std::string fname = entry->d_name;
            if (fname.size() > 4 && fname.substr(fname.size() - 4) == ".txt") {
                std::cout << " - " << fname << "\n";
                encontrou = true;
            }
        }
        closedir(dp);
    }
#endif

    if (!encontrou)
        std::cout << "(Nenhum arquivo de save encontrado)\n";

    return encontrou;
}
