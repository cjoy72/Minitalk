/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:22:34 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/22 11:47:51 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_content
{
	int	g_i;
	int	g_characters;
	int	g_ack;
	int	g_c;
	int	g_bits;
	int	g_charactersent;
	int	g_pid;
}	t_content;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_error(char *error);

#endif
