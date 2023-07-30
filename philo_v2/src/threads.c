/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:22:53 by luaraujo          #+#    #+#             */
/*   Updated: 2023/07/30 16:55:52 by luaraujo         ###   ########.fr       */
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

void	start_threads(t_data *data)
{
	data->id = 0;
	data->death = 0;
	data->count_philos_filled = 0;
	while (data->id < data->n_philos)
	{
		//printf("data->id = %d\n", data->id);
		pthread_create(&data->threads[data->id], NULL, philo, &(*data));
		data->id++;
	}
	data->id = 0;
	while (data->id < data->n_philos)
	{
		if (data->death != 0)
			pthread_detach(data->threads[data->id]);
		pthread_join(data->threads[data->id], NULL);
		data->id++;
	}
	if (data->death == 1)
	{
		free_all(&(*data));
		return ;
	}
}
