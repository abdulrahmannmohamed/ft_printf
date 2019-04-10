#include "ft_printf.h"
int handle_c(va_list list, t_block *block)
{
	(void)block;
	char c = va_arg(list, int);
	write(1, &c, 1);
	return(1);
}
int handle_s(va_list list, t_block *block)
{
	(void)block;
	char *s = va_arg(list, char*);
	ft_putstr(s);
	return(ft_strlen(s));
}
int handle_p(va_list list, t_block *block)
{
	(void)block;
	void *p = va_arg(list, void*);
	write(1, "0x", 2);
	unsigned long long n = (unsigned long long)p;
	int places = 0;
	print_in_base_x_and_count_digits(n, 16, 'a', &places);
	return (places + 2);
}
int handle_o(va_list list, t_block *block)
{
	unsigned long long num = handle_unsigned_len(list, block);
	int places = 0;
	print_in_base_x_and_count_digits(num, 8, 'a', &places);
	return (places);
}

int handle_d(va_list list, t_block *block)
{
	long long num = handle_signed_len(list, block);
	int places = 0;
	num = convert_to_unsigned(num, block);
	places = places_with_base_x(num, 10);
	// printf("places = %d\n", places);
	int count = 0;
	handle_prec(block, places);
	print_in_base_x_and_count_digits(num, 10, 'a', &count);
	return (places + block->is_neg + (block->prec > places ? block->prec - places : places));
}