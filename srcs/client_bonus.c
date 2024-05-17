/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:18:07 by your_name         #+#    #+#             */
/*   Updated: 2024/05/17 14:53:17 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

char	backslash_check(char c)
{
	if (c == '0')
		return ('\0');
	if (c == 'a')
		return ('\a');
	if (c == 'b')
		return ('\b');
	if (c == 't')
		return ('\t');
	if (c == 'n')
		return ('\n');
	if (c == 'v')
		return ('\v');
	if (c == 'f')
		return ('\f');
	if (c == 'r')
		return ('\r');
	if (c == '\\')
		return ('\\');
	return (c);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

void	ft_atob(int pid, char c)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 8)
	{
		if (c & (1 << bit_index))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit_index++;
	}
}

void	confirm_receipt(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message received by server\n", 27);
	exit(0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, confirm_receipt);
	while (argv[2][i])
	{
		if (argv[2][i] == '\\')
		{
			i++;
			ft_atob(pid, backslash_check(argv[2][i]));
		}
		else
			ft_atob(pid, argv[2][i]);
		i++;
	}
	ft_atob(pid, '\0');
	pause();
	return (0);
}
