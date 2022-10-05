/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_upto_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:03:07 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/08 09:00:39 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_upto_5(t_stack *a, t_stack *b)
{
	int	min_a;
	int	max_a;

	if (check_if_stack_sorted(*a) == 0)
	{
		max_a = get_max_in_stack(*a);
		move_to_top_of_a(a, get_index_of_element(*a, max_a));
		pb(b, a);
		min_a = get_min_in_stack(*a);
		move_to_top_of_a(a, get_index_of_element(*a, min_a));
		pb(b, a);
		push_swap_upto_3(a, 'a');
		pa(a, b);
		pa(a, b);
		ra(a);
	}
}
