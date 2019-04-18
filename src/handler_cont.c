#include "ft_printf.h"

int handle_u(va_list list, t_block *block)
{
	char c;
	int num_of_zeros;
	int num_of_spaces;
	unsigned long long num;
	int places;
	
	num = handle_unsigned_len(list, block);
	places = places_with_base_x(num, 10);
	c = (block->zero_flag && !block->prec ? '0' : ' ');
	handle_u_helper(block, &places, &num_of_zeros, &num_of_spaces);
	while (!block->neg_flag && num_of_spaces--)
		write(1, &c, 1);
	while (num_of_zeros--)
		write(1, "0", 1);
	print_in_base_x(num, 10, 'a');
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (places);
}

int handle_x(va_list list, t_block *block)
{
	int num_of_zeros;
	int num_of_spaces;
	unsigned long long num;
	int places;

	num = handle_unsigned_len(list, block);
	places = places_with_base_x(num, 16);
	places = (num == 0 && block->is_there_prec && block->prec == 0 ? 0 : places);
	handle_x_helper(block, &places, &num_of_zeros, &num_of_spaces);
	while (!block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	if (block->hash_flag && num != 0)
		write(1, "0x", 2);
	if (block->hash_flag && num == 0)
		places -= 2;
	while (num_of_zeros--)
		write(1, "0", 1);
	if (!(num == 0 && block->is_there_prec && block->prec == 0))
		print_in_base_x(num, 16, 'a');
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (places);
}
int handle_X(va_list list, t_block *block)
{
	int num_of_zeros;
	int num_of_spaces;
	unsigned long long num;
	int places;

	num = handle_unsigned_len(list, block);
	places = places_with_base_x(num, 16);
	places = (num == 0 && block->is_there_prec && block->prec == 0 ? 0 : places);
	handle_x_helper(block, &places, &num_of_zeros, &num_of_spaces);
	while (!block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	if (block->hash_flag)
		write(1, "0X", 2);
	while (num_of_zeros--)
		write(1, "0", 1);
	if (!(num == 0 && block->is_there_prec && block->prec == 0))
		print_in_base_x(num, 16, 'A');
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (places);
}
int handle_perc(va_list list, t_block *block)
{
	int num_of_zeros;
	int num_of_spaces;
	char c;
	int ret;

	c = (block->zero_flag && !block->prec ? '0' : ' ');
	num_of_zeros = block->prec - 1;
	num_of_zeros = num_of_zeros <= 0 ? 0 : num_of_zeros;
	num_of_spaces = block->width - 1 - num_of_zeros;
	num_of_spaces = num_of_spaces <= 0 ? 0 : num_of_spaces;
	ret = 1 + num_of_zeros + num_of_spaces;
	(void)list;
	while (!block->neg_flag && num_of_spaces--)
		write(1, &c, 1);
	while (num_of_zeros--)
		write(1, "0", 1);
	write(1, "%", 1);
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (ret);
}