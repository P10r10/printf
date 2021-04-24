#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
	puts("123456789012345678901234567890");

	printf("%d|\n", 0);
	ft_printf("%d|\n", 0);
	//261 d_zp_neg_minus1fit
	return 0;
}
