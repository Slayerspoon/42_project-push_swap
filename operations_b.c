/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:02:39 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/04 00:13:47 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b)
{
	int	temp;

	if (b->s_size >= 2)
	{
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
	}
	write(1, "sb\n", 3);
}

void	pb_big_part(t_stack *b, t_stack *a)
{
	int	*new_b;
	int	*new_a;
	int	counter;

	new_b = (int *)malloc(sizeof(int) * (b->s_size + 1));
	new_a = (int *)malloc(sizeof(int) * (a->s_size - 1));
	counter = 0;
	while (counter < b->s_size && b->s_size > 0)
	{
		new_b[b->s_size - counter] = b->stack[b->s_size - counter - 1];
		counter++;
	}
	new_b[0] = a->stack[0];
	free(b->stack);
	b->stack = new_b;
	counter = 0;
	while (counter < a->s_size - 1)
	{
		new_a[a->s_size - 2 - counter] = a->stack[a->s_size - 1 - counter];
		counter++;
	}
	free(a->stack);
	a->stack = new_a;
	b->s_size++;
	a->s_size--;
}

void	pb(t_stack *b, t_stack *a)
{
	pb_big_part(b, a);
	write(1, "pb\n", 3);
}

void	rb(t_stack *b)
{
	int	temp;
	int	index;

	index = 0;
	temp = b->stack[0];
	while (index < b->s_size - 1)
	{
		b->stack[index] = b->stack[index + 1];
		index++;
	}
	b->stack[b->s_size - 1] = temp;
	write(1, "rb\n", 3);
}

void	rrb(t_stack *b)
{
	int	temp;
	int	index;

	index = 0;
	temp = b->stack[b->s_size - 1];
	while (index < b->s_size - 1)
	{
		b->stack[b->s_size - 1 - index] = b->stack[b->s_size - 1 - index - 1];
		index++;
	}
	b->stack[0] = temp;
	write(1, "rrb\n", 4);
}
