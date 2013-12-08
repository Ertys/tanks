#pragma once

#include <windows.h>

class timer
{
public:
	timer();
	~timer();
	double time_elapsed();
	void reset();
	void sleep(double pTime);
private:
};

