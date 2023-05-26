/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:42:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/25 17:16:56 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	eat(t_data *data, int id)
{
	int		id2;

	id2 = id + 1;
	if (id2 == data->n_forks)
		id2 = 0;
	if (pthread_mutex_lock(&data->forks[id]) != 0)
		return (0);
	data->time_now = get_time() - data->start_time;
	printf("%ld %d has taken a fork\n", data->time_now, (id + 1));
	if (pthread_mutex_lock(&data->forks[id2]) != 0)
	{
		pthread_mutex_unlock(&data->forks[id]);
		return (0);
	}
	data->time_now = get_time() - data->start_time;
	printf("%ld %d has taken a fork\n", data->time_now, (id + 1));
	printf("%ld %d is eating\n", data->time_now, (id + 1));
	data->philos[id].eat_count++;
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(&data->forks[id]);
	pthread_mutex_unlock(&data->forks[id2]);
	return (1);
}

static int	sleeping(t_data *data, int id)
{
	data->time_now = get_time() - data->start_time;
	printf("%ld %d is sleeping\n", data->time_now, (id + 1));
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
		printf("%ld %d is thinking\n", data->time_now, (id + 1));
		if (get_time() - data->philos[id].start_time_to_die
			>= data->time_to_die)
		{
			data->time_now = get_time() - data->start_time;
			printf("%ld %d died\n", data->time_now, (id + 1));
			data->death = 1;
		}
		if (data->max_times_can_eat && data->philos[id].eat_count
			== data->max_times_can_eat)
			data->count_philos_filled++;
		printf("%d\n", data->death);
	}
}
