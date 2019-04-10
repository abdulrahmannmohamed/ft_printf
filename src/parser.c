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
int		ft_atoi_moving_string_address_past_nbr(const char **str)
{
	int		idx;
	int		flag;
	int		res;

	res = 0;
	idx = 0;
	flag = 1;
	while (((*str)[idx] >= 9 && (*str)[idx] <= 13) || (*str)[idx] == 32)
		idx++;
	if ((*str)[idx] == '+')
		idx++;
	else if ((*str)[idx] == '-')
	{
		flag = -1;
		idx++;
	}
	while ((*str)[idx] >= '0' && (*str)[idx] <= '9')
	{
		res = res * 10 + ((*str)[idx] - '0');
		idx++;
	}
	*str += idx;
	return (res * flag);
}
void parse_precision(const char **format, t_block *block)
{
	if (**format == '.')
	{
		block->is_there_prec = 1;
		(*format)++;
		block->prec = ft_atoi_moving_string_address_past_nbr(format);
	}
}