/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_ii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:37:17 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/14 16:09:14 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_next_smallest(t_stack stack, int smallest)
{
	int	i;
	int	next_smallest;

	next_smallest = get_max_in_stack(stack);
	i = 0;
	while (i < stack.s_size)
	{
		if (stack.stack[i] > smallest && stack.stack[i] < next_smallest)
			next_smallest = stack.stack[i];
		i++;
	}
	return (next_smallest);
}

int		check_if_stack_sorted(t_stack stack)
{
	int	previous_element;
	int	sorted;
	int	index;

	sorted = 1;
	if (stack.s_size > 0)
	{
		previous_element = stack.stack[0];
		index = 1;
		while (index < stack.s_size)
		{
			if (previous_element > stack.stack[index])
				sorted = 0;
			previous_element = stack.stack[index];
			index++;
		}
	}
	return (sorted);
}
