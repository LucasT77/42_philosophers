/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:29:04 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/06 19:36:33 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_philo *phi)
{
	pthread_mutex_lock(&(phi->params->forks[phi->fork1].mutex));
	pthread_mutex_lock(&(phi->params->forks[phi->fork2].mutex));
	if (!get_any_dead(phi->params))
		ft_print(phi, get_time() - get_start(phi->params), get_id(phi), 4);
}

void	ft_release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->params->forks[philo->fork1].mutex));
	pthread_mutex_unlock(&(philo->params->forks[philo->fork2].mutex));
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while ((ft_check_dead(philo) == 0) && (!ft_check_fed(philo->params)))
	{
		if (get_philo_num(philo->params) > 1)
		{
			if (get_any_dead(philo->params) == 0)
				ft_init_eat_routine(philo);
			if (ft_check_fed(philo->params))
			{
				ft_print(philo, get_time() - get_start(philo->params), 0, 7);
				return (NULL);
			}
		}
		if (!ft_check_fed(philo->params))
			ft_sleep(philo);
		if (!ft_check_fed(philo->params))
			ft_think(philo);
	}
	return (NULL);
}

void	start_philos(t_params *params)
{
	pthread_t		*threads;
	t_philo			**philo;
	unsigned int	i;

	threads = (pthread_t *)malloc(params->philo_no * sizeof(pthread_t));
	philo = (t_philo **)malloc(params->philo_no * sizeof(t_philo *));
	i = -1;
	params->start = get_time();
	params->thread = threads;
	while (++i < params->philo_no)
	{
		philo[i] = init_philos(params, i + 1);
		pthread_create(&threads[i], NULL, &philo_thread, philo[i]);
	}
	i = 0;
	while (i < params->philo_no)
		pthread_join(threads[i++], NULL);
	free(threads);
	i = 0;
	while (i < params->philo_no)
	{
		pthread_mutex_destroy(&philo[i]->dead);
		free(philo[i++]);
	}
	free(philo);
}

int	main(int argc, char **argv)
{
	t_params	params;
	int			error;
	int			i;

	error = 0;
	error = init_struct(argc, argv, &params);
	if (!error)
	{
		i = ft_atoll(argv[1]);
		pthread_mutex_init(&params.mutex, NULL);
		pthread_mutex_init(&params.print, NULL);
		params.forks = init_fork(params.philo_no);
		start_philos(&params);
		pthread_mutex_destroy(&params.mutex);
		pthread_mutex_destroy(&params.print);
		while (--i >= 0)
			pthread_mutex_destroy(&params.forks[i].mutex);
		ft_free_struct(&params);
	}
	return (0);
}
