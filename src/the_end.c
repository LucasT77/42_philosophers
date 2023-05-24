/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:16:19 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/24 17:05:13 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	the_end(t_data *data)
{
	int	i;

	i = 0;
	while (++i < data->n_forks)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->philos);
	free(data->threads);
	free(data->forks);
}
