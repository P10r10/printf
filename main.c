#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
	puts("123456789012345678901234567890");
	
	printf("%.5d", 2);
  ft_printf("%.5d", 2);
  //ft_printf("%d|\n", 19);
	//"%3d", 0)
	return 0;
}
