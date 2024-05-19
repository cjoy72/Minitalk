/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:30:48 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/19 19:56:09 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief    Sends 8 signals to the provided PID to transmit the
 * provided character bit by bit.
 * It starts from the MSB and progressively goes to the LSB.
 *
 * It sends SIGUSR1 if the bit is 1, SIGUSR2 if it is 0.
 *
 * @param    pid       server's PID
 * @param    character character to transmit
 */

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i--)
	{
		temp_char = character >> i;
		if (temp_char & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
	}
}

int	main(int argc, char **argv)
{
	pid_t		server_pid;
	int			i;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [server_pid] [message]\n", STDOUT_FILENO);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
		send_signal(server_pid, argv[2][i++]);
	send_signal(server_pid, '\0');
	return (0);
}
