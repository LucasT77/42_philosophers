/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:51:59 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/01 15:53:09 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	set_fed(t_params *params)
{
	pthread_mutex_lock(&(params->mutex));
	params->fed++;
	pthread_mutex_unlock(&(params->mutex));
}

void	set_print(t_params *params)
{
	pthread_mutex_lock(&(params->mutex));
	params->notprint = 1;
	pthread_mutex_unlock(&(params->mutex));
}
