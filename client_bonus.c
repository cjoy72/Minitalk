/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:43:23 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/18 17:42:38 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = 0;
	while (i--)
	{
		temp_char = character >> i;
		if (temp_char & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	handle_read_receipt(int signal)
{
	if (signal == SIGUSR1)
		write(STDOUT_FILENO, "Received bit 1\n", 15);
	else if (signal == SIGUSR2)
		write(STDOUT_FILENO, "Received bit 0\n", 15);
}

int	main(int argc, char **argv)
{
	pid_t		server_pid;
	const char	*message;
	int			i;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [server_pid] [message]\n", STDOUT_FILENO);
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, handle_read_receipt);
	signal(SIGUSR2, handle_read_receipt);
	i = 0;
	while (message[i])
	{
		send_signal(server_pid, message[i++]);
	}
	send_signal(server_pid, '\0');
	return (0);
}
