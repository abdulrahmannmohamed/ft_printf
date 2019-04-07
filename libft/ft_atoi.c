/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 22:21:03 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/24 22:21:11 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		idx;
	int		flag;
	int		res;

	res = 0;
	idx = 0;
	flag = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+')
		idx++;
	else if (str[idx] == '-')
	{
		flag = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + (str[idx] - '0');
		idx++;
	}
	return (res * flag);
}
