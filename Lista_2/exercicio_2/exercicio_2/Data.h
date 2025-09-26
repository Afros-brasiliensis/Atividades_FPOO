#pragma once

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano);
    void imprime() const;
};