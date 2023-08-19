






void	print_states(t_philo *philo, char state)
{
	/*if (philo->data.death != 0)
		return ;*/
	pthread_mutex_lock(&philo->data.block_print);
	if (state == 'd')
		printf ("%ld %d died\n", philo->data.time_now, (philo->id + 1));
	else if (state == 'f' && data->death == 0)
		printf ("%ld %d has taken a fork\n", philo->data.time_now, (philo->id + 1));
	else if (state == 'x' && data->death == 0)
		printf ("%ld %d has dropped a fork\n", philo->data.time_now, (philo->id + 1));
	else if (state == 'e' && data->death == 0)
		printf ("%ld %d is eating\n", philo->data.time_now, (philo->id + 1));
	else if (state == 's' && data->death == 0)
		printf ("%ld %d is sleeping\n", philo->data.time_now, (philo->id + 1));
	else if (state == 't' && data->death == 0)
		printf ("%ld %d is thinking\n", philo->data.time_now, (philo->id + 1));
	pthread_mutex_unlock(&data->block_print);
}