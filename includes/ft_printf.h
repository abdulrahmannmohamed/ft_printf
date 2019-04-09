#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct 	s_block
{
	int		specifier;
	int 		valid;
} 				t_block;

int ft_printf(const char *format, ...);

int handle_c(va_list list);
int handle_s(va_list list);
int handle_p(va_list list);
int handle_d(va_list list);
int handle_o(va_list list);
int handle_u(va_list list);
int handle_x(va_list list);
int handle_X(va_list list);

void parse_specifier(va_list list, const char *format, t_block *block);

// char *convert_decimal_to_base_x(unsigned long long n, int places, int base, char c);
// int places_with_base_x(unsigned long long x, int base);
void print_in_base_x_and_count_digits(unsigned long long n, int base, char c, int* places);
#endif