/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:42:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/03 17:18:25 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_forever_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->data.forks[philo->fork1]);
	print_states(&(*philo), 'f');
    usleep(philo->data->time_to_die * 1000);
    print_states(&(*philo), 'd');
	pthread_mutex_unlock(&philo->data.forks[philo->fork1]);
}

static int	is_dead(t_philo *philo)
{

}

void	eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data.forks[philo->fork1]);
    print_states(&(*philo), 'f');
    pthread_mutex_lock(&philo->data.forks[philo->fork2]);
    print_states(&(*philo), 'f');
    print_states(&(*philo), 'e');
    pthread_mutex_lock(&philo->time_to_eat);
    philo->time_has_eaten = get_time();
    pthread_mutex_unlock(&philo->time_to_eat);
    usleep(philo->data.time_eating * 1000);
    philo->eat_count++;
    pthread_mutex_unlock(&philo->data.forks[philo->fork1]);
    pthread_mutex_unlock(&philo->data.forks[philo->fork2]);
    print_states(&(*philo), 's');
    usleep(philo->data.time_sleeping * 1000);
}

void	think(t_philo *philo)
{
    print_states(&(*philo), 't');
}
