#include "ft_printf.h"

long long convert_to_unsigned(long long num, t_block *block)
{
	if (num < 0)
	{
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