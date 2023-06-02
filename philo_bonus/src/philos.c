/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:51:36 by luaraujo          #+#    #+#             */
/*   Updated: 2023/06/02 17:24:37 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philos(t_data *data, int id)
{
	
}

void	start_processes(t_data *data)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < data->n_forks)
	{
		pid = fork();
		if (pid == 0)
		{
			philos(&(*data), data->id);
			data->id++;
			break ;
		}
		data->philo[i].pid = pid;
		i++;
	}
	i = -1;
	while (++i < data->n_forks)
		waitpid(data->philo[i].pid, &data->philo[i].status, 0);
}