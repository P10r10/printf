#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
	puts("123456789012345678901234567890");
	printf("%d|\n", INT_MIN);
	ft_printf("%d|\n", INT_MIN);

	return 0;
}
