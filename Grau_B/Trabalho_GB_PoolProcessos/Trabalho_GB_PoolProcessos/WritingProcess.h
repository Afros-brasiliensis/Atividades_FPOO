#pragma once
#include "Process.h"
#include <fstream>
#include <iostream>

class WritingProcess : public Process {
private:
	std::string expression;

public:
	WritingProcess(int pid, const std::string& expr);

	void execute() override;

	int getTipo() const override;

	const std::string& getExpression() const;

};
