#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
//	static char	a01;

	puts("123456789012345678901234567890");
	printf("%p %p|\n", ULONG_MAX, -ULONG_MAX);
	ft_printf("%p %p|\n", ULONG_MAX, -ULONG_MAX);
//x 392
	return 0;
}
