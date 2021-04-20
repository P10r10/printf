#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
	puts("123456789012345678901234567890");
	
	printf("%10p|\n", NULL);
	ft_printf("%10p|\n", NULL);

	return 0;
}
