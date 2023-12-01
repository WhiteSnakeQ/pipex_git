/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:28:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/11/01 18:47:50 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(long n, int minus)
{
	size_t	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	if (minus == 1)
		return ((size_t)(i + 1));
	return ((size_t)i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	int			minus;
	long int	num;

	minus = 0;
	num = n;
	if (n < 0 && minus++ == 0)
		num = -num;
	digits = get_digits(num, minus);
	str_num = malloc(sizeof(char) * (digits + 1));
	if (str_num == NULL)
		return (NULL);
	str_num[digits--] = '\0';
	while (num > 9)
	{
		str_num[digits--] = num % 10 + '0';
		num /= 10;
	}
	str_num[digits--] = num + '0';
	if (minus)
		str_num[digits--] = '-';
	return (str_num);
}
