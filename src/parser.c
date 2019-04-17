#include "ft_printf.h"
void parse_specifier(va_list list, const char **format, t_block *block)
{
	const char *key = "cspdiouxXf%";
	char *pointer_to_spec;

	pointer_to_spec = ft_strchr(key, **format);
	if (pointer_to_spec)
	{
		block->specifier = pointer_to_spec - key;
		block->valid = 1;
		(*format)++;
	}
	(void)(list);
	// if (block->valid)
	// 	call_handler(list, block);
}

void parse_len(const char **format, t_block *block)
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

void parse_precision(const char **format, t_block *block)
{
	if (**format == '.')
	{
		block->is_there_prec = 1;
		(*format)++;
		block->prec = ft_atoi_move_str_start_pos(format);
	}
}

void parse_width(const char **format, t_block *block)
{
	block->width = ft_atoi_move_str_start_pos(format);
}
#include<stdio.h>
void parse_flag(const char **format, t_block *block)
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
	// printf("zer:%dplus:%dneg:%dhash:%dspace:%d", block->zero_flag, block->plus_flag, block->neg_flag, block->hash_flag, block->space_flag);
}
