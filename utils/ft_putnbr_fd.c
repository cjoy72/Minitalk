/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:53:03 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/19 21:07:05 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	array[12];
	int		i;

	num = (long)n;
	i = 0;
	if (num == 0)
		write(fd, "0", 1);
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	while (num > 0)
	{
		array[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (--i >= 0)
		write(fd, array + i, 1);
}
