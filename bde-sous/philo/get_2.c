/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:29:34 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/01 15:35:25 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

unsigned int	get_time_sleep(t_params *params)
{
	unsigned int	val;

	pthread_mutex_lock(&(params->mutex));
	val = params->time_to_sleep;
	pthread_mutex_unlock(&(params->mutex));
	return (val);
}

int	get_eat_times(t_params *params)
{
	int	val;

	pthread_mutex_lock(&(params->mutex));
	val = params->eat_times;
	pthread_mutex_unlock(&(params->mutex));
	return (val);
}

int	get_any_dead(t_params *params)
{
	int	val;

	pthread_mutex_lock(&(params->mutex));
	val = params->is_dead;
	pthread_mutex_unlock(&(params->mutex));
	return (val);
}

int	get_fed(t_params *params)
{
	int	val;

	pthread_mutex_lock(&(params->mutex));
	val = params->fed;
	pthread_mutex_unlock(&(params->mutex));
	return (val);
}

int	get_print(t_params *params)
{
	int	val;

	pthread_mutex_lock(&(params->mutex));
	val = params->notprint;
	pthread_mutex_unlock(&(params->mutex));
	return (val);
}
