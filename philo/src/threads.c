/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:22:53 by luaraujo          #+#    #+#             */
/*   Updated: 2023/07/26 15:14:24 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo(void *arg)
{
	t_data	*data;
	int		id;

	data = (t_data *)arg;
	id = data->id;
	data->philos[id].eat_count = 0;
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
