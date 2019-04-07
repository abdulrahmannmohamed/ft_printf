#include "ft_printf.h"
#include <stdio.h>
void handle_c(va_list list)
{
	char c = va_arg(list, int);
	ft_putchar(c);
}
void handle_s(va_list list)
{
	char *s = va_arg(list, char*);
	ft_putstr(s);
}
void handle_p(va_list list)
{
	void *p = va_arg(list, void*);
	write(1, "0x", 2);
	char *hex_address = ptradd_to_hex(p, 'a');
	ft_putstr(hex_address);
}
void handle_d(va_list list)
{
	int num = va_arg(list, int);
	ft_putnbr(num);
}
