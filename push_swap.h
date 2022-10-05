/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:03:24 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/15 20:00:37 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_stack
{
	int	*stack;
	int	s_size;
}				t_stack;
void			sa(t_stack *a);
void			sb(t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *b, t_stack *a);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
int				main_error_check(int argc, char **argv);
long long		ft_strtonum(const char *numstr);
int				get_max_in_stack(t_stack stack);
int				get_min_in_stack(t_stack stack);
int				get_index_of_element(t_stack stack, int element);
void			move_to_top_of_a(t_stack *a, int index);
void			move_to_top_of_b(t_stack *b, int index);
int				get_next_smallest(t_stack stack, int smallest);
int				check_if_stack_sorted(t_stack stack);
void			push_swap_upto_3(t_stack *a, char stack_letter);
void			push_swap_upto_5(t_stack *a, t_stack *b);
void			push_swap_unlimited_v6(t_stack *a, t_stack *b);

#endif
