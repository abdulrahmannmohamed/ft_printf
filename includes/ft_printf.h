/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:23:14 by amohamed          #+#    #+#             */
/*   Updated: 2019/04/22 23:23:16 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# define HH 1
# define H 2
# define LL 3
# define L 4

typedef struct	s_block
{
	int		printed_sign_char;
	int		is_neg;
	int		plus_flag;
	int		neg_flag;
	int		space_flag;
	int		hash_flag;
	int		zero_flag;
	int		width;
	int		is_there_prec;
	int		prec;
	int		len;
	int		specifier;
	int		valid;
}				t_block;

int				ft_printf(const char *format, ...);

int				handle_c(va_list list, t_block *block);
int				handle_s(va_list list, t_block *block);
int				handle_p(va_list list, t_block *block);
int				handle_d(va_list list, t_block *block);
int				handle_o(va_list list, t_block *block);
int				handle_u(va_list list, t_block *block);
int				handle_x(va_list list, t_block *block);
int				handle_perc(va_list list, t_block *block);

void			u_helper(t_block *block, int *places,
				int *n_zeros, int *n_spaces);
void			x_helper(t_block *block, int *places,
				int *n_zeros, int *n_spaces);
void			o_helper(t_block *block, int *places,
				int *n_zeros, int *n_spaces);
void			d_helper(t_block *block, int *places,
				int *n_zeros, int *n_spaces);
void			ft_print(char c, int count);

void			parse_flag(const char **format, t_block *block);
void			parse_width(const char **format, t_block *block);
void			parse_precision(const char **format, t_block *block);
void			parse_len(const char **format, t_block *block);
void			parse_specifier(va_list list,
				const char **format, t_block *block);

char			*set_sign(t_block *block);
void			flag_manager(t_block *block);
long long		handle_signed_len(va_list list, t_block *block);
long long		handle_unsigned_len(va_list list, t_block *block);

long long		convert_to_unsigned(long long num, t_block *block);

int				places_with_base_x(unsigned long long x, int base);
void			print_in_base_x(unsigned long long n, int base, char c);

#endif
