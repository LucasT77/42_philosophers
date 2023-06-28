/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:12 by luaraujo          #+#    #+#             */
/*   Updated: 2023/06/13 15:43:28 by luaraujo         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>

#define FORKS "/forks"
#define DEATH "/death"

typedef struct s_philo
{
	pthread_t		id;
	pid_t			pid;
	int				status;
	long			start_time_to_die;
	int				eat_count;
}				t_philo;

typedef struct s_data
{
	//pthread_t		*threads;
	sem_t			*forks;
	sem_t			*death;
	t_philo			*philos;
	int				n_philos;
	int				n_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_times_can_eat;
	long			start_time;
	long			time_now;
	int				pid_index;
	//int				death;
	int				id;
	int				count_philos_filled;
}				t_data;

//void	start_threads(t_data *data);
//void	*philo(void *arg);
//void	think(t_data *data, int id);
int		ft_atoi(const char *nptr);
long	get_time(void);
void	free_all(t_data *data);
void	print_states(t_data *data, int id, char state);
void	start_processes(t_data *data);
void	philos(t_data *data, int id);
void	think(t_data *data, int id);

#endif
