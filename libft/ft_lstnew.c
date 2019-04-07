/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 21:26:37 by amohamed          #+#    #+#             */
/*   Updated: 2018/11/02 21:26:40 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_link;

	if (!(new_link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
		return (new_link);
	}
	if (!(new_link->content = (void*)malloc(content_size)))
		return (NULL);
	new_link->content = ft_memcpy(new_link->content, content, content_size);
	new_link->content_size = content_size;
	return (new_link);
}
