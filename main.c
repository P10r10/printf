#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
	puts("123456789012345678901234567890");
	
	int i = printf("%-4.d|\n", 123);
	printf("COUNT: %d\n", i);
	i = ft_printf("%-4.d|\n", 123);
	printf("COUNT: %d\n", i);

	return 0;
}
