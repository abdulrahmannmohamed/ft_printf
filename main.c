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
	x = ft_printf("@moulitest: |%5.o| |%5.0o|", 0, 0);
	y = printf("@moulitest: |%5.o| |%5.0o|", 0, 0);
	// ft_printf("b=%u", b);
	// y = printf("c = |%.0o|\n", 5);
	// x=ft_printf("%05%");
	// x=ft_printf("%015p", a);
	// y=printf("%.100p", a);
	printf("\nmyprintf = %d\nrealprintf = %d", x, y);
}