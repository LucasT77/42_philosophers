/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:03:18 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/06 18:48:54 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

t_philo	*init_philos(t_params *params, int id)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->id = id;
	philo->last_action = params->start;
	philo->last_meal = params->start;
	philo->eat_no = params->eat_times;
	philo->is_dead = 0;
	philo->params = params;
	if (id % 2 == 0)
	{
		philo->fork1 = id % params->philo_no;
		philo->fork2 = (id - 1) % params->philo_no;
	}
	else
	{
		philo->fork1 = (id - 1) % params->philo_no;
		philo->fork2 = id % params->philo_no;
	}
	pthread_mutex_init(&philo->dead, NULL);
	return (philo);
}

t_fork	*init_fork(int philo_no)
{
	t_fork	*fork;
	int		i;

	fork = (t_fork *)malloc(sizeof(t_fork) * philo_no);
	if (!fork)
		return (NULL);
	i = 0;
	while (i < philo_no)
	{
		fork[i].in_use = 0;
		if (pthread_mutex_init(&(fork[i++].mutex), NULL))
		{
			while (i)
				pthread_mutex_destroy(&(fork[--i].mutex));
			return (NULL);
			printf("falha ao iniciar mutex\n");
		}
	}
	return (fork);
}

int	init_struct(int argc, char **argv, t_params *params)
{
	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philo <number_of_philos> <time_to_die> <time_to_eat>");
		printf(" <time_to_sleep> [eat_number_of_times]\n");
		return (1);
	}
	if (ft_check_params(argv[1], &params->philo_no, 1))
		return (1);
	if (ft_check_params(argv[2], &params->time_to_die, 1))
		return (1);
	if (ft_check_params(argv[3], &params->time_to_eat, 1000))
		return (1);
	if (ft_check_params(argv[4], &params->time_to_sleep, 1000))
		return (1);
	if (argc == 6)
	{
		if (ft_check_params(argv[5], (unsigned int *)&params->eat_times, 1))
			return (1);
	}
	else
		params->eat_times = -1;
	params->fed = 0;
	params->notprint = 0;
	params->is_dead = 0;
	return (0);
}

int	ft_check_params(char *str, unsigned int *var, int factor)
{
	int			nbr;
	long long	aux;

	nbr = 0;
	aux = 0;
	if (ft_isunsint(str))
		aux = ft_atoll(str) * factor;
	if (aux <= 0)
	{
		nbr++;
		printf("Invalid Parameter\n");
	}
	else
		*var = (unsigned int)aux;
	return (nbr);
}

void	ft_init_eat_routine(t_philo *philo)
{
	ft_take_forks(philo);
	ft_eat(philo);
	ft_release_forks(philo);
	if (get_eat_no(philo) == 0)
		set_fed(philo->params);
}
