/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:18:07 by your_name         #+#    #+#             */
/*   Updated: 2024/05/17 14:53:26 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int				bit_index = 0;
	static int				char_index = 0;
	static unsigned char	current_char = 0;
	static unsigned char	message[100000];

	(void)context;
	if (sig == SIGUSR1)
		current_char |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		message[char_index] = current_char;
		if (current_char == '\0')
		{
			write(1, (char *)message, char_index);
			write(1, "\n", 1);
			char_index = 0;
			kill(info->si_pid, SIGUSR1);
		}
		else
			char_index++;
		bit_index = 0;
		current_char = 0;
	}
}

void	ft_itoa(int n)
{
	char	c;

	if (n > 9)
		ft_itoa(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		write(1, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	pid = getpid();
	write(1, "SERVER PID: ", 12);
	ft_itoa(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = ft_btoa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
