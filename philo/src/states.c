/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:42:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/07/26 16:50:43 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	eat(t_data *data, int id)
{
	int		id2;

	if (data->death != 0 || data->n_philos <= 1)
		return (0);
	id2 = id + 1;
	if (id2 == data->n_forks)
		id2 = 0;
	pthread_mutex_lock(&data->forks[id]);
	data->time_now = get_time() - data->start_time;
	print_states(&(*data), id, 'f');
	pthread_mutex_lock(&data->forks[id2]);
	data->time_now = get_time() - data->start_time;
	print_states(&(*data), id, 'f');
	print_states(&(*data), id, 'e');
	data->philos[id].eat_count++;
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(&data->forks[id]);
	pthread_mutex_unlock(&data->forks[id2]);
	return (1);
}

static int	sleeping(t_data *data, int id)
{
	if (data->death != 0)
		return (0);
	data->time_now = get_time() - data->start_time;
	print_states(&(*data), id, 's');
	usleep(data->time_to_sleep * 1000);
	return (1);
}

void	think(t_data *data, int id)
{
	data->philos[id].start_time_to_die = get_time();
	while (data->death == 0 && data->count_philos_filled < data->n_philos)
	{
		if (eat(&(*data), id))
		{
			data->philos[id].start_time_to_die = get_time();
			sleeping(&(*data), id);
		}
		data->time_now = get_time() - data->start_time;
		print_states(&(*data), id, 't');
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
