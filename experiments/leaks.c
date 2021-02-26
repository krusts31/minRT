#include <stdlib.h>
#include <stdio.h>

void	lols1()
{
	system("leaks a.out");
	exit(0);
}

void	test()
{
	char	*lols;

	lols = malloc(sizeof(char) * 1);
	lols1();
	system("leaks a.out");
	exit(0);
}

int	main()
{
	char	*test1;

	test1 = malloc(sizeof(char) * 1);
	if (test1 == NULL)
		return (0);
	test();
	system("leaks a.out");
	exit(0);
}
