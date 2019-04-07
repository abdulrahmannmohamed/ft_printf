/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 11:20:10 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/28 20:07:05 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_stuff(char *s, int n, int len)
{
	int		flag;

	flag = 1;
	if (n == -2147483648)
	{
		flag = -1;
		s[len--] = 8 + '0';
		n = 214748364;
	}
	if (n < 0)
	{
		n *= -1;
		flag = -1;
	}
	while (n >= 10)
	{
		s[len--] = (n % 10) + '0';
		n /= 10;
	}
	if (n < 10)
	{
		s[len--] = n + '0';
	}
	return (flag);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*s;
	int		flag;

	len = ft_int_len(n) - 1;
	if (!(s = (char *)malloc(sizeof(char) * (len + 2))))
		return (0);
	s[len + 1] = '\0';
	flag = ft_stuff(s, n, len);
	if (flag == -1)
		s[0] = '-';
	return (s);
}
