#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
	int micro;
	struct timeval ps,now;
	gettimeofday(&ps, NULL);

	printf("ps_sec = %ld, ps_usec = %ls \n", ps.tv_sec, ps.tv_usec);

	while(micro<10)
	{
		gettimeofday(&now, NULL);
		if(now.tv_sec>ps.tv_sec):
			micro=1000000L;
		else:
			micro=0;
		micro+=now.tv_usec-ps.tv_usec;
	}
	
	printf("now_sec = %ld, now_usec = %ls \n", now.tv_sec, now.tv_usec);


	return 0;
}