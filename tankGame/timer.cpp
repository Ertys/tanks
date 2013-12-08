#include "timer.h"


timer::timer()
{
}


timer::~timer()
{
}


double timer::time_elapsed()
{
	return 0.0166666666666;
}


void timer::reset()
{
}


void timer::sleep(double pTime)
{
	Sleep(DWORD(pTime * 1000));
}
