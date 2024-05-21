/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:21:11 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/21 10:08:19 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minitalk.h"

static void	ft_reset(int signal)
{
	(void)signal;
	g_content.g_c = 0;
	g_content.g_bits = 0;
}

static void	ft_btoa(int signal, siginfo_t *info, void *context)
{
	alarm(1);
	(void)context;
	if (signal == SIGUSR1)
		g_content.g_c |= (1 << g_content.g_bits);
	g_content.g_bits++;
	if (g_content.g_bits == 8)
	{
		if (g_content.g_c == '\n')
			if (kill(info->si_pid, SIGUSR1) == -1)
				kill(info->si_pid, SIGUSR1);
		if (!(g_content.g_c > 0 && g_content.g_c < 8)
			|| g_content.g_c == 127
			|| (g_content.g_c > 13 && g_content.g_c < 32))
			ft_putchar_fd(g_content.g_c, 1);
		g_content.g_c = 0;
		g_content.g_bits = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	struct sigaction	sa_reset;

	(void)argv;
	if (argc != 1)
		ft_error("ERROR_ARGS");
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = ft_btoa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sa_reset.sa_handler = ft_reset;
	sigemptyset(&sa_reset.sa_mask);
	sa_reset.sa_flags = 0;
	if (sigaction(SIGALRM, &sa_reset, NULL) == -1)
		ft_error("ERROR_SIGNAL");
	while (1)
		pause();
	return (0);
}
