#include "Sistema.h"
#include <iostream>
#include <fstream>

using namespace std;

Sistema::Sistema() {}

Sistema::~Sistema(){
	limparFila();
}

Fila<Process*>* Sistema::getFila(){
	return &fila;
}

void Sistema::criarProcessoCalculo(int pid, const std::string& expressao) {
    Process* p = new ComputingProcess(pid, expressao);
    fila.push(p);
}

void Sistema::criarProcessoGravacao(int pid, const std::string& expressao) {
    Process* p = new WritingProcess(pid, expressao);
    fila.push(p);
}

void Sistema::criarProcessoLeitura(int pid) {
    Process* p = new ReadingProcess(pid, &fila);
    fila.push(p);
}

void Sistema::criarProcessoImpressao(int pid) {
    Process* p = new PrintingProcess(pid, &fila);
    fila.push(p);
}

void Sistema::executarProximo() {
    if (fila.isEmpty()) {
        cout << "Nao ha processos na fila.\n";
        return;
    }

    Process* p = fila.front();
    fila.pop();

    if (p != nullptr) {
        p->execute();
        delete p;
    }
}

void Sistema::executarEspecifico(int pid) {
    if (fila.isEmpty()) {
        cout << "Nao ha processos na fila.\n";
        return;
    }

    Fila<Process*> aux;
    bool encontrou = false;

    while (!fila.isEmpty()) {
        Process* p = fila.front();
        fila.pop();

        if (!encontrou && p != nullptr && p->getPid() == pid) {
            cout << "Executando processo com PID " << pid << "...\n";
            p->execute();
            delete p;
            encontrou = true;
        } else {
            aux.push(p);
        }
    }

    while (!aux.isEmpty()) {
        Process* p = aux.front();
        aux.pop();
        fila.push(p);
    }

    if (!encontrou) {
        cout << "Processo com PID" << pid << " nao encontrado.\n";
    }
}

void Sistema::salvarFila(const std::string& nomeArquivo)
{
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir arquivo " << nomeArquivo << " para escrita.\n";
        return;
    }

    if (fila.isEmpty()) {
        std::cout << "Fila vazia, nada para salvar.\n";
        arquivo.close();
        return;
    }

    Fila<Process*> auxiliar;

    while (!fila.isEmpty()) {
        Process* p = fila.front();
        fila.pop();

        int tipo = p->getTipo();
        int pid = p->getPid();

        arquivo << tipo << " " << pid;

        if (tipo == 1) {
            ComputingProcess* cp = dynamic_cast<ComputingProcess*>(p);
            if (cp) {
                arquivo << " " << cp->getExpression();
            }
        }
        else if (tipo == 2) {
            WritingProcess* wp = dynamic_cast<WritingProcess*>(p);
            if (wp) {
                arquivo << " " << wp->getExpression();
            }
        }

        arquivo << "\n";
        auxiliar.push(p);
    }

    while (!auxiliar.isEmpty()) {
        Process* p = auxiliar.front();
        auxiliar.pop();
        fila.push(p);
    }

    std::cout << "Fila salva em " << nomeArquivo << ".\n";
}
void Sistema::carregarFila(const std::string& nomeArquivo)
{
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir arquivo " << nomeArquivo << " para leitura.\n";
        return;
    }

    limparFila();

    std::string linha;

    while (std::getline(arquivo, linha)) {
        if (linha.empty())
            continue;

        std::istringstream iss(linha);
        int tipo, pid;
        iss >> tipo >> pid;

        std::string expr;
        std::getline(iss, expr); 

       
        if (!expr.empty() && expr[0] == ' ')
            expr.erase(0, 1);

        Process* p = nullptr;

        if (tipo == 1) {
            p = new ComputingProcess(pid, expr);
        }
        else if (tipo == 2) {
            p = new WritingProcess(pid, expr);
        }
        else if (tipo == 3) {
            p = new ReadingProcess(pid, &fila);
        }
        else if (tipo == 4) { 
            p = new PrintingProcess(pid, &fila);
        }
        else {
            std::cout << "Tipo de processo invalido no arquivo: " << tipo << "\n";
        }

        if (p != nullptr) {
            fila.push(p);
        }
    }

    std::cout << "Fila carregada com sucesso de " << nomeArquivo << ".\n";
}

void Sistema::limparFila() {
    while (!fila.isEmpty()) {
        Process* p = fila.front();
        fila.pop();
        delete p;
    }
}