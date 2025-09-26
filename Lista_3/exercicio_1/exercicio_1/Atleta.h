#pragma once
#include <string>
#include <iostream>

class Atleta {
private:
    std::string nome;
    int idade;

public:
    Atleta(const std::string& nome, int idade);
    virtual ~Atleta() = default;

    std::string getNome() const;
    int getIdade() const;

    virtual void imprime_info() const;
};