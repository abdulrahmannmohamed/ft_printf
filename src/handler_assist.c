#include "ft_printf.h"

long long convert_to_unsigned(long long num, t_block *block)
{
	if (num < 0)
	{
		// write(1, "-", 1);
		num *= -1;
		block->is_neg = 1;
	}
	return (num);
}
long long handle_signed_len(va_list list, t_block *block)
{
	long long n;
	if (block->len == HH)
		n = (signed char)va_arg(list, int);
	else if (block->len == H)
		n = (short int)va_arg(list, int);
	else if (block->len == L)
		n = va_arg(list, long);
	else if (block->len == LL)
		n = va_arg(list, long long);
	else
		n = va_arg(list, int);
	return (n);
}
long long handle_unsigned_len(va_list list, t_block *block)
{
	long long n;
	if (block->len == HH)
		n = (unsigned char)va_arg(list, int);
	else if (block->len == H)
		n = (unsigned short int)va_arg(list, int);
	else if (block->len == L)
		n = va_arg(list, unsigned long);
	else if (block->len == LL)
		n = va_arg(list, unsigned long long);
	else
		n = va_arg(list, unsigned int);
	return (n);
}
void flag_manager(t_block *block)
{
	if (block->is_neg)
	{
		block->plus_flag = 0;
		block->space_flag = 0;
	}
	else if (block->plus_flag)
		block->space_flag = 0;
}
char *set_sign(t_block *block)
{
	char *sign = NULL;
	if (block->is_neg)
		sign = "-";
	else if (block->plus_flag)
		sign = "+";
	else if (block->space_flag)
		sign = " ";
	return (sign);
}
void handle_prec(t_block *block, int *places)
{
// 	int num_of_zeros = 0;
// 	int num_of_spaces = 0;
// 	int is_there_a_printed_flag = block->is_neg + block->plus_flag + block->space_flag;
// 	places = is_there_a_printed_flag ? *places + 1 : *places;
// 	num_of_zeros = block->prec - (*places - is_there_a_printed_flag);
// 	num_of_zeros = num_of_zeros <= 0 ? 0 : num_of_zeros;
// 	num_of_spaces = block->width - (places + num_of_zeros);
// 	num_of_spaces = num_of_spaces <= 0 ? 0 : num_of_spaces;
// 	places += num_of_spaces + num_of_zeros;
// 	while (!block->neg_flag && num_of_spaces--)
// 		write(1, " ", 1);
// 	write(1, set_sign(block), 1);
// 	int count = 0;
// 	while (num_of_zeros--)
// 		write(1, "0", 1);
// 	print_in_base_x_and_count_digits(num, 10, 'a', &count);
// 	while (block->neg_flag && num_of_spaces--)
// 		write(1, " ", 1);
// }



	int num_of_zeros = 0;
	int num_of_spaces = 0;

	if (block->prec > *places)
	{
		num_of_zeros = block->prec - *places;
		*places = block->prec;
	}
	if (block->width > *places)
		num_of_spaces = block->width - *places;
	if (!block->neg_flag)
		while (num_of_spaces--)
		{
			write(1, " ", 1);
			(*places)++;
		}
	if (!block->is_neg)
	{
		if (block->plus_flag)
		{
			write(1, "+", 1);
			places++;
		}
		else if (block->space_flag)
		{
			write(1, " ", 1);
			places++;
		}
	}
	while (num_of_zeros--)
		write(1, "0", 1);
} 

void handle_width(t_block *block, int *places)
{
	while (*places < block->width)
	{
		write(1, " ", 1);
		(*places)++;
	}
}