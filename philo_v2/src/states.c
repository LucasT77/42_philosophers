/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:42:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/01 16:26:05 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	get_forks(t_data *data, int id)
{
	int		id2;

	id2 = id + 1;
	if (id2 == data->n_forks)
		id2 = 0;
	if (data->forks_available[id] == 0)
		return (0);
	pthread_mutex_lock(&data->getting_forks);
	pthread_mutex_lock(&data->forks[id]);
	data->time_now = get_time() - data->start_time;
	data->forks_available[id] = 0;
	print_states(&(*data), id, 'f');
	data->philos[id].fork_count++;
	if (data->forks_available[id2] == 0)
	{
		pthread_mutex_unlock(&data->forks[id]);
		data->forks_available[id] = 1;
		return (0);
	}
	pthread_mutex_lock(&data->forks[id2]);
	data->time_now = get_time() - data->start_time;
	data->forks_available[id2] = 0;
	print_states(&(*data), id, 'f');
	data->philos[id].fork_count++;
	pthread_mutex_unlock(&data->getting_forks);
	return (1);
}

static int	eat(t_data *data, int id)
{
	int		id2;

	if (data->death != 0 || data->n_philos <= 1)
		return (0);
	id2 = id + 1;
	if (id2 == data->n_forks)
		id2 = 0;
	if (data->philos[id].fork_count == 2)
	{
		print_states(&(*data), id, 'e');
		data->philos[id].eat_count++;
		usleep(data->time_to_eat * 1000);
		pthread_mutex_unlock(&data->forks[id]);
		data->forks_available[id] = 1;
		pthread_mutex_unlock(&data->forks[id2]);
		data->philos[id].fork_count = 0;
		data->forks_available[id2] = 1;
		data->philos[id].start_time_to_die = get_time();
		print_states(&(*data), id, 's');
		usleep(data->time_to_sleep * 1000);
	}
	return (1);
}

void	think(t_data *data, int id)
{
	data->philos[id].start_time_to_die = get_time();
	while (data->death == 0 && data->count_philos_filled < data->n_philos)
	{
		get_forks(&(*data), id);
		eat(&(*data), id);
		print_states(&(*data), id, 't');
		data->time_now = get_time() - data->start_time;
		if (get_time() - data->philos[id].start_time_to_die
			>= data->time_to_die || data->n_philos <= 1)
		{
			data->time_now = get_time() - data->start_time;
			print_states(&(*data), id, 'd');
			data->death = 1;
		}
		if (data->philos[id].eat_count == data->max_times_can_eat)
			data->count_philos_filled++;
		if (data->count_philos_filled == data->n_philos)
			data->death = 1;
	}
}
