#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

#define HH 1
#define H 2
#define LL 3
#define L 4

typedef struct 	s_block
{
	// int 	dot?
	int 	printed_sign_char;
	int 	is_neg;
	int		plus_flag;
	int 	neg_flag;
	int 	space_flag;
	int 	hash_flag;
	int 	zero_flag;
	int 	width;
	int 	is_there_prec;
	int 	prec;
	int 	len;
	int		specifier;
	int 		valid;
} 				t_block;

int ft_printf(const char *format, ...);

int handle_c(va_list list, t_block *block);
int handle_s(va_list list, t_block *block);
int handle_p(va_list list, t_block *block);
int handle_d(va_list list, t_block *block);
int handle_o(va_list list, t_block *block);
int handle_u(va_list list, t_block *block);
int handle_x(va_list list, t_block *block);
int handle_X(va_list list, t_block *block);
int handle_perc(va_list list, t_block *block);

int		ft_atoi_move_str_start_pos(const char **str);

void parse_flag(const char **format, t_block *block);
void parse_width(const char **format, t_block *block);
void parse_precision(const char **format, t_block *block);
void parse_len(const char **format, t_block *block);
void parse_specifier(va_list list, const char **format, t_block *block);

char *set_sign(t_block *block);
void flag_manager(t_block *block);
void handle_width(t_block *block, int *places);
void handle_prec(t_block *block, int *places);
long long handle_signed_len(va_list list, t_block *block);
long long handle_unsigned_len(va_list list, t_block *block);

long long convert_to_unsigned(long long num, t_block *block);

// char *convert_decimal_to_base_x(unsigned long long n, int places, int base, char c);
int places_with_base_x(unsigned long long x, int base);
void print_in_base_x_and_count_digits(unsigned long long n, int base, char c, int* places);
// void print_nbr_and_count_digits(long long n, int base, char c, int* places);
#endif