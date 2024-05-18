/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:32:39 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/18 15:42:41 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define END_TRANSMISSION '\0'

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
int		get_digits(long int n);
char	*ft_itoa(int n);

#endif
