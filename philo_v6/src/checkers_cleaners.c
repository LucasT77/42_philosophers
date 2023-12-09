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

int	control_arg_int(int argc, char *number)
{
	long long	num;
	int			i;

	i = 1;
	while (i < argc - 1)
	{
		num = ft_atoll(number);
		if (num > 2147483647 || ft_strlen(number) > 10)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_digits(char *number)
{
	int	i;
	int	len;

	len = ft_strlen(number);
	i = -1;
	while (++i < len)
		if (!ft_isdigit(number[i]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_arg_value(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (check_digits(argv[i]))
		{
			printf("You can only test valid x numbers.\n");
			return (EXIT_FAILURE);
		}
		if (control_arg_int(argc, argv[i]))
		{
			printf("You can only test int numbers.\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("The program must have at least one Philosopher.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	clean_mutexes(t_data *data)
{
	pthread_mutex_destroy(&data->end);
	pthread_mutex_destroy(&data->full);
}

void	clean(t_data *data, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		pthread_mutex_destroy(&data->fork[j]);
	clean_mutexes(data);
	free(data->fork);
	free(data->end_thr);
	free(data->philo);
}
