/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:33:19 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/27 20:33:25 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	int				i;
	unsigned int	end;

	end = start + len;
	if (!s)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (start < end)
	{
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}
