#include <stdio.h>

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
/*
**	AS FAR AS I AM AWEAR THEN SHIFTING BIT TO THE LEFT IT ACTS LIKE THE POWER SO IF ARG << 4 THEN THE ARG^4
**	IF ARG > 2 THEN ARG - 2 AND ARG^4+ARG-2;
*/
	return(t << 24 | r << 16 | g << 8 | b);
}

int	main(int argc, char **argv)
{
	int	ret;
	int	t;
	int	r;
	int	g;
	int	b;

	t = 2;
	r = 1;
	g = 1;
	b = 200;
	ret = 0;
	printf("%d| this is t: |%d| this is r: |%d| his is g: |%d| this is b: |%d|\n", ret, t, r, g, b);
	ret = create_trgb(t, r, g, b);
	printf("%d| this is t: |%d| this is r: |%d| his is g: |%d| this is b: |%d|\n", ret, t, r, g, b);
	printf("this is get_t %d\n", get_t(ret));
	printf("this is get_t %d\n", get_r(ret));
	printf("this is get_t %d\n", get_g(ret));
	printf("this is get_t %d\n", get_b(ret));
	return (0);
}
