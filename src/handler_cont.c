#include "ft_printf.h"
int handle_u(va_list list, t_block *block)
{
	(void)block;
	unsigned long long num = handle_unsigned_len(list, block);
	int places = 0;
	print_in_base_x_and_count_digits(num, 10, 'a', &places);
	return (places);
}
int handle_x(va_list list, t_block *block)
{
	(void)block;
	unsigned long long num = handle_unsigned_len(list, block);
	int places = 0;
	print_in_base_x_and_count_digits(num, 16, 'a', &places);
	return (places);
}
int handle_X(va_list list, t_block *block)
{
	(void)block;
	unsigned long long num = handle_unsigned_len(list, block);
	int places = 0;
	print_in_base_x_and_count_digits(num, 16, 'A', &places);
	return (places);
}