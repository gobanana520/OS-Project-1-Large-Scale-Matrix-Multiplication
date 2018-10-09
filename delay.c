#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

void 
delay(int t)
{
	long micro = 0;

	struct timeval tc,now;

	gettimeofday(&now, NULL);

	while(micro < t)
	{
		gettimeofday(&tc, NULL);
		micro = tc.tv_sec*1000000L + tc.tv_usec - now.tv_sec*1000000L - now.tv_usec;
	}

}

void 
main()
{
	struct timeval start, finish;
	
	gettimeofday(&start, NULL);
	
	delay(10);

	gettimeofday(&finish, NULL);

	printf("Running Time: %d miliseconds\n", finish.tv_sec*1000000 + finish.tv_usec - start.tv_sec*1000000 - start.tv_usec);
}
