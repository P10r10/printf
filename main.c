#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
	puts("123456789012345678901234567890");
	
	printf("%10.22d|\n", 3);
	ft_printf("%10.22d|\n", 3);
	//ft_printf("%5.4d|\n", 12);
//pft test 219
	return 0;
}
