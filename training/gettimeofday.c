# include <sys/time.h>

int	main(void)
{
	while(1)
	{
		gettimeofday(&current_time, NULL);
  		printf("seconds : %ld\nmicro seconds : %ld", current_time.tv_sec, current_time.tv_usec);
		usleep(200000);
	}
}