/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:28:54 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/25 10:28:55 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		idx;

	idx = 0;
	if (!s1[idx])
		return (-((unsigned char)s2[idx]));
	while (s1[idx] && (idx < n))
	{
		if (s1[idx] != s2[idx])
		{
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		}
		idx++;
	}
	if (s2[idx] && idx < n)
		return (-((unsigned char)s2[idx]));
	return (0);
}
