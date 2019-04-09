#include "ft_printf.h"
int handle_u(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int places = 0;
	print_in_base_x(num, 10, 'a', &places);
	return (places);
}
int handle_x(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int places = 0;
	print_in_base_x(num, 16, 'a', &places);
	return (places);
}
int handle_X(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int places = 0;
	print_in_base_x(num, 16, 'A', &places);
	return (places);
}