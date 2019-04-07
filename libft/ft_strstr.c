/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:26:04 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/25 10:26:05 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	int		ih;
	size_t	in;
	int		store;
	char	*ptr;

	ih = -1;
	if (!n[0])
		return ((char *)h);
	while (h[++ih])
	{
		if (h[ih] == n[0])
		{
			store = ih;
			ptr = (char *)&h[ih];
			in = 0;
			while ((n[in] == h[ih]) && h[ih] && n[in++])
				ih++;
			if (in == ft_strlen(n))
				return (ptr);
			ih = store;
		}
	}
	return (0);
}
