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
	// x = ft_printf("c = |%-15p|\n", a);
	x = ft_printf("c = |%3s|\n", s);
	// ft_printf("b=%u", b);
	y = printf("c = |%3s|\n", s);
	printf("\nmyprintf = %d\nrealprintf = %d", x, y);
}