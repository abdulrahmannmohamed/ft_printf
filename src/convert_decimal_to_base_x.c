#include "ft_printf.h"

int places_with_base_x(unsigned long long x, int base)
{
	int count = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		count++;
		x /= base;
	}
	return (count);
}
// char *convert_decimal_to_base_x(unsigned long long n, int num_places, int base, char c)
// {
// 	// int num_places = places_with_base_x(n, base);
// 	char *s;
// 	if (!(s = (char *)ft_memalloc(num_places + 1)))
// 		return (NULL);
// 	while (n)
// 	{
// 		s[--num_places] = (n % base > 9) ? (n % base - 10 + c) : (n % base + '0');
// 		n /= base;
// 	}
// 	return (s);
// }

void print_in_base_x_and_count_digits(unsigned long long n, int base, char c, int* places)
{
	if (n >= (unsigned long long)base)
	{
		print_in_base_x_and_count_digits(n / base, base, c, places);
		print_in_base_x_and_count_digits(n % base, base, c, places);
	}
	else
	{
		(*places)++;
		ft_putchar((n % base > 9) ? (n % base - 10 + c) : (n % base + '0'));
	}
}