#include "PrintingProcess.h"
#include <iostream>

PrintingProcess::PrintingProcess(int pid, Fila<Process*>* filaSistema) : Process(pid) {
	this->fila = filaSistema;
}

void PrintingProcess::execute() {
	std::cout << "[PrintingProcess] PID" << pid
		<< "imprimindo fila de processos...\n";

	if (fila->isEmpty()) {
		std::cout << "Fila vazia.\n";
		return;
	}

	Nodo<Process*>* atual = fila->getInicio();

	while (atual != nullptr) {
		Process* p = atual->getValor();

		std::cout << "- PID: " << p->getPid()
			<< "| Tipo: " << p->getTipo()
			<< "\n";

		atual = atual->getProximo();
	}
}

int PrintingProcess::getTipo() const {
	return 4;
}

