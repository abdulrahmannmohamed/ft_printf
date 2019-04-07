#include "ft_printf.h"
void parse_specifier(va_list list, const char *format, t_block *block)
{
	const char *key = "cspdiouxXf%";
	char *pointer_to_spec;

	pointer_to_spec = ft_strchr(key, *format);
	if (pointer_to_spec)
	{
		block->specifier = pointer_to_spec - key;
		// block->specifier = *format;
		block->valid = 1;
		// *format++;
	}
	(void)(list);
	// if (block->valid)
	// 	call_handler(list, block);

}