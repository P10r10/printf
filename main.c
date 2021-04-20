#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
	puts("123456789012345678901234567890");
	
	int i = printf("%.d|\n", 0);
	printf("COUNT: %d\n", i);
	i = ft_printf("%.d|\n", 0);
	printf("COUNT: %d\n", i);
	//make d 5

	return 0;
}
