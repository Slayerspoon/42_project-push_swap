/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_upto_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:04:02 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/06 18:47:13 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps3_min_at_0(t_stack *stack, char stack_letter)
{
	if (stack_letter == 'a')
	{
		if (stack->stack[1] > stack->stack[2])
		{
			sa(stack);
			ra(stack);
		}
	}
	else
	{
		if (stack->stack[1] > stack->stack[2])
		{
			sb(stack);
			rb(stack);
		}
	}
}

void	ps3_min_at_1(t_stack *stack, char stack_letter)
{
	if (stack_letter == 'a')
	{
		if (stack->stack[0] < stack->stack[2])
			sa(stack);
		else
			ra(stack);
	}
	else
	{
		if (stack->stack[0] < stack->stack[2])
			sb(stack);
		else
			rb(stack);
	}
}

void	ps3_min_at_2(t_stack *stack, char stack_letter)
{
	if (stack_letter == 'a')
	{
		if (stack->stack[0] < stack->stack[1])
			rra(stack);
		else
		{
			sa(stack);
			rra(stack);
		}
	}
	else
	{
		if (stack->stack[0] < stack->stack[1])
			rrb(stack);
		else
		{
			sb(stack);
			rrb(stack);
		}
	}
}

void	push_swap_upto_3(t_stack *stack, char stack_letter)
{
	int	index_of_min;

	if (stack->s_size == 2)
	{
		if (stack->stack[0] > stack->stack[1])
		{
			if (stack_letter == 'a')
				sa(stack);
			else
				sb(stack);
		}
	}
	else
	{
		index_of_min = get_index_of_element(*stack, get_min_in_stack(*stack));
		if (index_of_min == 0)
			ps3_min_at_0(stack, stack_letter);
		else if (index_of_min == 1)
			ps3_min_at_1(stack, stack_letter);
		else
			ps3_min_at_2(stack, stack_letter);
	}
}
