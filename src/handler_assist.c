#include "ft_printf.h"

int convert_to_unsigned(int num, int *places)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		(*places)++;
	}
	return (num);
}
