/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:40:12 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/22 11:52:02 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minitalk.h"

t_content	g_content;

static void	ft_characterreceived(int signal)
{
	(void)signal;
	if (signal == SIGUSR2)
		g_content.g_charactersent = 1;
}

static void	ft_atob(int pid, char c)
{
	g_content.g_bits = 0;
	while (g_content.g_bits < 8)
	{
		if (c & (1 << g_content.g_bits))
		{
			if (kill(pid, SIGUSR1) == -1)
				if (kill(pid, SIGUSR1) == -1)
					kill(pid, SIGUSR1);
		}
		else if (kill(pid, SIGUSR2) == -1)
			if (kill(pid, SIGUSR2) == -1)
				kill(pid, SIGUSR2);
		g_content.g_bits++;
		usleep(100);
	}
	if (g_content.g_charactersent == 0)
		usleep(1000010);
	else
		usleep(500);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		ft_error("ERROR_ARGS");
	g_content.g_pid = ft_atoi(argv[1]);
	if (signal(SIGUSR2, &ft_characterreceived) == SIG_ERR)
		ft_error("ERROR_SIGNAL");
	g_content.g_ack = 0;
	g_content.g_i = 0;
	while (argv[2][g_content.g_i])
	{
		if (!((argv[2][g_content.g_i] > 0 && argv[2][g_content.g_i] < 8)
			|| argv[2][g_content.g_i] == 127
			|| (argv[2][g_content.g_i] > 13 && argv[2][g_content.g_i] < 32)))
			ft_atob(g_content.g_pid, argv[2][g_content.g_i]);
		usleep(500);
		if (g_content.g_charactersent)
		{
			g_content.g_charactersent = 0;
			g_content.g_i++;
		}
	}
	ft_atob(g_content.g_pid, '\n');
	while (!g_content.g_ack)
		pause();
	return (0);
}
