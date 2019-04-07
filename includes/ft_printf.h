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

void parse_specifier(va_list list, const char *format, t_block *block);
// void handle_(va_list list);


char *ptradd_to_hex(void *p, char c);

#endif