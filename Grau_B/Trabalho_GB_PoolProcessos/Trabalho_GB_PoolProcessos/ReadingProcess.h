#pragma once
#include <string>
#include "Process.h"
#include "Fila.h"
#include "ComputingProcess.h"

class ReadingProcess : public Process {
private:
	Fila<Process*>* fila;

public:
	ReadingProcess(int pid, Fila<Process*>* filaSistema) : Process(pid), fila(filaSistema) {}

	void execute() override;

	int getTipo() const override;
};