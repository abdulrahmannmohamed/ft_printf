
#include "ft_printf.h"


int call_handler(va_list list, t_block *block)
{
	int (*func[11])(va_list, t_block*);

	func[0] = handle_c;
	func[1] = handle_s;
	func[2] = handle_p;
	func[3] = handle_d;
	func[4] = handle_d;
	func[5] = handle_o;
	func[6] = handle_u;
	func[7] = handle_x;
	func[8] = handle_X;
	// func[9] = handle_f;
	// func[10] = handle_%;

	return (func[block->specifier](list, block));
}
void parser(va_list list, const char **format, t_block *block)
{
	// parse_flag(format, block);
	// parse_width(format, block);
	parse_precision(format, block);
	parse_len(format, block);
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
int ft_printf(const char *format, ...)
{
	t_block block;
	va_list list;
	int count = 0;

	ft_bzero(&block, sizeof(block));
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			parser(list, &format, &block);
			if (block.valid)
				count += call_handler(list, &block);
		}
		else
			count += put_basic(&format);
	}
	return (count);
}
