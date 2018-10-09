#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
	long micro = 0;
	struct timeval tc,now;

	
	gettimeofday(&now, NULL);

	while(micro<10)
	{
		gettimeofday(&tc, NULL);
		micro = tc.tv_sec*1000000L + tc.tv_usec - now.tv_sec*1000000L - now.tv_usec;
	}
	
	printf("ps_sec = %ld, ps_usec = %ld \n", now.tv_sec, now.tv_usec);
	printf("now_sec = %ld, now_usec = %ld \n", tc.tv_sec, tc.tv_usec);

	return 0;
}