// #include "includes/ft_printf.h"
#include <stdio.h>
int main(void)
{
	// int  =-12;
	int b;
	int* a = &b;
	// int c = a;
	char *s = "hi";
	int x,y;
	x = ft_printf("|%5p|", 0);
	y = printf("|%5p|", 0);
	// ft_printf("b=%u", b);
	// y = printf("c = |%.0o|\n", 5);
	// x=ft_printf("%05%");
	// y=printf("%5p", 0);
	printf("\nmyprintf = %d\nrealprintf = %d", x, y);
}