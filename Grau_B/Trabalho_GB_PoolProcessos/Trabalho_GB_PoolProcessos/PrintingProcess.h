#pragma once
#include "Process.h"
#include "Fila.h"

class PrintingProcess : public Process {
private:
	Fila<Process*>* fila;

public:
	PrintingProcess(int pid, Fila<Process*>* filaSistema);

	void execute() override;

	int getTipo() const override;

};