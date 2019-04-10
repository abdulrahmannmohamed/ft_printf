#include "ft_printf.h"

int convert_to_unsigned(int num, t_block *block)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		// (*places)++;
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

void handle_prec(t_block *block, int places)
{
	while (places < block->prec)
		{
			write(1, "0", 1);
			places++;
		}
}