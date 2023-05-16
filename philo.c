/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:11:47 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/16 17:05:23 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_the_variables(int argc, char **argv, t_philo *philo)
{
	int	i;

	philo->n_philos = ft_atoi(argv[1]);
	philo->n_forks = philo->n_philos;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->max_times_can_eat = ft_atoi(argv[5]);
	philo->philos = malloc(sizeof(int) * philo->n_philos);
	if (!philo->philos)
		return (-1);
	i = 0;
	while (i < philo->n_philos)
	{
		philo->philos[i] = i + 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo			philo;
	pthread_t		threads;
	struct timeval	current_time;

	if (argc < 5 || argc > 6)
	{
		printf("Incorrect number of arguments!");
		return (0);
	}
	if (get_the_variables(argc, argv, &philo) == -1)
		return (0);
	
}
