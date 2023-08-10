/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:31:30 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/06 18:09:25 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long long	ft_atoll(const char *str)
{
	int			pos;
	long long	atoi;

	atoi = 0;
	pos = 1;
	while (*str == ' ' || ((*str >= '\t') && (*str <= '\r')))
		str++;
	if (*str == '-')
	{
		pos = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		atoi = atoi * 10 + (str[0] - '0');
		str++;
	}
	return (atoi * pos);
}

void	ft_print(t_philo *philo, unsigned int time, int id, int action)
{
	pthread_mutex_lock(&(philo->params->print));
	if (!get_any_dead(philo->params) && !ft_check_fed(philo->params))
	{
		if (action == 1)
			printf("%d %d is eating\n", time, id);
		if (action == 2)
			printf("%d %d is sleeping\n", time, id);
		if (action == 3)
			printf("%d %d is thinking\n", time, id);
		if (action == 4)
			printf("%d %d has taken a fork\n", time, id);
		if (action == 5)
			printf("%d %d has released a fork\n", time, id);
	}
	else if (!get_print(philo->params))
	{
		if (action == 7)
			printf("%d everyone finished their meals\n", time);
		else if (ft_check_fed(philo->params) == 0 && action == 6)
			printf("%d %d died\n", time, id);
		set_print(philo->params);
	}
	pthread_mutex_unlock(&(philo->params->print));
}

void	ft_free_struct(t_params *params)
{
	free(params->forks);
}

int	ft_isunsint(const char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) > 11)
		return (0);
	if ((str[0] == '+') && str[1] != '\0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (str[i] != '\0')
		return (0);
	if (ft_atoll(str) > INT_MAX || ft_atoll(str) < 0)
		return (0);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
