#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define MatrixNumber 		1000
#define NO_THREAD		25
#define STEP 			(MatrixNumber/NO_THREAD)

int **a, **b,**c;

pthread_t tid[32];


void
Matrix(int rows, int cols)
{
	int i, j;
	srand(MatrixNumber);

	a = (int**)malloc(sizeof(int*)*rows);
	b = (int**)malloc(sizeof(int*)*rows);
	c = (int**)malloc(sizeof(int*)*rows);

	for(i = 0; i < rows; i++)
	{
		a[i]=(int*)malloc(sizeof(int)*cols);
		b[i]=(int*)malloc(sizeof(int)*cols);
		c[i]=(int*)malloc(sizeof(int)*cols);
	}

	for(i = 0;i < cols;i++)
	{
		for(j = 0; j < MatrixNumber;j++)
		{
			a[i][j] = rand()%2000+1;
			b[i][j] = rand()%2000+1;
		}
	}
}

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

void *
thread_count (void *arg)
{
	int n = arg;
	int head = (n * STEP);
	int end = (head + STEP);
	int i, j, k;
	
	for(i = head;i < end;i++)
	{
		for(j = 0; j < MatrixNumber;j++)
		{
			for(k = 0; k < MatrixNumber;k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			delay(10);
		}
	}
}

void 
printMatrix(int **pArray, int rows, int cols)
{
	int i;
	int j;
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("%d\t", pArray[i][j]);
		}
		printf("\n");
	}
}

int
main()
{
	int i,j;
	
	struct timeval start, finish;

	Matrix(MatrixNumber, MatrixNumber);

	gettimeofday(&start, NULL);

	for( i = 0; i < NO_THREAD; i++ )
		pthread_create( &tid[ i ], NULL, thread_count, (void *) i );

	for( i = 0; i < NO_THREAD; i++ )
		pthread_join( tid[ i ], NULL );
	
	gettimeofday(&finish, NULL);
	
	printf("Running Time: %d miliseconds\n", finish.tv_sec*1000 + finish.tv_usec/1000 - start.tv_sec*1000 - start.tv_usec/1000);

	return 0;
}




