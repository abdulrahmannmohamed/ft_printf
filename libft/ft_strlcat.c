/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:41:53 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/24 14:41:56 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	i1;
	size_t	x;
	size_t	i2;
	size_t	sum;

	idx = 0;
	i1 = ft_strlen(dst);
	x = i1;
	i2 = ft_strlen(src);
	sum = i1 + i2;
	while (src[idx] && i1 + 1 < (dstsize) && i1 < sum)
		dst[i1++] = src[idx++];
	if (dstsize > x)
		dstsize = x;
	dst[i1] = '\0';
	return (dstsize + i2);
}
