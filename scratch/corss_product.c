#include <stdio.h>

int	main()
{
	int	x;
	int	y;
	int	z;

	int	x1;
	int	y1;
	int	z1;

/*
**	if the x valu in the f1st vector is set to 1 then it 
**	and the y value in the 2 array to 1; y value in the 1st vector set to zero
**	and the x value in the seccond vector is set to 0
**	then te z axis is going to be 1 otherwise -1;
*/
	x = 0;
	y = 1;
	z = 0;

	x1 = 1;
	y1 = 0;
	z1 = 0;
	printf("this is x: %d\n" ,y * z1 - z * y1);
	printf("this is y: %d\n" ,z * x1 - x * z1);
	printf("this is z: %d\n" ,x * y1 - y * x1);
	return (0);
}
