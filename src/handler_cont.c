#include "ft_printf.h"
void handle_u(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char *u_num = convert_decimal_to_base_x(num, 10, 'a');
	ft_putstr(u_num);
}
void handle_x(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char *hex_val = convert_decimal_to_base_x(num, 16, 'a');
	ft_putstr(hex_val);
}
void handle_X(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char *hex_val = convert_decimal_to_base_x(num, 16, 'A');
	ft_putstr(hex_val);
}