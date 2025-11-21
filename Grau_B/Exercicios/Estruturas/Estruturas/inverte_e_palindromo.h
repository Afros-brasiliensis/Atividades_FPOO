#pragma once
#include <iostream>
#include "Pilhas.h"  
#include "Filas.h" 
#include "Listas.h"
#include <ctime>
#include <cstdlib>
#include <string>

//Exercicio 0 de aula: inverter uma palavra
string inverterPalavra(const string& palavra) {
    Pilha<char> pilha;
    for (int i = 0; i < palavra.size(); ++i) {
        pilha.push(palavra[i]);
    }
    string palavraInvertida = "";
    while (!pilha.isEmpty()) {
        palavraInvertida += pilha.top();
        pilha.pop();
    }
    return palavraInvertida;
}
//Exercicio 1 de aula: verificar se uma palavra eh um palindromo
bool ehPalindromo(const string& palavra) {
    Pilha<char> pilha;
    for (int i = 0; i < palavra.size(); ++i) {
        pilha.push(palavra[i]);
    }
    for (int i = 0; i < palavra.size(); ++i) {
        if (pilha.top() != palavra[i]) {
            return false;
        }
        pilha.pop();
    }
    return true;
}

