/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:23:43 by amohamed          #+#    #+#             */
/*   Updated: 2019/04/22 23:23:46 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_helper(t_block *block, int *places, int *n_zeros, int *n_spaces)
{
	*n_zeros = block->prec - *places;
	*n_zeros = *n_zeros <= 0 ? 0 : *n_zeros;
	*n_spaces = block->width - *places - *n_zeros;
	*n_spaces = *n_spaces <= 0 ? 0 : *n_spaces;
	*places += *n_spaces + *n_zeros;
}

void	x_helper(t_block *block, int *places, int *n_zeros, int *n_spaces)
{
	int	hash_val;

	hash_val = (block->hash_flag ? 2 : 0);
	*n_zeros = block->zero_flag && !block->prec && !block->neg_flag
		? block->width - *places - hash_val : block->prec - *places;
	*n_zeros = *n_zeros <= 0 ? 0 : *n_zeros;
	*n_spaces = block->width - *places - *n_zeros - hash_val;
	*n_spaces = *n_spaces <= 0 ? 0 : *n_spaces;
	*places += *n_spaces + *n_zeros + hash_val;
}

void	o_helper(t_block *block, int *places, int *n_zeros, int *n_spaces)
{
	*n_zeros = block->prec - *places;
	*n_zeros = *n_zeros <= 0 ? 0 : *n_zeros;
	*n_zeros = (!(*n_zeros) && block->hash_flag) ? *n_zeros + 1 : *n_zeros;
	*n_spaces = block->width - (*places + *n_zeros);
	*n_spaces = *n_spaces <= 0 ? 0 : *n_spaces;
	*places += *n_spaces + *n_zeros;
}

void	d_helper(t_block *block, int *places, int *n_zeros, int *n_spaces)
{
	int	printable_flag;

	printable_flag = block->is_neg + block->plus_flag + block->space_flag;
	*places = printable_flag ? *places + 1 : *places;
	*n_zeros = ((block->zero_flag && !block->is_there_prec && !block->neg_flag)
		? block->width : block->prec) - (*places)
			+ (block->prec ? printable_flag : 0);
	*n_zeros = *n_zeros <= 0 ? 0 : *n_zeros;
	*n_spaces = block->width - (*places + *n_zeros);
	*n_spaces = *n_spaces <= 0 ? 0 : *n_spaces;
	*places += *n_spaces + *n_zeros;
}

void	ft_print(char c, int count)
{
	int		save;
	char	*s;

	save = count;
	if (count && (s = (char*)malloc(sizeof(char) * (count + 1))))
	{
		s[save] = '\0';
		while (count > 0)
			s[--count] = c;
		write(1, s, save);
		free(s);
	}
}
