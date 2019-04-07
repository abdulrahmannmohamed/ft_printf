/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:02:23 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/23 15:02:25 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		idx;

	idx = 0;
	while (src[idx] && (idx < len))
	{
		dst[idx] = src[idx];
		idx++;
	}
	while (idx < len)
	{
		dst[idx++] = '\0';
	}
	return (dst);
}
