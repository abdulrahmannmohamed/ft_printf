#include "ft_printf.h"
int hex_places(unsigned long long x)
{
	int count = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		count++;
		x /= 16;
	}
	return (count);
}

char *ptradd_to_hex(void *p, char c)
{
	unsigned long long n = (unsigned long long)p;
	int num_places = hex_places(n);
	char *s;
	if (!(s = (char *)ft_memalloc(num_places + 1)))
		return (NULL);
	while (n)
	{
		s[--num_places] = (n % 16 > 9) ? (n % 16 - 10 + c) : (n % 16 + '0');
		n /= 16;
	}
	return (s);
}