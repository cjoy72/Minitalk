/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:59:19 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/20 22:38:06 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minitalk.h"

static void	ft_btoa(int signal)
{
	static int	c;
	static int	bits;

	if (signal == SIGUSR1)
		c |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		if (!(c > 0 && c < 8)
			|| c == 127
			|| (c > 13 && c < 32))
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
	sa.sa_handler = ft_btoa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("ERROR_SIGNAL");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error("ERROR_SIGNAL");
	while (1)
	{
		pause();
	}
	return (0);
}
