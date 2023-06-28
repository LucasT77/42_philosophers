/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:28:43 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/25 16:59:00 by luaraujo         ###   ########.fr       */
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
	//int	i;

	//i = 0;
	sem_close(data->forks);
	sem_close(data->death);
	free(data->philos);

}

void	print_states(t_data *data, int id, char state)
{
	if (data->death != 0)
		return ;
	//pthread_mutex_lock(&data->block_print);
	if (state == 'd')
		printf ("%ld %d died\n", data->time_now, (id + 1));
	else if (state == 'f' && data->death == 0)
		printf ("%ld %d has taken a fork\n", data->time_now, (id + 1));
	else if (state == 'e' && data->death == 0)
		printf ("%ld %d is eating\n", data->time_now, (id + 1));
	else if (state == 's' && data->death == 0)
		printf ("%ld %d is sleeping\n", data->time_now, (id + 1));
	else if (state == 't' && data->death == 0)
		printf ("%ld %d is thinking\n", data->time_now, (id + 1));
	//pthread_mutex_unlock(&data->block_print);
}
