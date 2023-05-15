#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void	*my_turn(void *arg)
{
	int	*i_ptr;

	i_ptr = (int *)arg;
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("My turn! %d\n", *i_ptr);
		(*i_ptr)++;
	}
	return NULL;
}

void	your_turn()
{
	for (int i = 0; i < 3; i++)
	{
		sleep(2);
		printf("Your turn\n");
	}
}

int	main()
{
	pthread_t	new_thread;
	int	v;

	v = 0;
	pthread_create(&new_thread, NULL, my_turn, &v);
	your_turn();
	pthread_join(new_thread, NULL);
}