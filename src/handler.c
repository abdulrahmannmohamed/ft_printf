#include "ft_printf.h"
# define MAX(x, y) x > y ? x : y
int handle_c(va_list list, t_block *block)
{
	int places = 1;
	(void)block;
	char c = va_arg(list, int);
	while (!block->neg_flag && places < block->width)
	{
		write(1, " ", 1);
		places++;
	}
	write(1, &c, 1);
	while (block->neg_flag && places < block->width)
	{
		write(1, " ", 1);
		places++;
	}
	return(places);
}
int handle_s(va_list list, t_block *block)
{
	char *s = va_arg(list, char*);
	int places = 0;
	if (block->prec)
		places = (block->prec < (int)ft_strlen(s) ? block->prec : ft_strlen(s));
	else
		places = ft_strlen(s);
	int num_of_spaces;
	num_of_spaces = block->width - places;
	num_of_spaces = num_of_spaces <= 0 ? 0 : num_of_spaces;
	int num = places + num_of_spaces;
	while (!block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	write(1, s, places);
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return(num);
}
int handle_p(va_list list, t_block *block)
{
	unsigned long long n = (unsigned long long)va_arg(list, void*);
	write(1, "0x", 2);
	int places = places_with_base_x(n, 16) + 2;
	int count = 0;
	int num_of_spaces;
	num_of_spaces = block->width - places;
	num_of_spaces = num_of_spaces <= 0 ? 0 : num_of_spaces;
	places += num_of_spaces;
	while (!block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	print_in_base_x_and_count_digits(n, 16, 'a', &count);
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (places);
}
void handle_o_helper(t_block *block, int *places, int *num_of_zeros, int *num_of_spaces)
{
	*num_of_zeros = block->prec - *places;
	*num_of_zeros = *num_of_zeros <= 0 ? 0 : *num_of_zeros;
	*num_of_zeros = (!(*num_of_zeros) && block->hash_flag) ? *num_of_zeros + 1 : *num_of_zeros;
	*num_of_spaces = block->width - (*places + *num_of_zeros);
	*num_of_spaces = *num_of_spaces <= 0 ? 0 : *num_of_spaces;
	*places += *num_of_spaces + *num_of_zeros;
}
int handle_o(va_list list, t_block *block)
{
	int num_of_zeros = 0;
	int num_of_spaces = 0;
	unsigned long long num = handle_unsigned_len(list, block);
	int places = places_with_base_x(num, 8);
	int count = 0;
	handle_o_helper(block, &places, &num_of_zeros, &num_of_spaces);
	while (!block->neg_flag && num_of_spaces--)
		write(1, &c, 1);
	while (num_of_zeros--)
		write(1, "0", 1);
	print_in_base_x_and_count_digits(num, 8, 'a', &count);
	while (block->neg_flag && num_of_spaces--)
		write(1, &c, 1);
	return (places);
}
void handle_d_helper(t_block *block, int *places, int *num_of_zeros, int *num_of_spaces)
{
	int is_there_printable_flag = 0;
	is_there_printable_flag = block->is_neg + block->plus_flag + block->space_flag;
	*places = is_there_printable_flag ? *places + 1 : *places;
	*num_of_zeros = block->prec - (*places - is_there_printable_flag);
	*num_of_zeros = *num_of_zeros <= 0 ? 0 : *num_of_zeros;
	*num_of_spaces = block->width - (*places + *num_of_zeros);
	*num_of_spaces = *num_of_spaces <= 0 ? 0 : *num_of_spaces;
	*places += *num_of_spaces + *num_of_zeros;
}
int handle_d(va_list list, t_block *block)
{
	long long num = handle_signed_len(list, block);
	int places = 0;
	int num_of_zeros = 0;
	int num_of_spaces = 0;

	num = convert_to_unsigned(num, block);
	places = places_with_base_x(num, 10);
	flag_manager(block);
	handle_d_helper(block, &places, &num_of_zeros, &num_of_spaces);
	while (!block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	write(1, set_sign(block), 1);
	int count = 0;
	while (num_of_zeros--)
		write(1, "0", 1);
	print_in_base_x_and_count_digits(num, 10, 'a', &count);
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (places);
}
