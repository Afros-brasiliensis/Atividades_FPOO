#include "Process.h"

int Process::nextPid = 1;

Process::Process() {
	pid = 0;
}
Process::Process(int pid) {
	this->pid = pid;
}

Process::~Process() {
}

int Process::getPid() const {
	return pid;
}

int Process::generatePid() {
	// retorna o valor atual e já incrementa para o próximo
	return nextPid++;
}