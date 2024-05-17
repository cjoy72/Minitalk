/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:17:33 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/17 14:52:10 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

// Client
char	backslash_check(char c);
int		ft_atoi(const char *str);
void	ft_atob(int pid, char c);
void	confirm_receipt(int sig);
// Server
void	ft_btoa(int sig, siginfo_t *info, void *context);
void	ft_itoa(int n);

#endif
