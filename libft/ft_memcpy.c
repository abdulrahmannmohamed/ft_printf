/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 00:42:10 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/29 00:42:13 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		((unsigned char*)dst)[idx] = ((unsigned char*)src)[idx];
		idx++;
	}
	return (dst);
}
