#include "ft_printf.h"

void handle_u_helper(t_block *block, int *places, int *num_of_zeros, int *num_of_spaces)
{
	*num_of_zeros = block->prec - *places;
	*num_of_zeros = *num_of_zeros <= 0 ? 0 : *num_of_zeros;
	*num_of_spaces = block->width - *places - *num_of_zeros;
	*num_of_spaces = *num_of_spaces <= 0 ? 0 : *num_of_spaces;
	*places += *num_of_spaces + *num_of_zeros;
}

void handle_x_helper(t_block *block, int *places, int *num_of_zeros, int *num_of_spaces)
{
	int hash_val;

	hash_val = (block->hash_flag ? 2 : 0);
	*num_of_zeros = block->zero_flag  && !block->prec && !block->neg_flag ? block->width - *places - hash_val : block->prec - *places;
	*num_of_zeros = *num_of_zeros <= 0 ? 0 : *num_of_zeros;
	*num_of_spaces = block->width - *places - *num_of_zeros - hash_val;
	*num_of_spaces = *num_of_spaces <= 0 ? 0 : *num_of_spaces;
	*places += *num_of_spaces + *num_of_zeros + hash_val;
}

void handle_o_helper(t_block *block, int *places, int *num_of_zeros, int *num_of_spaces)
{
	*num_of_zeros = block->prec - *places;
	*num_of_zeros = *num_of_zeros <= 0 ? 0 : *num_of_zeros;
	*num_of_zeros = (!(*num_of_zeros) && block->hash_flag) ? *num_of_zeros + 1 : *num_of_zeros;
	*num_of_spaces = block->width - (*places + *num_of_zeros);
	*num_of_spaces = *num_of_spaces <= 0 ? 0 : *num_of_spaces;
	*places += *num_of_spaces + *num_of_zeros;
}

void handle_d_helper(t_block *block, int *places, int *num_of_zeros, int *num_of_spaces)
{
	int is_there_printable_flag;
	
	is_there_printable_flag = block->is_neg + block->plus_flag + block->space_flag;
	*places = is_there_printable_flag ? *places + 1 : *places;
	*num_of_zeros = ((block->zero_flag && !block->is_there_prec && !block->neg_flag) ? block->width : block->prec) - (*places) + (block->prec ? is_there_printable_flag : 0);
	*num_of_zeros = *num_of_zeros <= 0 ? 0 : *num_of_zeros;
	*num_of_spaces = block->width - (*places + *num_of_zeros);
	*num_of_spaces = *num_of_spaces <= 0 ? 0 : *num_of_spaces;
	*places += *num_of_spaces + *num_of_zeros;
}