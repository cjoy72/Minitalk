/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:43:35 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/18 17:43:16 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_index = 0;

	(void)context;
	if (signal == SIGUSR1)
		current_char |= 1 << (7 - bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
			write(STDOUT_FILENO, "\n", 1);
		else
			write(STDOUT_FILENO, &current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
	if (kill(info->si_pid, signal) == -1)
	{
		write(STDOUT_FILENO, "Error: Unable to send signal\n", 29);
		exit(1);
	}
}

int	main(void)
{
	struct sigaction	action;
	char				*pid;

	pid = ft_itoa(getpid());
	write(STDOUT_FILENO, "Server PID: ", 12);
	write(STDOUT_FILENO, pid, ft_strlen(pid));
	write(STDOUT_FILENO, "\n", 1);
	action.sa_sigaction = handle_signal;
	action.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&action.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
}
