/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:40:12 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/19 23:25:38 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minitalk.h"

int	g_ack = 0;

static void	ft_atob(int pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c & (1 << bits))
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("ERROR_KILL");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("ERROR_KILL");
		}
		usleep(100);
		bits++;
	}
}

static void	ft_ack_receive(int signal)
{
	if (signal == SIGUSR1)
	{
		g_ack = 1;
		ft_putstr_fd("Message received by server\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	if (argc != 3)
		ft_error("ERROR_ARGS");
	pid = ft_atoi(argv[1]);
	if (signal(SIGUSR1, &ft_ack_receive) == SIG_ERR)
		ft_error("ERROR_SIGNAL");
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
	while (!g_ack)
		pause();
	return (0);
}
