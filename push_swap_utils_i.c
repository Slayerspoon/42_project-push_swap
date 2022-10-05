/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:05:29 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/13 19:10:26 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_max_in_stack(t_stack stack)
{
	int	max;
	int	index;

	max = 0;
	if (stack.stack != NULL)
	{
		max = stack.stack[0];
		index = 1;
		while (index < stack.s_size)
		{
			if (max < stack.stack[index])
				max = stack.stack[index];
			index++;
		}
	}
	return (max);
}

int		get_min_in_stack(t_stack stack)
{
	int	min;
	int	index;

	min = 0;
	if (stack.stack != NULL)
	{
		min = stack.stack[0];
		index = 1;
		while (index < stack.s_size)
		{
			if (min > stack.stack[index])
				min = stack.stack[index];
			index++;
		}
	}
	return (min);
}

int		get_index_of_element(t_stack stack, int element)
{
	int	index;

	index = 0;
	while (stack.stack[index] != element)
		index++;
	return (index);
}

void	move_to_top_of_a(t_stack *a, int index)
{
	int	distance_up;
	int	distance_down;

	distance_up = index;
	distance_down = a->s_size - index;
	if (distance_up <= distance_down)
	{
		while (distance_up > 0)
		{
			ra(a);
			distance_up--;
		}
	}
	else
	{
		while (distance_down > 0)
		{
			rra(a);
			distance_down--;
		}
	}
}

void	move_to_top_of_b(t_stack *b, int index)
{
	int	distance_up;
	int	distance_down;

	distance_up = index;
	distance_down = b->s_size - index;
	if (distance_up <= distance_down)
	{
		while (distance_up > 0)
		{
			rb(b);
			distance_up--;
		}
	}
	else
	{
		while (distance_down > 0)
		{
			rrb(b);
			distance_down--;
		}
	}
}
