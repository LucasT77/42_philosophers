/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:12 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/16 16:43:26 by luaraujo         ###   ########.fr       */
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
	int	n_philos;
	int	n_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_times_can_eat;
	int	*philos;
}				t_philo;

int	ft_atoi(const char *nptr);

#endif
