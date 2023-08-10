/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:42:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/08 19:58:20 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*static int	is_dead(t_data *data, int id)
{
	data->time_now = get_time() - data->start_time;
	if (data->death)
		return (1);
	if (get_time() - data->philos[id].start_time_to_die
			>= data->time_to_die || data->n_philos <= 1)
	{
		print_states(&(*data), id, 'd');
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	if (data->count_philos_filled == data->n_philos)
	{
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	return (0);
}*/

void	*is_dead(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		data->time_now = get_time() - data->start_time;
		if (data->death)
			return (0);
		if (get_time() - data->philos[data->philos->id].start_time_to_die
				>= data->time_to_die || data->n_philos <= 1)
		{
			data->death = 1;
			print_states(&(*data), data->philos->id, 'd');
			pthread_mutex_unlock(&data->dead);
			return (0);
		}
		if (data->count_philos_filled == data->n_philos)
		{
			data->death = 1;
			pthread_mutex_unlock(&data->dead);
			return (0);
		}
	}
}

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

	if (data->death || data->n_philos <= 1)
		return (0);
	id2 = id + 1;
	if (id2 == data->n_forks)
		id2 = 0;
	if (data->philos[id].fork_count == 2)
	{
		print_states(&(*data), id, 'e');
		data->philos[id].eat_count++;
		if (data->philos[id].eat_count == data->max_times_can_eat)
			data->count_philos_filled++;
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
	data->philos->id = id;
	pthread_create(&data->philos[id].th_death, NULL, is_dead, &(*data));
	while (!data->death)
	{
		if (get_forks(&(*data), id))
			if (eat(&(*data), id))
				print_states(&(*data), id, 't');
	}
	pthread_join(data->philos[id].th_death, NULL);
	pthread_detach(data->philos[id].th_death);
}

/*
	Ideia: criar mais uma thread para verificar constantemente se um philo morreu.
	Pode ser usado um mutex. Enquanto o mutex for bloqueado a funcao death continua
	esperando, e assim que um philo morre o mutex eh desbloqueado, terminando a funcao, que termina tudo.
*/
