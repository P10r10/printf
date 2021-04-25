#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
//	static char	a01;

	puts("123456789012345678901234567890");
	printf("%*.*x|\n", 10, 21, -10);
	ft_printf("%*.*x|\n", 10, 21, -10);
//x 392
	return 0;
}
