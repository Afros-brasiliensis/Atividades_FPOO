#include <iostream>
#include <string>
#include "Pilhas.h"

using namespace std;

bool expressaoBalanceada(const string& expressao) {
	Pilha<char> pilha;
	bool temSimbolo = false;
	for (char caractere : expressao) {
		if (caractere == '(' || caractere == '[' || caractere == '{') {
			pilha.push(caractere);
			temSimbolo = true;
		}
		else if(caractere == ')' || caractere == ']' || caractere == '}') {
			temSimbolo = true;
			
			if (pilha.isEmpty()) {
				cout << "Erro : Fecha '" << caractere << "' sem correspondente abre." << endl;
				return false;
			}
			char aberto = pilha.top();
			pilha.pop();

			bool combina = 
				(aberto == '(' && caractere == ')') ||
				(aberto == '[' && caractere == ']') ||
				(aberto == '{' && caractere == '}');

			if (!combina) {
				cout << "Erro : Fecha '" << caractere << "' mas o ultimo aberto foi '" << aberto << "'." << endl;
			}
		}
	}

	if (!pilha.isEmpty()) {
		char aberto = pilha.top();
		cout << "Erro : Abre '" << aberto << "' sem correspondente fecha." << endl;
		return false;
	}

	if (!temSimbolo) {
		cout << "Expressao balanceada: Nenhum simbolo de abertura ou fechamento" << endl;
	}
	else {
		cout << "Expressao balanceada!" << endl;
	}
	return true;
}