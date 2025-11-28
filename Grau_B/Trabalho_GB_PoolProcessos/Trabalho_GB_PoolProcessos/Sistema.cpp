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
        std::cout << "Erro ao abrir o arquivo para salvar a fila.\n";
        return;
    }

    if (fila.isEmpty()) {
        std::cout << "Fila vazia, nada para salvar.\n";
        arquivo.close();
        return;
    }

    int tamanhoOriginal = fila.getTamanho();
    int contador = 0;

    while (contador < tamanhoOriginal)
    {
        Process* p = fila.front();  
        fila.pop();                  

        int tipo = p->getTipo();
        int pid = p->getPid();

       
        arquivo << tipo << " " << pid;

        if (tipo == 1) {
            ComputingProcess* cp = (ComputingProcess*)p;
            arquivo << " " << cp->getExpression();
        }
        else if (tipo == 2) {
            WritingProcess* wp = (WritingProcess*)p;
            arquivo << " " << wp->getExpression();
        }

        arquivo << "\n";

        fila.push(p);

        contador++;
    }

    arquivo.close();

    std::cout << "Fila salva com sucesso em " << nomeArquivo << ".\n";
}

void Sistema::carregarFila(const std::string& nomeArquivo)
{
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo para carregar a fila.\n";
        return;
    }

   
    while (!fila.isEmpty()) {
        Process* p = fila.front();
        fila.pop();
        delete p;
    }

    int tipo;
    int pid;
    std::string expr;

 
    while (arquivo >> tipo >> pid)
    {
        if (tipo == 1) {
          
            arquivo >> expr;
            Process* p = new ComputingProcess(pid, expr);
            fila.push(p);
        }
        else if (tipo == 2) {
           
            arquivo >> expr;
            Process* p = new WritingProcess(pid, expr);
            fila.push(p);
        }
        else if (tipo == 3) {
            
            Process* p = new ReadingProcess(pid, &fila);
            fila.push(p);
        }
        else if (tipo == 4) {
      
            Process* p = new PrintingProcess(pid, &fila);
            fila.push(p);
        }
        else {
            std::cout << "Tipo de processo invalido encontrado no arquivo: "
                << tipo << "\n";
          
            std::getline(arquivo, expr);
        }
    }

    arquivo.close();

    std::cout << "Fila carregada com sucesso de " << nomeArquivo << ".\n";
}

void Sistema::limparFila() {
    while (!fila.isEmpty()) {
        Process* p = fila.front();
        fila.pop();
        delete p;
    }
}