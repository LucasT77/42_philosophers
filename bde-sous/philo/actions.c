/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:05:40 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/06 18:07:17 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_check_dead(t_philo *philo)
{
	unsigned int	now;

	now = get_time();
	if (!get_any_dead(philo->params))
	{
		if ((now - get_last_meal(philo)) > get_time_die(philo->params))
		{
			set_any_dead(philo->params);
			ft_print(philo, now - philo->params->start, philo->id, 6);
		}
	}
	return (get_any_dead(philo->params));
}

int	ft_eat(t_philo *philo)
{
	unsigned int	now;

	now = get_time();
	if (get_any_dead(philo->params))
		return (0);
	if (ft_check_dead(philo))
		return (0);
	set_last_action(now, philo);
	set_last_meal(now, philo);
	set_eat_no(philo);
	ft_print(philo, now - get_start(philo->params), get_id(philo), 1);
	ft_usleep(philo->params->time_to_eat, philo);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if (ft_check_dead(philo))
		return (0);
	if (get_fed(philo->params) == get_eat_times(philo->params))
		return (0);
	ft_print(philo, get_time() - get_start(philo->params), get_id(philo), 3);
	set_last_action(get_time(), philo);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_check_dead(philo))
		return (0);
	if (get_fed(philo->params) == get_eat_times(philo->params))
		return (0);
	ft_print(philo, get_time() - get_start(philo->params), get_id(philo), 2);
	ft_usleep(get_time_sleep(philo->params), philo);
	set_last_action(get_time(), philo);
	return (0);
}

int	ft_check_fed(t_params *par)
{
	return (get_fed(par) >= get_philo_num(par) && get_eat_times(par) != -1);
}
