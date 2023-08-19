/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:22:53 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/03 16:37:43 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->eat_count = 0;
	philo->fork_count = 0;
	pthread_mutex_lock(&philo->time_to_eat);
	philo->time_has_eaten = philo->start_time;
	pthread_mutex_unlock(&philo->time_to_eat);
	if (philo->n_philos == 1)
	{
		philo_forever_alone(&(*philo));
		return (NULL);
	}
	if (philo->id % 2)
		think(&(*philo));
	while (philo->data->stop == 0)
	{
		eat(&(*philo));
		think(&(*philo));
	}
	return (NULL);
}

static int	philo_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		data->philos[i].start_time = data->start_time = get_time();
		if (i % 2)
		{
			data->philos[i].fork1 = (i + 1) % data->n_philos;
			data->philos[i].fork2 = i;
		}
		else
		{
			data->philos[i].fork1 = i;
			data->philos[i].fork2 = (i + 1) % data->n_philos;;
		}
		data->philos[i].data = data;
		data->philos[i].id = i;
		data->philos[i].eat_count = 0;
		data->philos[i].philo_filled = 0;
		pthread_mutex_init(&data->philos[i].time_to_eat, NULL);
		data->philos[i].n_philos = data->n_philos;
	}
	return (1);
}

int	start_threads(t_data *data)
{
	int	i;

	data->start_time = get_time();
	philo_init(&data);
	i = -1;
	while (++i < data->n_philos)
	{
		if (i % 2)
		{
			data->philo[i].fork1 = (i + 1) % data->n_philos;
			data->philo[i].fork2 = i;
		}
		else
		{
			data->philo[i].fork1 = i;
			data->philo[i].fork2 = (i + 1) % data->n_philos;;
		}
		data->philo[i].id = i;
		if (pthread_create(&data->philos[i].thread, NULL, &philo, data->philos[i]))
			return (0);
	}
	if (data->n_philos > 1)
		if (pthread_create(&data->death, NULL, &death, &(*data)))
			return (0);
	return (1);
}
