/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:11:47 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 18:50:43 by luaraujo         ###   ########.fr       */
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

	if (argc < 5 || argc > 6)
	{
		printf("Incorrect number of arguments!");
		return (0);
	}
	if (get_the_variables(argc, argv, &philo) == -1)
		return (0);
	philo.start_time = get_time();
	pthread_mutex_init(&philo.mutex, NULL);
	pthread_mutex_destroy(&philo.mutex);
	//pthread_mutex_lock(&philo->mutex);
	//pthread_mutex_unlock(&philo->mutex);
}
