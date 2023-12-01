/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:45:07 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 13:17:26 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	digit;
	char	to_write;

	digit = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		digit = -digit;
	}
	if (digit > 9)
	{
		to_write = digit % 10;
		ft_putnbr_fd(digit / 10, fd);
	}
	else
		to_write = digit;
	to_write += '0';
	write(fd, &to_write, 1);
}
