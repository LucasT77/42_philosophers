/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:42:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/06/05 17:02:41 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	eat(t_data *data, int id)
{
	sem_wait(data->semaphore);
	print_states(&(*data), id, 'f');
	sem_wait(data->semaphore);
	print_states(&(*data), id, 'f');
	print_states(&(*data), id, 'e');
	data->philos[id].eat_count++;
	usleep(data->time_to_eat * 1000);
	sem_post(data->semaphore);
	sem_post(data->semaphore);
	return (1);
}

static int	sleeping(t_data *data, int id)
{
	if (data->death != 0)
		return (0);
	data->time_now = get_time() - data->start_time;
	print_states(&(*data), id, 's');
	usleep(data->time_to_sleep * 1000);
	return (1);
}

void	think(t_data *data, int id)
{
	data->philos[id].start_time_to_die = get_time();
	while (1)
	{
		print_states(&(*data), id, 's');
		eat(&(*data), id);
		sleeping(&(*data), id);
	}
}
