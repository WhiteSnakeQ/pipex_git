/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:45:07 by kreys             #+#    #+#             */
/*   Updated: 2023/11/01 16:19:24 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_string(long *number_print, const char *symbol, int *minus)
{
	int		stop_cheking;

	stop_cheking = 0;
	if ((symbol[0] == '+' || symbol[0] == '-') && *number_print == 0)
	{
		stop_cheking++;
		if (symbol[0] == '-')
			*minus = -*minus;
		symbol++;
	}
	while (*symbol)
	{
		if (symbol[0] >= '0' && symbol[0] <= '9')
		{
			*number_print *= 10;
			*number_print += symbol[0] - 48;
			stop_cheking++;
		}
		else if (*number_print > 0)
			return (1);
		else
			return (-1);
		symbol++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long		number_to_print;
	int			minus;
	int			play;

	minus = 1;
	number_to_print = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	play = check_string(&number_to_print, str, &minus);
	if (minus == -1)
		number_to_print = -number_to_print;
	return ((int)number_to_print);
}
