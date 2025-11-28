#include "WritingProcess.h"

WritingProcess::WritingProcess(int pid, const std::string& expr) : Process(pid) {
	expression = expr;
}

void WritingProcess::execute() {
	std::ofstream arquivo("Process.txt");
	if(arquivo.is_open()) {
		arquivo << "Processo " << pid << ": " << expression << std::endl;
		arquivo.close();
		std::cout << "Processo " << pid << ": Escrita concluida no arquivo." << std::endl;
	} else {
		std::cout << "Erro ao abrir o arquivo no processo " << pid << std::endl;
	}
}

int WritingProcess::getTipo() const {
	return 2;
}

const std::string& WritingProcess::getExpression() const {
	return expression;
}