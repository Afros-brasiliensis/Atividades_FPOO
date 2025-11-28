#pragma once
#include <string>

class Process {
protected:
	int pid;

	static int nextPid;

public:
	Process();

	Process(int pid);

	virtual ~Process();

	int getPid() const;

	virtual void execute() = 0;
	
	virtual int getTipo() const = 0;

	static int generatePid();
};