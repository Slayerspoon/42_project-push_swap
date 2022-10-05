/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:52:09 by aionescu          #+#    #+#             */
/*   Updated: 2021/11/06 20:06:53 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_duplicates_check(int argc, char **argv)
{
	int		main_index;
	int		sec_index;
	int		length;

	main_index = 1;
	while (main_index < argc - 1)
	{
		sec_index = main_index + 1;
		while (sec_index < argc)
		{
			if (ft_strlen(argv[main_index]) == ft_strlen(argv[sec_index]))
			{
				length = ft_strlen(argv[main_index]);
				if (ft_strncmp(argv[main_index], argv[sec_index], length) == 0)
					return (1);
			}
			sec_index++;
		}
		main_index++;
	}
	return (0);
}

int	arg_int_check(const char *arg)
{
	if (ft_strtonum(arg) < -2147483648 || 2147483647 < ft_strtonum(arg))
		return (1);
	if (ft_strlen(arg) > 11)
		return (1);
	return (0);
}

int	arg_number_check(const char *arg)
{
	int	index;

	index = 0;
	while (arg[index] != '\0')
	{
		if ((arg[0] == '-' && arg[1] == '0')
			|| (ft_strlen(arg) == 1 && (arg[0] < '0' || '9' < arg[0])))
			return (1);
		if (index == 0)
		{
			if ((arg[0] != '-' && (arg[0] < '1' || '9' < arg[0]))
				&& (arg[0] == '0' && arg[1] != '\0'))
				return (1);
		}
		else
		{
			if (arg[index] < '0' || '9' < arg[index])
				return (1);
		}
		index++;
	}
	if (index == 0)
		return (1);
	return (0);
}

int	main_error_check(int argc, char **argv)
{
	int	arg_num;

	arg_num = 1;
	while (arg_num < argc)
	{
		if (arg_number_check(argv[arg_num]) != 0)
			return (1);
		if (arg_int_check(argv[arg_num]) != 0)
			return (1);
		arg_num++;
	}
	if (arg_duplicates_check(argc, argv) != 0)
		return (1);
	return (0);
}
