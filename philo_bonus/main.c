/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:11:47 by luaraujo          #+#    #+#             */
/*   Updated: 2023/06/05 15:42:41 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_the_variables(int argc, char **argv, t_data *data)
{
	data->n_philos = ft_atoi(argv[1]);
	data->n_forks = data->n_philos;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_times_can_eat = ft_atoi(argv[5]);
	else
		data->max_times_can_eat = -1;
	data->philos = malloc(sizeof(int) * data->n_philos);
	if (!data->philos)
		return (-1);
	return (1);
}

void	init_variables(t_data *data)
{
	data->start_time = get_time();
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	data->threads = malloc(sizeof(pthread_t) * data->n_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_forks);
	data->id = 0;
	data->death = 0;
	data->pid_index = 0;
	data->count_philos_filled = 0;
	sem_unlink(SEM_NAME);
	data->semaphore = sem_open(SEM_NAME, O_CREAT, 0600, data->n_forks);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc < 5 || argc > 6)
	{
		printf("Incorrect number of arguments!");
		return (0);
	}
	if (get_the_variables(argc, argv, &data) == -1)
		return (0);
	init_variables(&data);
	start_processes(&data);
	return (0);
}
