#include <math.h>
#include <stdio.h>

int	main()
{
	int	x;

	x = 0;
	while (x != 361)
	{
		printf("dle[%d], this is cos |%f| this is sin [%f]\n", x, cos(x), sin(x));
		x++;
	}
	return (0);
}
