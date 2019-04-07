/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 00:28:53 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/29 00:28:55 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(s, size);
	return ((void*)s);
}
