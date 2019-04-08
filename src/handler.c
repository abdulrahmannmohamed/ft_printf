#include "ft_printf.h"
int handle_c(va_list list)
{
	char c = va_arg(list, int);
	write(1, &c, 1);
	return(1);
}
int handle_s(va_list list)
{
	char *s = va_arg(list, char*);
	ft_putstr(s);
	return(ft_strlen(s));
}
int handle_p(va_list list)
{
	void *p = va_arg(list, void*);
	write(1, "0x", 2);
	unsigned long long n = (unsigned long long)p;
	int places = places_with_base_x(n, 16);
	print_in_base_x(n, 16, 'a');
	return (places + 2);
}
int handle_o(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int places = places_with_base_x(num, 8);
	print_in_base_x(num, 8, 'a');
	return (places);
}
int handle_d(va_list list)
{
	int num = va_arg(list, int);
	ft_putnbr(num);
	return (places_with_base_x(num, 10));
}
