#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector> 

#include "Batalha.h"

bool Batalha::executar() {
	cout << "\n--- A BATALHA COMECA! ---" << endl;

	bool jogadorFugiu = false;
	bool turnoValido = true; 

	while (jogador->estaVivo() && inimigo->estaVivo() && !jogadorFugiu) {

		exibirStatus();

		cout << "\n--- SEU TURNO ---" << endl;
		cout << "Escolha sua acao:" << endl;
		cout << "1. Atacar" << endl;
		cout << "2. Usar Item" << endl; 
		cout << "3. Tentar Fugir" << endl;

		int escolha;
		cin >> escolha;

		turnoValido = true; 

		if (escolha == 1) { 
			int faJogador = calcularForcaAtaque(jogador->getHabilidade() + jogador->getBonusForcaAtaque());
			int faInimigo = calcularForcaAtaque(inimigo->getHabilidade());
			cout << "Sua Forca de Ataque: " << faJogador << " | Inimigo: " << faInimigo << endl;

			if (faJogador > faInimigo) {
				cout << "Voce acertou o inimigo!" << endl;
				inimigo->tomarDano(2);
			}
			else {
				cout << "O inimigo defendeu o seu ataque." << endl;
			}

		}
		else if (escolha == 2) { // USAR ITEM
			// Filtra o inventario para mostrar apenas itens usaveis em combate
			vector<Item> inventario = jogador->getInventario();
			vector<Item> itensUsaveis;
			vector<int> indicesOriginais; // Para saber o indice real do item no inventario principal

			for (int i = 0; i < inventario.size(); ++i) {
				// Um item usavel e comum ('c') e pode ser usado em combate
				if (inventario[i].isUsavelEmCombate() && inventario[i].getTipo() == 'c') {
					itensUsaveis.push_back(inventario[i]);
					indicesOriginais.push_back(i);
				}
			}

			if (itensUsaveis.empty()) {
				cout << "Voce nao tem itens que possam ser usados em combate." << endl;
				turnoValido = false; // O jogador nao fez nada, entao nao perde o turno
			}
			else {
				cout << "Qual item voce quer usar?" << endl;
				for (int i = 0; i < itensUsaveis.size(); ++i) {
					cout << i + 1 << ". " << itensUsaveis[i].getNome() << endl;
				}
				cout << "0. Cancelar" << endl;

				int escolhaItem;
				cin >> escolhaItem;

				if (escolhaItem > 0 && escolhaItem <= itensUsaveis.size()) {
					Item& itemEscolhido = itensUsaveis[escolhaItem - 1];

					// Logica de efeito do item
					if (itemEscolhido.getNome() == "Pocao de Cura") {
						cout << "Voce bebe a pocao de cura." << endl;
						jogador->curar(7); // Cura 7 pontos de energia
						// NOTA: Para um item consumivel, aqui voce chamaria um metodo para remover o item do inventario.
					}
				}
				else {
					cout << "Acao cancelada." << endl;
					turnoValido = false; // Acao cancelada, nao perde o turno
				}
			}

		}
		else if (escolha == 3) { // FUGIR
			if (inimigo->isFugaPermitida()) {
				cout << "Voce conseguiu escapar da batalha!" << endl;
				jogadorFugiu = true;
			}
			else {
				cout << "Voce tenta fugir, mas o " << inimigo->getNome() << " bloqueia seu caminho! Voce perde o turno." << endl;
			}
		}

		if (!inimigo->estaVivo()) {
			break;
		}

		// So passa para o turno do inimigo se o jogador fez uma acao valida (atacar ou fugir sem sucesso)
		if (turnoValido && !jogadorFugiu) {
			cout << "\n--- TURNO DO INIMIGO ---" << endl;
			// ... (logica do turno do inimigo permanece a mesma) ...
			int faInimigo = calcularForcaAtaque(inimigo->getHabilidade());
			int faJogador = calcularForcaAtaque(jogador->getHabilidade());
			cout << "Forca de Ataque do " << inimigo->getNome() << ": " << faInimigo << " | Sua Defesa: " << faJogador << endl;

			if (faInimigo > faJogador) {
				cout << "O inimigo acertou voce!" << endl;
				jogador->tomarDano(2);
			}
			else {
				cout << "Voce conseguiu defender o ataque do inimigo." << endl;
			}
		}
	}

	cout << "\n--- FIM DA BATALHA ---" << endl;
	return jogador->estaVivo() && !jogadorFugiu;
}

// ... (o resto do Batalha.cpp permanece igual) ...