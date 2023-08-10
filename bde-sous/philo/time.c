/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:08:31 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/06 18:09:35 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

unsigned int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((unsigned int)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

void	ft_usleep(unsigned int sleep_time, t_philo *philo)
{
	unsigned int	start;

	start = get_time();
	while ((get_time() - start) < (sleep_time / 1000))
	{
		if (!ft_check_dead(philo))
			usleep(500);
		else
			break ;
	}
}
