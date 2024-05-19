/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:21:11 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/20 01:30:10 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minitalk.h"

static void	ft_btoa(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	bits;

	(void)context;
	if (signal == SIGUSR1)
		c |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		if (c == '\n')
			if (kill(info->si_pid, SIGUSR1) == -1)
				kill(info->si_pid, SIGUSR1);
		ft_putchar_fd(c, 1);
		c = 0;
		bits = 0;
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
	sa.sa_sigaction = ft_btoa;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("ERROR_SIGNAL");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error("ERROR_SIGNAL");
	while (1)
		pause();
	return (0);
}
