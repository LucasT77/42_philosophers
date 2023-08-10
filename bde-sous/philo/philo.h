/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:07:41 by bde-sous          #+#    #+#             */
/*   Updated: 2023/07/06 18:18:52 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				in_use;
}	t_fork;

typedef struct s_params{
	unsigned int	philo_no;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				eat_times;
	unsigned int	start;
	int				fed;
	int				notprint;
	t_fork			*forks;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	int				is_dead;
	pthread_t		*thread;
}	t_params;

typedef struct t_philo
{
	int				id;
	unsigned int	last_action;
	unsigned int	last_meal;
	int				eat_no;
	int				is_dead;
	int				fork1;
	int				fork2;
	pthread_mutex_t	dead;
	t_params		*params;
}	t_philo;

size_t			ft_strlen(const char *s);
unsigned int	get_last_meal(t_philo *philo);
unsigned int	get_time_die(t_params *params);
unsigned int	get_start(t_params *params);
unsigned int	get_id(t_philo *philo);
unsigned int	get_time_eat(t_params *params);
unsigned int	get_time_sleep(t_params *params);
unsigned int	get_eat_no(t_philo *philo);
unsigned int	get_time(void);
long long		ft_atoll(const char *str);
int				get_eat_times(t_params *params);
int				get_fed(t_params *params);
int				get_any_dead(t_params *params);
int				ft_sleep(t_philo *philo);
int				ft_think(t_philo *philo);
int				ft_eat(t_philo *philo);
int				ft_check_dead(t_philo *philo);
int				get_philo_num(t_params *params);
int				ft_check_fed(t_params *params);
int				get_print(t_params *params);
int				ft_isunsint(const char *str);
int				init_struct(int argc, char **argv, t_params *params);
int				ft_check_params(char *str, unsigned int *var, int factor);
void			set_print(t_params *params);
void			set_last_action(int val, t_philo *philo);
void			set_last_meal(int val, t_philo *philo);
void			set_eat_no(t_philo *philo);
void			set_any_dead(t_params *params);
void			set_fed(t_params *params);
void			ft_print(t_philo *philo, unsigned int time, int id, int action);
void			ft_usleep(unsigned int sleep_time, t_philo *philo);
void			ft_init_eat_routine(t_philo *philo);
void			ft_take_forks(t_philo *phi);
void			ft_release_forks(t_philo *philo);
void			ft_free_struct(t_params *params);
t_philo			*init_philos(t_params *params, int id);
t_fork			*init_fork(int philo_no);

#endif