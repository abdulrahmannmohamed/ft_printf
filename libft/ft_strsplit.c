/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:09:10 by amohamed          #+#    #+#             */
/*   Updated: 2018/11/03 17:47:45 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_stuff(char const *s, char **res, int w_len, int w_i)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (w_len)
		res[w_i][k++] = s[i - w_len--];
	res[w_i][k] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	int		w_len;
	int		w_i;
	char	**res;
	int		count;

	w_i = 0;
	count = ft_w_count(s, c);
	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char*) * (count + 1))))
		return (0);
	while (*s && w_i < count)
	{
		w_len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c && s++)
			w_len++;
		if (!(res[w_i] = (char*)malloc(sizeof(char) * (w_len + 1))))
			return (0);
		ft_stuff(s++, res, w_len, w_i++);
	}
	res[w_i] = 0;
	return (res);
}
