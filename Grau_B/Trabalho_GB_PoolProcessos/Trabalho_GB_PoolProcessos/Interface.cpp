#include "Interface.h"
#include <iostream>
#include <limits>

using namespace std;

Interface::Interface() {}

void Interface::mostrarMenu() {
    cout << "\n===== MENU DO SISTEMA =====\n";
    cout << "1 - Criar processo\n";
    cout << "2 - Executar proximo processo\n";
    cout << "3 - Executar processo especifico (por PID)\n";
    cout << "4 - Salvar fila de processos\n";
    cout << "5 - Carregar fila de processos\n";
    cout << "0 - Sair\n";
    cout << "Escolha uma opcao: ";
}

void Interface::opcaoCriarProcesso() {
    int tipo;

    cout << "\n--- Criar processo ---\n";
    cout << "Tipo de processo:\n";
    cout << "1 - Processo de Calculo\n";
    cout << "2 - Processo de Gravacao\n";
    cout << "3 - Processo de Leitura (Process.txt -> fila)\n";
    cout << "4 - Processo de Impressao (mostra fila)\n";
    cout << "Escolha o tipo: ";
    cin >> tipo;

    if (tipo == 1) {
        int pid = Process::generatePid();  

        string expressao;
        cout << "Digite a expressao (ex: 10 + 20): ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, expressao);

        sistema.criarProcessoCalculo(pid, expressao);
        cout << "Processo de Calculo criado com PID " << pid << ".\n";
    }
    else if (tipo == 2) {
        int pid = Process::generatePid();

        string expressao;
        cout << "Digite a expressao para gravar no arquivo: ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, expressao);

        sistema.criarProcessoGravacao(pid, expressao);
        cout << "Processo de Gravacao criado com PID " << pid << ".\n";
    }
    else if (tipo == 3) {
        int pid = Process::generatePid();  

        sistema.criarProcessoLeitura(pid);
        cout << "Processo de Leitura criado com PID " << pid << ".\n";
    }
    else if (tipo == 4) {
        int pid = Process::generatePid(); 

        sistema.criarProcessoImpressao(pid);
        cout << "Processo de Impressao criado com PID " << pid << ".\n";
    }
    else {
        cout << "Tipo invalido. Nenhum processo criado.\n";
    }
}


void Interface::opcaoExecutarProximo() {
    cout << "\n--- Executar proximo processo ---\n";
    sistema.executarProximo();
}

void Interface::opcaoExecutarEspecifico() {
    cout << "\n--- Executar processo especifico ---\n";
    int pid;
    cout << "Digite o PID do processo a ser executado: ";
    cin >> pid;

    sistema.executarEspecifico(pid);
}

void Interface::opcaoSalvarFila() {
    cout << "\n--- Salvar fila ---\n";
    string nomeArquivo;
    cout << "Digite o nome do arquivo (ex: fila.txt): ";
    cin >> nomeArquivo;

    sistema.salvarFila(nomeArquivo);
}

void Interface::opcaoCarregarFila() {
    cout << "\n--- Carregar fila ---\n";
    string nomeArquivo;
    cout << "Digite o nome do arquivo (ex: fila.txt): ";
    cin >> nomeArquivo;

    sistema.carregarFila(nomeArquivo);
}

void Interface::executar() {
    int opcao = -1;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
        case 1:
            opcaoCriarProcesso();
            break;
        case 2:
            opcaoExecutarProximo();
            break;
        case 3:
            opcaoExecutarEspecifico();
            break;
        case 4:
            opcaoSalvarFila();
            break;
        case 5:
            opcaoCarregarFila();
            break;
        case 0:
            cout << "Saindo do sistema...\n";
            break;
        default:
            cout << "Opcao invalida.\n";
            break;
        }

    } while (opcao != 0);
}
