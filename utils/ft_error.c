/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:21:45 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/19 21:28:05 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minitalk.h"

void	ft_error(char *error)
{
	ft_putstr_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
