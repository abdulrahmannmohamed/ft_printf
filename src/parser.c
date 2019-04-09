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