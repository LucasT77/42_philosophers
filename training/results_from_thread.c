#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	*my_turn(void *arg)
{
	int	*i_ptr;

	i_ptr = (int *)malloc(sizeof(int));
	(*i_ptr) = 5;
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("My turn! %d\n", *i_ptr);
		(*i_ptr)++;
	}
	return i_ptr;
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
	int	*result;

	pthread_create(&new_thread, NULL, my_turn, NULL);
	your_turn();
	pthread_join(new_thread, (void *)&result);
	printf("thread's done: result = %d\n", *result);
}