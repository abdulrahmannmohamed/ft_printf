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

int	handle_c(va_list list, t_block *block)
{
	int		places;
	char	c;
	char	padding;

	(void)block;
	padding = block->zero_flag ? '0' : ' ';
	c = va_arg(list, int);
	places = 1;
	while (!block->neg_flag && places < block->width)
	{
		write(1, &padding, 1);
		places++;
	}
	write(1, &c, 1);
	while (block->neg_flag && places < block->width)
	{
		write(1, " ", 1);
		places++;
	}
	return (places);
}

int	handle_s(va_list list, t_block *block)
{
	char	*s;
	int		places;
	int		num_of_spaces;
	int		num;

	s = va_arg(list, char*);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (block->prec || block->is_there_prec)
		places = (block->prec < (int)ft_strlen(s) ? block->prec : ft_strlen(s));
	else
		places = ft_strlen(s);
	num_of_spaces = block->width - places;
	num_of_spaces = num_of_spaces <= 0 ? 0 : num_of_spaces;
	num = places + num_of_spaces;
	while (!block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	write(1, s, places);
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (num);
}

int	handle_p(va_list list, t_block *block)
{
	unsigned long long	n;
	int					places;
	int					num_of_spaces;
	int					num_of_zeros;

	n = (unsigned long long)va_arg(list, void*);
	places = places_with_base_x(n, 16) + 2;
	num_of_zeros = block->prec - places + 2;
	num_of_zeros = num_of_zeros <= 0 ? 0 : num_of_zeros;
	num_of_spaces = block->width - places - num_of_zeros;
	num_of_spaces = num_of_spaces <= 0 ? 0 : num_of_spaces;
	places += num_of_spaces + num_of_zeros;
	if (!block->neg_flag)
		ft_print(' ', num_of_spaces);
	write(1, "0x", 2);
	ft_print('0', num_of_zeros);
	if (!(n == 0 && block->is_there_prec && block->prec == 0))
		print_in_base_x(n, 16, 'a');
	else
		places--;
	if (block->neg_flag)
		ft_print(' ', num_of_spaces);
	return (places);
}

int	handle_o(va_list list, t_block *block)
{
	char				c;
	int					num_of_zeros;
	int					num_of_spaces;
	unsigned long long	num;
	int					places;

	c = (block->zero_flag && !block->prec ? '0' : ' ');
	num = handle_unsigned_len(list, block);
	places = places_with_base_x(num, 8);
	if ((num == 0 && block->is_there_prec && block->prec == 0)
		|| (num == 0 && block->hash_flag))
		places--;
	o_helper(block, &places, &num_of_zeros, &num_of_spaces);
	while (!block->neg_flag && num_of_spaces--)
		write(1, &c, 1);
	while (num_of_zeros--)
		write(1, "0", 1);
	if (!((num == 0 && block->is_there_prec && block->prec == 0)
		|| (num == 0 && block->hash_flag)))
		print_in_base_x(num, 8, 'a');
	while (block->neg_flag && num_of_spaces--)
		write(1, " ", 1);
	return (places);
}

int	handle_d(va_list list, t_block *block)
{
	long long	num;
	int			places;
	int			num_of_zeros;
	int			num_of_spaces;

	num = handle_signed_len(list, block);
	num = convert_to_unsigned(num, block);
	places = places_with_base_x(num, 10);
	places = (num == 0 && block->is_there_prec
		&& block->prec == 0 ? 0 : places);
	flag_manager(block);
	d_helper(block, &places, &num_of_zeros, &num_of_spaces);
	if (!block->neg_flag && num_of_spaces)
		ft_print(' ', num_of_spaces);
	write(1, set_sign(block), 1);
	if (num_of_zeros)
		ft_print('0', num_of_zeros);
	if (!(num == 0 && block->is_there_prec && block->prec == 0))
		print_in_base_x(num, 10, 'a');
	if (block->neg_flag && num_of_spaces)
		ft_print(' ', num_of_spaces);
	return (places);
}
