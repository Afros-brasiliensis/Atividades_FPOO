#pragma once
#include <string>
#include "Process.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "PrintingProcess.h"
#include "ReadingProcess.h"
#include "Fila.h"	

class Sistema {
private:

	Fila<Process*> fila;

public:

	Sistema();
	~Sistema();

	Fila<Process*>* getFila();

	//criacao dos processos
	void criarProcessoCalculo(int pid, const std::string& expressao);
	void criarProcessoGravacao(int pid, const std::string& expressao);
	void criarProcessoLeitura(int pid);
	void criarProcessoImpressao(int pid);

	void executarProximo();
	void executarEspecifico(int pid);

	void salvarFila(const std::string& nomeArquivo);
	void carregarFila(const std::string& nomeArquivo);

	void limparFila();
};
