/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:42:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/20 17:23:39 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_message(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->end);
	if (philo->data->the_end == 1)
	{
		pthread_mutex_unlock(&philo->data->end);
		return (0);
	}
	printf("%li %i %s\n", get_time() - philo->data->start, \
philo->id_philo, str);
	pthread_mutex_unlock(&philo->data->end);
	return (1);
}

int	lock_second_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->second_fork);
	if (!print_message("has taken a fork", philo) || \
		!print_message("is eating", philo))
	{
		unlock_two_forks(philo);
		return (0);
	}
	pthread_mutex_lock(&philo->data->full);
	philo->meal_time = get_time();
	pthread_mutex_unlock(&philo->data->full);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->full);
	philo->meals_eated++;
	pthread_mutex_unlock(&philo->data->full);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	return (1);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	if (philo->data->philo_nbr == 1)
	{
		print_message("has taken a fork", philo);
		usleep(philo->data->time_to_die * 1000);
		pthread_mutex_unlock(philo->first_fork);
		return (0);
	}
	if (!print_message("has taken a fork", philo))
	{
		pthread_mutex_unlock(philo->first_fork);
		return (0);
	}
	if (!lock_second_fork(philo))
		return (0);
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	usleep(300);
	if (!print_message("is sleeping", philo))
		return (0);
	usleep(philo->data->time_to_sleep * 1000);
	return (1);
}

int	think(t_philo *philo)
{
	if (!print_message("is thinking", philo))
		return (0);
	return (1);
}
