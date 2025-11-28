#pragma once
#include "Process.h"
#include <iostream>
#include <sstream>	

class ComputingProcess : public Process {
private: 
	std::string expression;

public:
	ComputingProcess(int pid, const std::string& expr);

	int getTipo() const override;

	const std::string& getExpression() const;

	void execute() override;

};//terminar computing process, fiz writing process e o resto de tudo.