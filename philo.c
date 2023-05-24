/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:11:47 by luaraujo          #+#    #+#             */
/*   Updated: 2023/05/23 15:20:27 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static int	get_the_variables(int argc, char **argv, t_data *data)
{
	int	i;

	data->n_philos = ft_atoi(argv[1]);
	data->n_forks = data->n_philos;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_times_can_eat = ft_atoi(argv[5]);
	data->philos = malloc(sizeof(int) * data->n_philos);
	if (!data->datas)
		return (-1);
	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i] = i + 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc < 5 || argc > 6)
	{
		printf("Incorrect number of arguments!");
		return (0);
	}
	if (get_the_variables(argc, argv, &data) == -1)
		return (0);
	data.start_time = get_time();
	data.philos = malloc(sizeof(t_philos) * data.n_philos);
	data.threads = malloc(sizeof(pthread_t) * data.n_philos);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.n_forks);
	i = -1;
	while (++i < n_forks)
		pthread_mutex_init(&data.forks[i], NULL);
	start_threads(&data);

}
