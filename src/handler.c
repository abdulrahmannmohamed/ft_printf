#include "ft_printf.h"
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
	unsigned long long n = (unsigned long long)p;
	char *hex_address = convert_decimal_to_base_x(n, 16, 'a');
	ft_putstr(hex_address);
}
void handle_o(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char *octal = convert_decimal_to_base_x(num, 8, 'a');
	ft_putstr(octal);
}
void handle_d(va_list list)
{
	int num = va_arg(list, int);
	ft_putnbr(num);
}
