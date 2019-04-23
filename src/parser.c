/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:23:43 by amohamed          #+#    #+#             */
/*   Updated: 2019/04/22 23:23:46 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_specifier(va_list list, const char **format, t_block *block)
{
	const char	*key = "cspdiouxXq%";
	char		*pointer_to_spec;

	pointer_to_spec = ft_strchr(key, **format);
	if (pointer_to_spec)
	{
		block->specifier = pointer_to_spec - key;
		block->valid = 1;
		(*format)++;
	}
	(void)(list);
}

void	parse_len(const char **format, t_block *block)
{
	if (ft_strnstr(*format, "hh", 2))
		block->len = HH;
	else if (**format == 'h')
		block->len = H;
	else if (ft_strnstr(*format, "ll", 2))
		block->len = LL;
	else if (**format == 'l')
		block->len = L;
	if (block->len)
	{
		if (block->len == HH || block->len == LL)
			(*format) += 2;
		else
			(*format) += 1;
	}
}

void	parse_precision(const char **format, t_block *block)
{
	int		idx;
	int		res;

	res = 0;
	idx = 0;
	if (**format == '.')
	{
		block->is_there_prec = 1;
		(*format)++;
		while ((*format)[idx] >= '0' && (*format)[idx] <= '9')
		{
			res = res * 10 + ((*format)[idx] - '0');
			idx++;
		}
		*format += idx;
		block->prec = res;
	}
}

void	parse_width(const char **format, t_block *block)
{
	int		idx;
	int		res;

	res = 0;
	idx = 0;
	while ((*format)[idx] >= '0' && (*format)[idx] <= '9')
	{
		res = res * 10 + ((*format)[idx] - '0');
		idx++;
	}
	*format += idx;
	block->width = res;
}

void	parse_flag(const char **format, t_block *block)
{
	while (ft_strchr("+-0# ", **format))
	{
		if (**format == '0')
			block->zero_flag = 1;
		else if (**format == '+')
			block->plus_flag = 1;
		else if (**format == '-')
			block->neg_flag = 1;
		else if (**format == '#')
			block->hash_flag = 1;
		else if (**format == ' ')
			block->space_flag = 1;
		(*format)++;
	}
}
