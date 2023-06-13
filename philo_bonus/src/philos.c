/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:51:36 by luaraujo          #+#    #+#             */
/*   Updated: 2023/06/13 16:15:53 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	moniring_death(t_data *data)
{
	data->death = sem_open(DEATH, O_RDWR);
	sem_wait(data->death); // espera o sem = 1, ou seja, qnd um philo morre, o sem_post(death)
	// end it all
	return ;
}

void	philos(t_data *data, int id)
{
	data->forks = sem_open(FORKS, O_RDWR);
	data->death = sem_open(DEATH, O_RDWR);
	sem_wait(data->death); // sem = 0
	data->philos[id].eat_count = 0;
	if (pthread_create(data->philos[id].id, NULL, moniring_death, &(*data)) == 0)
	{
		pthread_detach(data->philos[id].id);
		return ;
	}
	pthread_join(data->philos[id].id, NULL);
	think(&(*data), id);
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