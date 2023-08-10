/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:33:10 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/01 15:32:04 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

unsigned int	get_last_meal(t_philo *philo)
{
	unsigned int	val;

	pthread_mutex_lock(&(philo->dead));
	val = philo->last_meal;
	pthread_mutex_unlock(&(philo->dead));
	return (val);
}

unsigned int	get_id(t_philo *philo)
{
	unsigned int	val;

	pthread_mutex_lock(&(philo->dead));
	val = philo->id;
	pthread_mutex_unlock(&(philo->dead));
	return (val);
}

unsigned int	get_eat_no(t_philo *philo)
{
	unsigned int	val;

	pthread_mutex_lock(&(philo->dead));
	val = philo->eat_no;
	pthread_mutex_unlock(&(philo->dead));
	return (val);
}

unsigned int	get_time_die(t_params *params)
{
	unsigned int	val;

	pthread_mutex_lock(&(params->mutex));
	val = params->time_to_die;
	pthread_mutex_unlock(&(params->mutex));
	return (val);
}

unsigned int	get_time_eat(t_params *params)
{
	unsigned int	val;

	pthread_mutex_lock(&(params->mutex));
	val = params->time_to_eat;
	pthread_mutex_unlock(&(params->mutex));
	return (val);
}
