/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:13:35 by luaraujo          #+#    #+#             */
/*   Updated: 2023/08/20 17:11:17 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*int	dead_or_filled(t_philo *philo)
{

}*/

int starved_to_death(t_data *data, int id)
{
    if ((get_time() - data->philos[id].time_has_eaten) >= data->time_to_die)
    {
        data->stop = 1;
        print_states(&(*data).philos[id], 'd');
        return (1);
    }
    return (0);
}

static int check_situation(t_data *data)
{
    int i;
    int j;

    i = -1;
    while (++i < data->n_philos)
    {
        pthread_mutex_lock(&data->philos[i].time_to_eat);
        if (starved_to_death(&(*data), i))
        {
            pthread_mutex_unlock(&data->philos[i].time_to_eat);
            return (1);
        }
        if (data->max_times_can_eat != -1)
        {
            j = -1;
            while (++j < data->n_philos)
            {
                if (data->philos[j].philo_filled != 1)
                    break ;
            }
            if (j == data->n_philos)
                return (1);
        }
        pthread_mutex_unlock(&data->philos[i].time_to_eat);
    }
    return (0);
}

void	*death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
    data->stop = 0;
    data->all_filled = 0;
    while (1)
    {
        if (check_situation(&(*data)) == 1)
        {
            data->stop = 1;
			i = -1;
			while (++i < data->n_philos)
				pthread_detach(data->philos[i].thread);
            return (NULL);
        }
    }
	return (NULL);
}
