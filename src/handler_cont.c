#include "ft_printf.h"
void handle_u_helper(t_block *block, int *places, int *num_of_zeros, int *num_of_spaces)
{
	*num_of_zeros = block->prec - *places;
	*num_of_zeros = *num_of_zeros <= 0 ? 0 : *num_of_zeros;
	*num_of_spaces = block->width - *places - *num_of_zeros;
	*num_of_spaces = *num_of_spaces <= 0 ? 0 : *num_of_spaces;
	*places += *num_of_spaces + *num_of_zeros;
}
int handle_u(va_list list, t_block *block)
{
	int num_of_zeros = 0;
	int num_of_spaces = 0;
	unsigned long long num = handle_unsigned_len(list, block);
	int places = places_with_base_x(num, 10);
	
	int count = 0;
	handle_u_helper(block, &places, &num_of_zeros, &num_of_spaces);
	while (!block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	while (num_of_zeros--)
		write(1, "0", 1);
	print_in_base_x_and_count_digits(num, 10, 'a', &count);
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (places);
}
void handle_x_helper(t_block *block, int *places, int *num_of_zeros, int *num_of_spaces)
{
	*num_of_zeros = block->prec - *places;
	*num_of_zeros = *num_of_zeros <= 0 ? 0 : *num_of_zeros;
	*num_of_spaces = block->width - *places - *num_of_zeros - (block->hash_flag ? 2 : 0);
	*num_of_spaces = *num_of_spaces <= 0 ? 0 : *num_of_spaces;
	*places += *num_of_spaces + *num_of_zeros + (block->hash_flag ? 2 : 0);
}
int handle_x(va_list list, t_block *block)
{
	int num_of_zeros = 0;
	int num_of_spaces = 0;
	unsigned long long num = handle_unsigned_len(list, block);
	int places = places_with_base_x(num, 16);
	handle_x_helper(block, &places, &num_of_zeros, &num_of_spaces);
	int count = 0;
	while (!block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	if (block->hash_flag)
		write(1, "0x", 2);
	while (num_of_zeros--)
		write(1, "0", 1);
	print_in_base_x_and_count_digits(num, 16, 'a', &count);
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (places);
}
int handle_X(va_list list, t_block *block)
{
	int num_of_zeros = 0;
	int num_of_spaces = 0;
	unsigned long long num = handle_unsigned_len(list, block);
	int places = places_with_base_x(num, 16);
	handle_x_helper(block, &places, &num_of_zeros, &num_of_spaces);
	int count = 0;
	while (!block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	if (block->hash_flag)
		write(1, "0X", 2);
	while (num_of_zeros--)
		write(1, "0", 1);
	print_in_base_x_and_count_digits(num, 16, 'A', &count);
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (places);
}
int handle_perc(va_list list, t_block *block)
{
	(void)block;
	(void)list;
	write(1, "%", 1);
	return (1);
}