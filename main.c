#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int main()
{
	
	puts("123456789012345678901234567890");
 // ft_printf("Meu:%0*.*d|\n", 3, -2, 8);
  printf("%.*u|\n", -11, -12);
	//ft_printf("% *.5i|\n", 4, 42);


  //42Maz 503/514
  //pft   677/694
	return 0;
}
