#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
	puts("123456789012345678901234567890");
	
	printf("%07d|\n", -43);
  ft_printf("%07d|\n", -43);
  //224 d_zp_neg_minus1fit
	return 0;
}
