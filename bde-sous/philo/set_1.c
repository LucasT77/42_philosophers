/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:55:15 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/01 15:52:56 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	set_last_action(int val, t_philo *philo)
{
	pthread_mutex_lock(&(philo->dead));
	philo->last_action = val;
	pthread_mutex_unlock(&(philo->dead));
}

void	set_last_meal(int val, t_philo *philo)
{
	pthread_mutex_lock(&(philo->dead));
	philo->last_meal = val;
	pthread_mutex_unlock(&(philo->dead));
}

void	set_eat_no(t_philo *philo)
{
	pthread_mutex_lock(&(philo->dead));
	philo->eat_no--;
	pthread_mutex_unlock(&(philo->dead));
}

void	set_any_dead(t_params *params)
{
	pthread_mutex_lock(&(params->mutex));
	params->is_dead = 1;
	pthread_mutex_unlock(&(params->mutex));
}
