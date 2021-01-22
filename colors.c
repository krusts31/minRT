#include "minRT.h"
/*
**	AS FAR AS I AM AWEAR THEN SHIFTING BIT TO THE LEFT IT ACTS LIKE THE POWER SO IF ARG << 4 THEN THE ARG^4
**	IF ARG > 2 THEN ARG - 2 AND ARG^4+ARG-2;
*/
int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
