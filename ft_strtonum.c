/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtonum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:42:58 by aionescu          #+#    #+#             */
/*   Updated: 2021/10/27 19:47:11 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_beginning(const char *numstr, int *sign)
{
	int	index;

	index = 0;
	*sign = 1;
	while ((9 <= numstr[index] && numstr[index] <= 13) || numstr[index] == ' ')
		index++;
	if (numstr[index] == '+' || numstr[index] == '-')
	{
		index++;
		if (numstr[index - 1] == '-')
			*sign = -1;
	}
	return (index);
}

long long	ft_strtonum(const char *numstr)
{
	long long	number;
	int			index;
	int			sign;

	number = 0;
	sign = 1;
	index = handle_beginning(numstr, &sign);
	while (numstr[index] != '\0')
	{
		if (numstr[index] < '0' || '9' < numstr[index])
			break ;
		number = number * 10 + (numstr[index] - '0');
		index++;
	}
	number = sign * number;
	return ((long long)number);
}
