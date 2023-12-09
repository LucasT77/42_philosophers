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

typedef struct s_philo
{
	struct s_data			*data;
	int						id_philo;
	pthread_t				philo_thr;
	pthread_mutex_t			*first_fork;
	pthread_mutex_t			*second_fork;
	long					meal_time;
	int						meals_to_eat;
	int						meals_eated;
}				t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_t		*end_thr;
	pthread_mutex_t	*fork;
	pthread_mutex_t	end;
	pthread_mutex_t	full;
	long			start;
	int				philo_nbr;
	int				the_end;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat_all;
}				t_data;

int			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			check_arg_value(int argc, char **argv);
int			check_digits(char *number);
int			control_arg_int(int argc, char *number);
long long	ft_atoll(const char *str);
int			get_defs(t_data *data, int argc, char **argv);
int			memory_set(t_data *data);
int			init_memory(t_data *data);
int			finish_memory(t_data *data);
int			philosopher_data(t_data *data);
int			create_philosophers(t_data *info);
long		get_time(void);
int			end(t_data *info);
void		*check_end(void *arg_end);
void		*routine(void *arg);
void		clean_mutexes(t_data *data);
void		clean(t_data *data, int i);
void		reset(int *i, int *j, int time);
int			eat(t_philo *philo);
int			ft_sleep(t_philo *philo);
int			think(t_philo *philo);
int			print_message(char *str, t_philo *philo);
int			lock_second_fork(t_philo *philo);
void		unlock_two_forks(t_philo *philo);

#endif
