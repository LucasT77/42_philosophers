/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:12 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/23 17:21:44 by luaraujo         ###   ########.fr       */
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
	char	state;
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
	int				id;
}				t_data;

int	ft_atoi(const char *nptr);
long	get_time(void);

#endif
