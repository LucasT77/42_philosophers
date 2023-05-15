#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void	*my_turn(void *arg)
{
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("My turn!\n");
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

	pthread_create(&new_thread, NULL, my_turn, NULL);
	your_turn();
	pthread_join(new_thread, NULL);
}