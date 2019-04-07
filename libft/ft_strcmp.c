/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 22:32:15 by amohamed          #+#    #+#             */
/*   Updated: 2018/10/25 10:27:29 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int	idx;

	idx = 0;
	if (!s1[idx])
		return (-((unsigned char)s2[idx]));
	while (s1[idx])
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx++;
	}
	if (s2[idx])
		return (-((unsigned char)s2[idx]));
	return (0);
}
