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

void handle_c(va_list list);
void handle_s(va_list list);
void handle_p(va_list list);
void handle_d(va_list list);
void handle_o(va_list list);
void handle_u(va_list list);
void handle_x(va_list list);
void handle_X(va_list list);

void parse_specifier(va_list list, const char *format, t_block *block);

char *convert_decimal_to_base_x(unsigned long long n, int base, char c);

#endif