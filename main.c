// #include "includes/ft_printf.h"
int main(void)
{
	int b = 5;
	int *a = &b;
	
	ft_printf("b = %d\na = %p", b, a);
}