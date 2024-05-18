/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:30:34 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/18 15:42:23 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		negative;
	int		result;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		negative *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= negative;
	return (result);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

int	get_digits(long int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			digit_count;
	char		*result;
	long int	n_copy;

	n_copy = n;
	if (n_copy < 0)
		n_copy *= -1;
	digit_count = get_digits(n_copy);
	if (n < 0)
		digit_count++;
	result = malloc((digit_count + 1) * sizeof(char));
	if (!result)
		return (0);
	result[digit_count--] = '\0';
	while (digit_count >= 0)
	{
		result[digit_count--] = (n_copy % 10) + '0';
		n_copy /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
