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
