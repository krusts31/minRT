#include <stdio.h>
#include <math.h>

int	main()
{
	float	x;
	float	y;
	float	z;
	float	len;

	x = 5;
	y = 7;
	z = 2;
	len = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	if (len > 0)
	{
		float invLen;

		invLen = 1 / len;
		x *=invLen;
		y *=invLen;
		z *=invLen;
		printf("len: %f\ninvLen: %f\nx: %f y: %f z: %f\n",len, invLen, x, y, z);
	}
	return (0);
}
