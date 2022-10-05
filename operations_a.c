/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:02:24 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/03 23:59:35 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->s_size >= 2)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
	}
	write(1, "sa\n", 3);
}

void	pa_big_part(t_stack *a, t_stack *b)
{
	int	*new_a;
	int	*new_b;
	int	counter;

	new_a = (int *)malloc(sizeof(int) * (a->s_size + 1));
	new_b = (int *)malloc(sizeof(int) * (b->s_size - 1));
	counter = 0;
	while (counter < a->s_size && a->s_size > 0)
	{
		new_a[a->s_size - counter] = a->stack[a->s_size - counter - 1];
		counter++;
	}
	new_a[0] = b->stack[0];
	free(a->stack);
	a->stack = new_a;
	counter = 0;
	while (counter < b->s_size - 1)
	{
		new_b[b->s_size - 2 - counter] = b->stack[b->s_size - 1 - counter];
		counter++;
	}
	free(b->stack);
	b->stack = new_b;
	a->s_size++;
	b->s_size--;
}

void	pa(t_stack *a, t_stack *b)
{
	pa_big_part(a, b);
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	int	temp;
	int	index;

	index = 0;
	temp = a->stack[0];
	while (index < a->s_size - 1)
	{
		a->stack[index] = a->stack[index + 1];
		index++;
	}
	a->stack[a->s_size - 1] = temp;
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	int	temp;
	int	index;

	index = 0;
	temp = a->stack[a->s_size - 1];
	while (index < a->s_size - 1)
	{
		a->stack[a->s_size - 1 - index] = a->stack[a->s_size - 1 - index - 1];
		index++;
	}
	a->stack[0] = temp;
	write(1, "rra\n", 4);
}
