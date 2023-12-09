/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:22:53 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/20 17:24:00 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	end(t_data *data)
{
	int	i;
	int	j;

	reset(&i, &j, 100);
	while (1)
	{
		if (i >= data->philo_nbr)
			reset(&i, &j, 200);
		pthread_mutex_lock(&data->full);
		if ((long long int)(data->time_to_die) <= (get_time() - \
data->philo[i].meal_time))
		{
			pthread_mutex_unlock(&data->full);
			return (i + 1);
		}
		if (data->meals_to_eat_all != 0 && data->philo[i].meals_eated >= \
data->meals_to_eat_all)
			j++;
		pthread_mutex_unlock(&data->full);
		i++;
		if (j == data->philo_nbr)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

void	*check_end(void *arg_end)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg_end;
	i = end(data);
	pthread_mutex_lock(&data->end);
	data->the_end = 1;
	pthread_mutex_unlock(&data->end);
	if (i > 0)
		printf("%li %i died\n", get_time() - data->start, i);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*tmp_philo;
	t_data	*tmp_data;

	tmp_philo = (t_philo *) arg;
	tmp_data = tmp_philo->data;
	pthread_mutex_lock(&tmp_data->full);
	tmp_philo->meals_eated = 0;
	pthread_mutex_unlock(&tmp_data->full);
	if ((tmp_philo->id_philo) % 2 == 0)
		usleep(2000);
	while (1)
	{
		if (!eat(tmp_philo))
			break ;
		if (!ft_sleep(tmp_philo))
			break ;
		if (!think(tmp_philo))
			break ;
	}
	return (NULL);
}

int	create_philosophers(t_data *data)
{
	int	i;

	i = -1;
	data->start = get_time();
	while (++i < data->philo_nbr)
	{
		pthread_create(&data->philo[i].philo_thr, NULL, &routine, (void *) \
&data->philo[i]);
		pthread_mutex_lock(&data->full);
		data->philo[i].meal_time = get_time();
		pthread_mutex_unlock(&data->full);
		usleep(200);
	}
	pthread_create(data->end_thr, NULL, &check_end, (void *) data);
	i = -1;
	while (++i < data->philo_nbr)
		pthread_join(data->philo[i].philo_thr, NULL);
	pthread_join(*data->end_thr, NULL);
	return (EXIT_SUCCESS);
}

int	philosopher_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nbr)
	{
		data->philo[i].id_philo = (i + 1);
		if (i % 2 == 0)
		{
			data->philo[i].first_fork = &data->fork[((i + 1)
					% data->philo_nbr)];
			data->philo[i].second_fork = &data->fork[i];
		}
		else
		{
			data->philo[i].first_fork = &data->fork[i];
			data->philo[i].second_fork = &data->fork[((i + 1)
					% data->philo_nbr)];
		}
		data->philo[i].meals_to_eat = 0;
		data->philo[i].data = data;
	}
	return (EXIT_SUCCESS);
}
