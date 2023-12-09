/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:11:47 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/20 17:12:44 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_memory(t_data *data)
{
	if (pthread_mutex_init(&data->end, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->full, NULL))
	{
		pthread_mutex_destroy(&data->end);
		return (EXIT_FAILURE);
	}
	data->philo = (t_philo *) malloc (sizeof(t_philo) * data->philo_nbr);
	if (!data->philo)
	{
		clean_mutexes(data);
		return (EXIT_FAILURE);
	}
	if (finish_memory(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	finish_memory(t_data *data)
{
	data->fork = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) \
	* data->philo_nbr);
	if (!data->fork)
	{
		free(data->philo);
		clean_mutexes(data);
		return (EXIT_FAILURE);
	}
	data->end_thr = (pthread_t *) malloc (sizeof(pthread_mutex_t));
	if (!data->end_thr)
	{
		free(data->philo);
		free(data->fork);
		clean_mutexes(data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	memory_set(t_data *data)
{
	int	i;

	i = -1;
	if (init_memory(data))
	{
		printf("Fail creating dinamic memory.\n");
		return (EXIT_FAILURE);
	}
	while (++i < data->philo_nbr)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
		{
			while ((i - 1) >= 0)
			{
				pthread_mutex_destroy(&data->fork[i - 1]);
				i--;
			}
			free(data->philo);
			free(data->fork);
			clean_mutexes(data);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	get_defs(t_data *data, int argc, char **argv)
{
	if (!ft_atoi(argv[1]) || !ft_atoi(argv[2]) || \
	!ft_atoi(argv[3]) || !ft_atoi(argv[4]))
		return (EXIT_FAILURE);
	else
	{
		data->philo_nbr = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
	}
	if (argc == 6)
	{
		if (!ft_atoi(argv[5]))
			return (EXIT_FAILURE);
		else
			data->meals_to_eat_all = ft_atoi(argv[5]);
	}
	else
		data->meals_to_eat_all = 0;
	data->the_end = 0;
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("Incorrect number of arguments!\n");
		return (0);
	}
	if (check_arg_value(argc, argv))
		return (EXIT_FAILURE);
	if (get_defs(&data, argc, argv))
	{
		printf("The args must be integers\n");
		return (EXIT_FAILURE);
	}
	if (memory_set(&data))
		return (EXIT_FAILURE);
	philosopher_data(&data);
	if (create_philosophers(&data))
		return (EXIT_FAILURE);
	clean(&data, data.philo_nbr);
	return (0);
}
