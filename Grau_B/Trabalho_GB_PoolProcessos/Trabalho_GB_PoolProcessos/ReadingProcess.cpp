#include "ReadingProcess.h"
#include <iostream>
#include <fstream>

void ReadingProcess::execute() {
	std::ifstream arquivo("Process.txt");

	if (!arquivo.is_open()) {
		std::cout << "Erro ao abrir Process.txt para leitura. \n";
		return;
	}

	std::string linha;
	std::cout << "[ReadingProcess] PID " << pid
		<< "lendo Process.txt...\n";

	while (std::getline(arquivo, linha))
	{
		if (linha.empty()) continue;
		int newPid = Process::generatePid();
		Process* proc = new ComputingProcess(newPid, linha);

		fila->push(proc);

		std::cout << "- Criado ComputingProcess("
			<< newPid << ")" << linha << "\n"; 
	}

	arquivo.close();

	std::ofstream clearFile("Process.txt");
	clearFile.close();

	std::cout << "[ReadingProcess Arquivo limpo.\n";

}

int ReadingProcess::getTipo() const {
	return 3;
}



