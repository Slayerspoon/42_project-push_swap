/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_unlimited_v6.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:46:12 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/14 16:18:08 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	generate_sorted_a(t_stack a)
{
	t_stack	sorted_a;
	int		index;
	int		*sorted_a_array;

	sorted_a_array = malloc(sizeof(int) * a.s_size);
	sorted_a.stack = sorted_a_array;
	sorted_a.s_size = a.s_size;
	sorted_a_array[0] = get_min_in_stack(a);
	index = 1;
	while (index < a.s_size)
	{
		sorted_a_array[index] = get_next_smallest(a, sorted_a_array[index - 1]);
		index++;
	}
	return (sorted_a);
}

int		is_in_lowest_chunk(int a_element, t_stack sorted_a, int chunk_size)
{
	int	is_in_chunk;
	int	index;

	is_in_chunk = 0;
	index = 0;
	while (index < chunk_size)
	{
		if (a_element == sorted_a.stack[index])
		{
			is_in_chunk = 1;
			break ;
		}
		index++;
	}
	return (is_in_chunk);
}

int		divide_and_push_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int		count;
	t_stack	sorted_a;

	sorted_a = generate_sorted_a(*a);
	count = 0;
	while (count < chunk_size && a->s_size > 0)
	{
		while (is_in_lowest_chunk(a->stack[0], sorted_a, chunk_size) == 0)
			ra(a);
		pb(b, a);
		count++;
	}
	free(sorted_a.stack);
	return (count);
}

void	push_rest_to_a(t_stack *a, t_stack *b, int total_size, int chunk_size)
{
	int	iterations;
	int	left_in_chunk;

	left_in_chunk = chunk_size;
	iterations = total_size / chunk_size;
	while (iterations > 0 && b->s_size > 0)
	{
		while (left_in_chunk > 0)
		{
			move_to_top_of_b(b, get_index_of_element(*b, get_max_in_stack(*b)));
			pa(a, b);
			left_in_chunk--;
		}
		left_in_chunk = chunk_size;
		iterations--;
	}
}

void	push_swap_unlimited_v6(t_stack *a, t_stack *b)
{
	int	last_chunk_size;
	int	chunk_size;
	int	total_size;

	total_size = a->s_size;
	chunk_size = 10 + (total_size - 100) / 15;
	if (check_if_stack_sorted(*a) == 0)
	{
		while (a->s_size > 0)
			last_chunk_size = divide_and_push_to_b(a, b, chunk_size);
		while (last_chunk_size > 0)
		{
			move_to_top_of_b(b, get_index_of_element(*b, get_max_in_stack(*b)));
			pa(a, b);
			last_chunk_size--;
		}
		push_rest_to_a(a, b, total_size, chunk_size);
	}
}
