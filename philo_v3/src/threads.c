/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:22:53 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/01 16:17:52 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo(void *arg)
{
	t_data	*data;
	int		id;
	int		i;

	data = (t_data *)arg;
	id = data->id;
	data->philos[id].eat_count = 0;
	data->philos[id].fork_count = 0;
	data->forks_available = malloc(sizeof(int) * data->n_forks);
	i = -1;
	while (++i < data->n_forks)
		data->forks_available[i] = 1;
	think(&(*data), id);
	return (0);
}

void	*death(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->dead);
	data->id = -1;
	while (++data->id < data->n_philos)
		pthread_detach(data->threads[data->id]);
	return (0);
}

void	start_threads(t_data *data)
{
	data->id = -1;
	data->death = 0;
	data->count_philos_filled = 0;
	pthread_mutex_lock(&data->dead);
	pthread_create(&data->th_death, NULL, death, &(*data));
	while (++data->id < data->n_philos)
	{
		pthread_create(&data->threads[data->id], NULL, philo, &(*data));
		usleep(100);
	}
	data->id = -1;
	while (++data->id < data->n_philos)
		pthread_join(data->threads[data->id], NULL);
	pthread_join(data->th_death, NULL);
	free_all(&(*data));
}
