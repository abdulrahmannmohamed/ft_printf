// #include "includes/ft_printf.h"
#include <stdio.h>
int main(void)
{
	unsigned int b = 123123123;
	unsigned int a = (unsigned int)b;
	int c = a;

	ft_printf("b=%x", b);
	// ft_printf("b=%u", b);
	printf("\nb=%x", b);
}