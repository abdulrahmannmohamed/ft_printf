#include "ft_printf.h"

int		ft_atoi_move_str_start_pos(const char **str)
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