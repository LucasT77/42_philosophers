/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:12 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/20 15:05:06 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	time_to_eat;
	int				id;
	long			time_has_eaten;
	int				eat_count;
	int				fork_count;
	int				fork1;
	int				fork2;
	long			start_time;
	int				n_philos;
	int				philo_filled;
}				t_philo;

typedef struct s_data
{
	pthread_t		death;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead;
	pthread_mutex_t	block_print;
	pthread_mutex_t	getting_forks;
	t_philo			*philos;
	int				*forks_available;
	int				n_philos;
	int				n_forks;
	int				time_to_die;
	int				time_eating;
	int				time_sleeping;
	int				max_times_can_eat;
	long			start_time;
	long			time_now;
	int				id;
	int				count_philos_filled;
	int				stop;
	int				all_filled;
}				t_data;

int		ft_atoi(const char *nptr);
long	get_time(void);
int		start_threads(t_data *data);
void	*philo(void *arg);
void	*death(void *arg);
void	think(t_philo *philo);
void	free_all(t_data *data);
void	print_states(t_philo *philo, char state);
void	philo_forever_alone(t_philo *philo);
void	eat(t_philo *philo);
int		dead_or_filled(t_philo *philo);

#endif
