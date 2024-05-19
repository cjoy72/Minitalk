/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:40:12 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/20 01:05:55 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minitalk.h"

static void	ft_atob(int pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c & (1 << bits))
		{
			if (kill(pid, SIGUSR1) == -1)
				if(kill(pid, SIGUSR1 == -1)
					kill(pid, SIGUSR1);
			usleep(100);
		}		
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				if(kill(pid, SIGUSR2 == -1)
					kill(pid, SIGUSR2);
			usleep(100);
		}
		usleep(100);
		bits++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	if (argc != 3)
		ft_error("ERROR_ARGS");
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		if (!((argv[2][i] > 0 && argv[2][i] < 8)
			|| argv[2][i] == 127
			|| (argv[2][i] > 13 && argv[2][i] < 32)))
			ft_atob(pid, argv[2][i]);
		i++;
	}
	ft_atob(pid, '\n');
	return (0);
}
