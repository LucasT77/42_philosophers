/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:12 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/25 15:52:06 by luaraujo         ###   ########.fr       */
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

typedef struct s_philo
{
	long	start_time_to_die;
	int		eat_count;
	//int		full;
}				t_philo;

typedef struct s_data
{
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				n_philos;
	int				n_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_times_can_eat;
	long			start_time;
	long			time_now;
	int				id;
	int				death;
	int				count_philos_filled;
}				t_data;

int		ft_atoi(const char *nptr);
long	get_time(void);
void	start_threads(t_data *data);
void	*philo(void *arg);
void	think(t_data *data, int id);
void	free_all(t_data *data);

#endif
