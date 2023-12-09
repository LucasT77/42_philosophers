/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:28:43 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/20 16:59:21 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			signal;
	int			i;

	res = 0;
	signal = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i += 1;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i += 1;
	}
	return (res * signal);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
