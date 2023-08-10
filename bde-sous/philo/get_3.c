/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:29:27 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/01 15:36:06 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

unsigned int	get_start(t_params *params)
{
	unsigned int	val;

	pthread_mutex_lock(&(params->mutex));
	val = params->start;
	pthread_mutex_unlock(&(params->mutex));
	return (val);
}

int	get_philo_num(t_params *params)
{
	int	val;

	pthread_mutex_lock(&(params->mutex));
	val = params->philo_no;
	pthread_mutex_unlock(&(params->mutex));
	return (val);
}
