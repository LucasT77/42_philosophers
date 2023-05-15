#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BIG 1000000000UL
int	counter = 0;
pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

void	*count_to_big(void *arg)
{
	for (int i = 0; i < BIG; i++)
	{
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int	main()
{
	pthread_t	t;

	pthread_create(&t, NULL, count_to_big, NULL);
	count_to_big(NULL);
	pthread_join(t, NULL);
	printf("Done. Counter = %u\n", counter);
}

// A bad example of thread usage