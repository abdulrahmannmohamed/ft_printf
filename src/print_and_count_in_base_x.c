#include "ft_printf.h"

int places_with_base_x(unsigned long long x, int base)
{
	int count;

	count = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		count++;
		x /= base;
	}
	return (count);
}

void print_in_base_x(unsigned long long n, int base, char c)
{
	if (n >= (unsigned long long)base)
	{
		print_in_base_x(n / base, base, c);
		print_in_base_x(n % base, base, c);
	}
	else
		ft_putchar((n % base > 9) ? (n % base - 10 + c) : (n % base + '0'));
}