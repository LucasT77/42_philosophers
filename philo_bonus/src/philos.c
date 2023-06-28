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

void	*monitoring_death(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	data->death = sem_open(DEATH, O_RDWR);
	sem_wait(data->death); // espera o sem = 1, ou seja, qnd um philo morre, o sem_post(death)
	// end it all
	return (0);
}

void	philos(t_data *data, int id)
{
	printf("philo %d started", id);
	data->forks = sem_open(FORKS, O_RDWR);
	data->death = sem_open(DEATH, O_RDWR);
	sem_wait(data->death); // sem = 0
	data->philos[id].eat_count = 0;
	if (pthread_create(&data->philos[id].id, NULL, monitoring_death, &(*data)) == 0)
	{
		pthread_detach(data->philos[id].id);
		free_all(&(*data));
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
		data->philos[i].pid = pid;
		i++;
	}
	i = -1;
	while (++i < data->n_forks)
		waitpid(data->philos[i].pid, &data->philos[i].status, 0);
}