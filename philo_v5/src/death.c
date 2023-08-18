/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:13:35 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/18 19:13:38 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dead_or_filled(t_philo *philo)
{

}

int starved_to_death(t_data *data, int id)
{
    if ((get_time() - data->philo[id].time_has_eaten) >= data->time_to_die)
    {
        data->kill = 1;
        print_states(data->philo[id], 'd');
        return (1);
    }
    return (0);
}

static int check_situation(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->n_philo)
    {
        pthread_mutex_lock(&data->philo[i].time_to_eat);
        if (starved_to_death(&(*data), i))
        {
            pthread_mutex_unlock(&data->philo[i].time_to_eat);
            return (1);
        }
        if (data->max_times_can_eat != -1)
            //verify if all philos are filled
        pthread_mutex_unlock(&data->philo[i].time_to_eat);
    }
}

void	*death(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
    data->kill = 0;
    data->all_filled = 0;
    while (1)
    {

    }
}