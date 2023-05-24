/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:42:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/24 15:56:45 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	eat(t_data *data, int id)
{
	long	start_eat;
	int		id2;

	id2 = id + 1
	if (id2 == data->n_forks)
		id2 = 0;
	start_eat = get_time();
	if (pthread_mutex_lock(&data->forks[id]) != 0)
		return (0);
	if (pthread_mutex_lock(&data->forks[id2]) != 0)
	{
		pthread_mutex_unlock(&data->forks[id]);
		return (0);
	}
	data->philos[id].state = 'e';
	data->philos[id].eat_count++;
	while (1)
		if (get_time() - start_eat >= data->time_to_eat)
			break ;
	pthread_mutex_unlock(&data->forks[id]);
	pthread_mutex_unlock(&data->forks[id2]);
	data->philos[id].start_time_to_die = get_time();
	return (1);
}

static int	sleep(t_data *data)
{
	long	start_sleep;

	start_sleep = get_time();
	data->philos[id].state = 's';
	while (1)
		if (get_time() - start_sleep >= data->time_to_sleep)
			break ;
	return (1);
}

void	think(t_data *data, int id)
{
	data->philos[id].start_time_to_die = get_time();
	while (1)
	{
		if (eat(&(*data), id))
			sleep(&(*data));
		data->philos[id].state = 't';
		if (get_time() - data->philos[id].start_time_to_die >= data->time_to_die)
		{
			data->philos[id].state = 'd';
			the_end(&(*data));
			return ;
		}
		if(data->max_times_can_eat && data->philos[id].eat_count == data->max_times_can_eat)
		{
			data->philos[id].full = 1;
		}
	}
}