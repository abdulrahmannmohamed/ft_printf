#include "ft_printf.h"
int handle_u(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int places = places_with_base_x(num, 10);
	print_in_base_x(num, 10, 'a');
	return (places);
}
int handle_x(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int places = places_with_base_x(num, 16);
	print_in_base_x(num, 16, 'a');
	return (places);
}
int handle_X(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int places = places_with_base_x(num, 16);
	print_in_base_x(num, 16, 'A');
	return (places);
}