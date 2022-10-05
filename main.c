/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:54:45 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/14 15:51:21 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*generate_a(int argc, char **argv)
{
	int	*a;
	int	index;

	a = malloc(sizeof(int) * (argc - 1));
	index = 0;
	while (index < argc - 1)
	{
		a[index] = ft_atoi(argv[index + 1]);
		index++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	if (main_error_check(argc, argv) != 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a.stack = generate_a(argc, argv);
	a.s_size = argc - 1;
	b.stack = malloc(0);
	b.s_size = 0;
	if (argc <= 4)
		push_swap_upto_3(&a, 'a');
	else if (argc <= 6)
		push_swap_upto_5(&a, &b);
	else
		push_swap_unlimited_v6(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}
