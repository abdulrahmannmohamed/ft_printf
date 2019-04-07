
#include "ft_printf.h"


void call_handler(va_list list, t_block *block)
{
	void (*func[11])(va_list);

	func[0] = handle_c;
	func[1] = handle_s;
	func[2] = handle_p;
	func[3] = handle_d;
	func[4] = handle_d;
	// func[5] = handle_o;
	// func[5] = handle_u;
	// func[5] = handle_x;
	// func[5] = handle_X;
	// func[5] = handle_f;
	// func[5] = handle_%;

	func[block->specifier](list);
}

void parser(va_list list, const char *format, t_block *block)
{
	parse_specifier(list, format, block);
}
int put_basic(const char **format)
{
	int	print_len;

	print_len = 0;
	char *x = ft_strchr(*format, '%');
	print_len = x ? x - *format : ft_strlen(*format);
	write(1, *format, print_len);
	*format += print_len;
	return (print_len);
}
// #include <stdio.h>
int ft_printf(const char *format, ...)
{
	t_block block;
	va_list list;
	int count = 0;

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			parser(list, format, &block);
			if (block.valid)
			{
				call_handler(list, &block);
				format++;
			}
				// call_handler(&block, ap)
		}
		else
			count += put_basic(&format);
	}
	return (count);
}
