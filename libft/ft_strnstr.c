/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:26:43 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/25 10:26:44 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t		ih;
	size_t		in;
	size_t		store;
	char		*ptr;

	ih = 0;
	if (!n[0])
		return ((char *)h);
	while (h[ih] && ih < len)
	{
		if (h[ih] == n[0])
		{
			store = ih;
			ptr = (char *)&h[ih];
			in = 0;
			while (n[in] && ih < len && (n[in] == h[ih++]))
				in++;
			if (in == ft_strlen(n))
				return (ptr);
			ih = store;
		}
		ih++;
	}
	return (NULL);
}
