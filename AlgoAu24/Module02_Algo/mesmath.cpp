#include "mesmath.h"


int mesmath::max(int p_nombre1, int p_nombre2)
{
	
	return p_nombre1 > p_nombre2 ? p_nombre1 : p_nombre2;
}

int mesmath::min(int p_nombre1, int p_nombre2)
{
	return  p_nombre1 > p_nombre2 ? p_nombre2 : p_nombre1;
}
