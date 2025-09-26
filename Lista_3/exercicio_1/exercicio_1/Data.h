#pragma once
#include <iostream>

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano);

    int getDia() const;
    int getMes() const;
    int getAno() const;

    void imprime_data() const;
};