#pragma once
#include "ComputingProcess.h"

ComputingProcess::ComputingProcess(int pid, const std::string& expr) : Process(pid) {
	expression = expr;
}

void ComputingProcess::execute() {
	std::istringstream iss(expression);
	double operando1, operando2;
	char operador;
	iss >> operando1 >> operador >> operando2;

	double resultado = 0;
	bool ok = true;
	switch (operador) {
		case '+':
			resultado = operando1 + operando2;
			break;
		case '-':
			resultado = operando1 - operando2;
			break;
		case '*':
			resultado = operando1 * operando2;
			break;
		case '/':
			if (operando2 != 0) {
				resultado = operando1 / operando2;
			} else {
				std::cout << "Erro: Divisao por zero no processo " << pid << std::endl;
				return;
			}
			break;
		default:	
			std::cout << "[PID " << pid << "] Operador invalido: " << operador << std::endl;
			ok = false;
		}
	if(ok)
		std::cout << "Processo " << pid << ": " << expression << " = " << resultado << std::endl;
}

const std::string& ComputingProcess::getExpression() const {
	return expression;
}

int ComputingProcess::getTipo() const {
	return 1;
}

