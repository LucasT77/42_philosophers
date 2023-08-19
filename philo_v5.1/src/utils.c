/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:28:43 by luaraujo          #+#    #+#             */
/*   Updated: 2023/07/30 15:50:46 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sinal;
	int	result;

	result = 0;
	sinal = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sinal *= -1;
		if (nptr[i++] >= '0' && nptr[i++] <= '9')
			i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + nptr[i] - '0';
		i++;
	}
	return (result * sinal);
}

long	get_time(void)
{
	struct timeval	time;
	long			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000;
	milliseconds += time.tv_usec / 1000;
	return (milliseconds);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (++i < data->n_forks)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->block_print);
	pthread_mutex_destroy(&data->getting_forks);
	pthread_mutex_destroy(&data->dead);
	free(data->philos);
	//free(data->threads);
	free(data->forks);
	free(data->forks_available);
}

void	print_states(t_philo *philo, char state)
{
	/*if (philo->data.death != 0)
		return ;*/
	pthread_mutex_lock(&philo->data->block_print);
	if (state == 'd')
		printf ("%ld %d died\n", get_time() - philo->data->start_time, (philo->id + 1));
	else if (state == 'f')
		printf ("%ld %d has taken a fork\n", get_time() - philo->data->start_time, (philo->id + 1));
	else if (state == 'x')
		printf ("%ld %d has dropped a fork\n", get_time() - philo->data->start_time, (philo->id + 1));
	else if (state == 'e')
		printf ("%ld %d is eating\n", get_time() - philo->data->start_time, (philo->id + 1));
	else if (state == 's')
		printf ("%ld %d is sleeping\n", get_time() - philo->data->start_time, (philo->id + 1));
	else if (state == 't')
		printf ("%ld %d is thinking\n", get_time() - philo->data->start_time, (philo->id + 1));
	pthread_mutex_unlock(&philo->data->block_print);
}
