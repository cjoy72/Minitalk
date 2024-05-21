/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:59:19 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/21 15:26:29 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minitalk.h"

static void	ft_reset(int signal)
{
	(void)signal;
	g_content.g_c = 0;
	g_content.g_bits = 0;
}

static void	ft_btoa(int signal)
{
	struct itimerval	timer;
	
	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = 250000;
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL, &timer, NULL);
	if (signal == SIGUSR1)
		g_content.g_c |= (1 << g_content.g_bits);
	g_content.g_bits++;
	if (g_content.g_bits == 8)
	{
		if (!(g_content.g_c > 0 && g_content.g_c < 8)
			|| g_content.g_c == 127
			|| (g_content.g_c > 13 && g_content.g_c < 32))
			ft_putchar_fd(g_content.g_c, 1);
		g_content.g_c = 0;
		g_content.g_bits = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		ft_error("ERROR_ARGS");
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_handler = ft_btoa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGALRM, ft_reset);
	while (1)
		pause();
	return (0);
}
