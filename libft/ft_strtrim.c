/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:49:10 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/27 11:49:14 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		beg;
	int		end;
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	end = (int)ft_strlen(s) - 1;
	beg = 0;
	while (ft_isspace(s[beg]) && (beg <= end + 1))
		beg++;
	while (ft_isspace(s[end]) && (end != beg - 1))
		end--;
	if (!(res = (char *)malloc(end - beg + 2)))
		return (0);
	i = 0;
	while (beg <= end)
	{
		res[i++] = s[beg++];
	}
	res[i] = '\0';
	return (res);
}
