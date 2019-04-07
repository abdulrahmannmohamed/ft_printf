/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:16:53 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/29 11:16:55 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*srcc;
	unsigned char	*dstt;

	srcc = (unsigned char*)src;
	dstt = (unsigned char*)dst;
	if (srcc >= dstt)
	{
		i = 0;
		while (i < len)
		{
			dstt[i] = srcc[i];
			i++;
		}
	}
	else
	{
		while (len != 0)
		{
			dstt[len - 1] = srcc[len - 1];
			len--;
		}
	}
	return (dst);
}
