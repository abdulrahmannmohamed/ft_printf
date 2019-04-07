/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:00:34 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/24 14:02:02 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		idx;
	size_t		i2;
	size_t		i1;

	i2 = ft_strlen(s2);
	idx = 0;
	i1 = ft_strlen(s1);
	while (s2[idx] && idx < n)
	{
		s1[i1] = s2[idx];
		i1++;
		idx++;
	}
	s1[i1] = '\0';
	return (s1);
}
