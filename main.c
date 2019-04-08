// #include "includes/ft_printf.h"
#include <stdio.h>
int main(void)
{
	int b = -123;
	int* a = &b;
	// int c = a;
	int x,y;
	x = ft_printf("b=%u", b);
	// ft_printf("b=%u", b);
	y = printf("b=%u", b);
	printf("\nmyprintf = %d\nrealprintf = %d", x, y);
}