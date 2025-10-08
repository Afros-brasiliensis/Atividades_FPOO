#include "Game.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <limits>

using namespace std;

// Função auxiliar para dividir strings, usada no carregamento do save
static vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

Jogo::Jogo() : jogador(nullptr), numeroCenaAtual(0) {
    srand(time(nullptr));
}

Jogo::~Jogo() {
    delete jogador;
}

void Jogo::iniciar() {
    // A lógica de iniciar o jogo sempre começa pelo menu principal.
    telaDeAbertura();
}

void Jogo::telaDeAbertura() {
    int escolha = 0;
    while (escolha != 4) {
        cout << "\n==============================" << endl;
        cout << "      AVENTURA FANTASTICA     " << endl;
        cout << "==============================" << endl;
        cout << "1. Novo Jogo" << endl;
        cout << "2. Carregar Jogo Salvo" << endl;
        cout << "3. Creditos" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            escolha = 0;
        }

        switch (escolha) {
        case 1: {
            int slot = escolherSlot();
            criarNovoJogo(slot);
            break;
        }
        case 2: {
            int slot = escolherSlot();
            carregarJogoSalvo(slot);
            break;
        }
        case 3:
            exibirCreditos();
            break;
        case 4:
            cout << "Saindo do jogo. Ate a proxima!" << endl;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}

void Jogo::criarNovoJogo(int slot) {
    cout << "\n -- Criando um Novo Jogo -- \n" << endl;
    jogador = new Personagem(); // Cria um personagem temporário
    telaDeInventario(true);     // Aqui o personagem real é criado e configurado

    numeroCenaAtual = 1;
    cenasVisitadas.clear();
    cenasVisitadas.push_back(numeroCenaAtual);

    telaPrincipalDoJogo(slot);
}

void Jogo::carregarJogoSalvo(int slot) {
    cout << "\n -- Carregando Jogo Salvo -- \n" << endl;
    if (carregar(slot)) {
        cout << "Jogo carregado com sucesso!" << endl;
        telaDeInventario(false); // Apenas mostra o inventário
        telaPrincipalDoJogo(slot);
    }
    else {
        cout << "Nenhum jogo salvo encontrado no slot " << slot << "." << endl;
    }
}

void Jogo::exibirCreditos() {
    cout << "\n -- Creditos -- \n" << endl;
    cout << "Desenvolvido por:" << endl;
    cout << "Athos Nunes Kolling" << endl;
    cout << "Gustavo Sbardelotto Rezende" << endl;
    cout << "Obrigado por jogar!" << endl;
}

void Jogo::telaDeInventario(bool criandoPersonagem) {
    if (criandoPersonagem) {
        cout << "\n--- Criacao de Personagem ---" << endl;
        cout << "Voce tem 12 pontos para distribuir entre os atributos." << endl;

        // Atributos começam com o valor mínimo
        int habilidade = 6;
        int energia = 12;
        int sorte = 6;
        int pontosParaDistribuir = 12;

        while (pontosParaDistribuir > 0) {
            // Limpa a tela para ver melhor
            system("cls");

            cout << "\nVoce tem " << pontosParaDistribuir << " pontos restantes." << endl;
            cout << "Atributos Atuais:" << endl;
            cout << "1. HABILIDADE: " << habilidade << " (Max: 12)" << endl;
            cout << "2. ENERGIA:    " << energia << " (Max: 24)" << endl;
            cout << "3. SORTE:      " << sorte << " (Max: 12)" << endl;

            cout << "\nEm qual atributo voce quer adicionar pontos? (1, 2 ou 3): ";
            int escolhaAtributo;
            cin >> escolhaAtributo;

            if (cin.fail() || escolhaAtributo < 1 || escolhaAtributo > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Opcao invalida. Tente novamente." << endl;
                continue;
            }

            cout << "Quantos pontos voce deseja adicionar? ";
            int pontosAdicionar;
            cin >> pontosAdicionar;

            if (cin.fail() || pontosAdicionar <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Voce deve adicionar um numero positivo de pontos." << endl;
                continue;
            }

            if (pontosAdicionar > pontosParaDistribuir) {
                cout << "Voce nao tem pontos suficientes!" << endl;
                continue;
            }

            switch (escolhaAtributo) {
            case 1: // Habilidade
                if (habilidade + pontosAdicionar > 12) {
                    cout << "Nao e possivel ultrapassar o valor maximo de 12 para HABILIDADE." << endl;
                }
                else {
                    habilidade += pontosAdicionar;
                    pontosParaDistribuir -= pontosAdicionar;
                }
                break;
            case 2: // Energia
                if (energia + pontosAdicionar > 24) {
                    cout << "Nao e possivel ultrapassar o valor maximo de 24 para ENERGIA." << endl;
                }
                else {
                    energia += pontosAdicionar;
                    pontosParaDistribuir -= pontosAdicionar;
                }
                break; 
            case 3: // Sorte
                if (sorte + pontosAdicionar > 12) {
                    cout << "Nao e possivel ultrapassar o valor maximo de 12 para SORTE." << endl;
                }
                else {
                    sorte += pontosAdicionar;
                    pontosParaDistribuir -= pontosAdicionar;
                }
                break;
            }
        }

        delete jogador;
        jogador = new Personagem("Aventureiro", habilidade, energia, sorte);

        cout << "\n--- Personagem Criado! ---" << endl;
    }

    // Garante que o jogador existe antes de tentar mostrar o inventário
    if (jogador) {
        jogador->mostrarInventario();
    }

    cout << "Pressione Enter para continuar...";
    // Limpa qualquer entrada restante no buffer antes de esperar pelo Enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void Jogo::telaPrincipalDoJogo(int slot) {
    bool jogoAtivo = true;
    while (jogoAtivo && jogador->estaVivo()) {
        salvarProgresso(slot);

        if (!cenaAtual.carregar(numeroCenaAtual)) {
            cout << "Fim da Aventura! Obrigado por jogar." << endl;
            jogoAtivo = false;
            continue;
        }

        Item* itemDaCena = cenaAtual.getItem();
        if (itemDaCena) {
            cout << "\nVoce encontrou: " << itemDaCena->getNome() << endl;
            jogador->adicionarItem(*itemDaCena);
        }

        if (cenaAtual.isCenaDeCombate()) {
            telaDeCombate(cenaAtual.getInimigo());
        }
        else {
            system("cls");
            cout << cenaAtual.getTexto() << endl;

            const auto& opcoes = cenaAtual.getTextoEscolhas();
            for (size_t i = 0; i < opcoes.size(); ++i) {
                cout << i + 1 << ". " << opcoes[i] << endl;
            }

            int escolha;
            cout << "\nSua escolha: ";
            cin >> escolha;
            processarEscolha(escolha);
        }

        if (numeroCenaAtual == 0) { // Condição de fim de jogo
            jogoAtivo = false;
        }
    }

    if (!jogador->estaVivo()) {
        cout << "\n--- VOCE FOI DERROTADO --- \nFim de Jogo." << endl;
    }
}

void Jogo::telaDeCombate(Monstro* inimigo) {
    cout << "\n -- Combate Iniciado! -- \n" << endl;
    cout << "Voce esta enfrentando: " << inimigo->getNome() << endl;

    while (jogador->estaVivo() && inimigo->estaVivo()) {
        cout << "\nSua Energia: " << jogador->getEnergia() << " | Energia do " << inimigo->getNome() << ": " << inimigo->getEnergia() << endl;
        cout << "O que voce faz?\n1. Atacar\n2. Usar Sorte\n3. Tentar Fugir" << endl;

        int escolha;
        cin >> escolha;
        switch (escolha) {
        case 1:
            executarCombate(inimigo); // **CORREÇÃO**: Passando o inimigo
            break;
        case 2:
            if (jogador->usarSorte()) {
                cout << "Voce testa sua sorte e consegue um golpe poderoso!" << endl;
                inimigo->tomarDano(4); // Dano ampliado
            }
            else {
                cout << "Voce nao tem mais Sorte para usar!" << endl;
            }
            break; // **CORREÇÃO**: Faltava este break
        case 3:
            cout << "Voce tentou fugir..." << endl;
            // Lógica de fuga aqui
            numeroCenaAtual = cenaAtual.getCenaDerrota(); // Fuga leva à cena de "derrota"
            return; // Sai da função de combate
        }
    } // **CORREÇÃO**: Faltava esta chave '}' para fechar o while

    if (jogador->estaVivo()) {
        cout << "Voce venceu!" << endl;
        numeroCenaAtual = cenaAtual.getCenaVitoria();
    }
    else {
        numeroCenaAtual = cenaAtual.getCenaDerrota();
    }
}

void Jogo::processarEscolha(int escolha) {
    const auto& destinos = cenaAtual.getCenasDestino();
    if (escolha > 0 && escolha <= destinos.size()) {
        numeroCenaAtual = destinos[escolha - 1];
    }
    else {
        cout << "Escolha invalida." << endl;
    }
}

void Jogo::executarCombate(Monstro* inimigo) {
    int faJogador = (rand() % 10 + 1) + jogador->getHabilidade();
    int faInimigo = (rand() % 10 + 1) + inimigo->getHabilidade();

    cout << "Sua Forca de Ataque: " << faJogador << " | Forca do Inimigo: " << faInimigo << endl;

    if (faJogador > faInimigo) {
        cout << "Voce atinge o inimigo!" << endl;
        inimigo->tomarDano(2);
    }
    else if (faInimigo > faJogador) {
        cout << "O inimigo atinge voce!" << endl;
        jogador->tomarDano(2);
    }
    else {
        cout << "Empate!" << endl;
    }
}

int Jogo::escolherSlot() {
    int slot = 0;
    while (slot < 1 || slot > 3) {
        cout << "\nEscolha um slot de jogo (1, 2 ou 3): ";
        cin >> slot;
        if (cin.fail() || slot < 1 || slot > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcao invalida." << endl;
            slot = 0;
        }
    }
    return slot;
}

void Jogo::salvarProgresso(int slot) {
    if (!jogador) return; // Não salva se o jogador não existir
    ofstream saveFile("savegame" + to_string(slot) + ".txt");
    if (!saveFile.is_open()) return;

    saveFile << jogador->getNome() << "\n"
        << jogador->getHabilidade() << "\n"
        << jogador->getEnergia() << "\n"
        << jogador->getSorte() << "\n"
        << jogador->getTesouro() << "\n"
        << jogador->getProvisoes() << "\n";

    vector<Item> inventario = jogador->getInventario();
    saveFile << inventario.size() << "\n";
    for (auto& item : inventario) {
        saveFile << item.getNome() << ";" << item.getTipo() << ";" << item.isUsavelEmCombate() << ";" << item.getBonusForcaAtaque() << ";" << item.getBonusDano() << "\n";
    }

    saveFile << numeroCenaAtual << "\n";
    saveFile << cenasVisitadas.size() << "\n";
    for (int cena : cenasVisitadas) {
        saveFile << cena << " ";
    }
    saveFile << "\n";
    saveFile.close();
}

bool Jogo::carregar(int slot) {
    // 1. Tenta abrir o arquivo do slot escolhido
    ifstream loadFile("savegame" + to_string(slot) + ".txt");
    if (!loadFile.is_open()) {
        // Se o arquivo não existir, retorna false.
        return false;
    }

    try {
        // 2. Lê os dados básicos do personagem
        string nome;
        int habilidade, energia, sorte, tesouro, provisoes;
        string linha;

        getline(loadFile, nome);
        getline(loadFile, linha); habilidade = stoi(linha);
        getline(loadFile, linha); energia = stoi(linha);
        getline(loadFile, linha); sorte = stoi(linha);
        getline(loadFile, linha); tesouro = stoi(linha);
        getline(loadFile, linha); provisoes = stoi(linha);

        // 3. Deleta o jogador antigo (se houver) e cria um novo com os dados carregados
        delete jogador;
        jogador = new Personagem(nome, habilidade, energia, sorte);

        // Atribui o tesouro e as provisões carregadas
        // (Garanta que sua classe Personagem tenha estes métodos)
        jogador->adicionarTesouro(tesouro);
        // jogador->setProvisoes(provisoes); // Você precisará criar este método em Personagem.h/cpp

        // 4. Lê o inventário
        getline(loadFile, linha);
        int numItens = stoi(linha);

        for (int i = 0; i < numItens; ++i) {
            string itemLinha;
            getline(loadFile, itemLinha);

            // Usa a função 'split' para quebrar a linha "nome;tipo;combate;fa;dano"
            vector<string> dadosItem = split(itemLinha, ';');
            if (dadosItem.size() == 5) {
                Item item(dadosItem[0],                 // nome (string)
                    dadosItem[1][0],               // tipo (char)
                    stoi(dadosItem[2]),            // podeUsarEmCombate (bool/int)
                    stoi(dadosItem[3]),            // bonusForcaAtaque (int)
                    stoi(dadosItem[4]));           // bonusDano (int)

                jogador->adicionarItem(item);
            }
        }

        // 5. Lê o estado do jogo (cena atual)
        getline(loadFile, linha);
        this->numeroCenaAtual = stoi(linha);

        // 6. Lê o histórico de cenas visitadas
        this->cenasVisitadas.clear();
        getline(loadFile, linha);
        int numCenasVisitadas = stoi(linha);

        if (numCenasVisitadas > 0) {
            getline(loadFile, linha);
            istringstream cenasStream(linha);
            int idCena;
            while (cenasStream >> idCena) {
                this->cenasVisitadas.push_back(idCena);
            }
        }

        // 7. Se tudo correu bem, fecha o arquivo e retorna sucesso
        loadFile.close();
        return true;

    }
    catch (const std::exception& e) {
        // Se qualquer conversão (stoi) ou leitura falhar, o arquivo está corrompido.
        cerr << "Erro ao carregar o jogo: arquivo de save corrompido. (" << e.what() << ")" << endl;
        loadFile.close();
        return false;
    }
}