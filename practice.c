#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define MatrixNumber 1000                    // the Matrix Capacity
#define NO_THREAD 25                          // thread number
#define STEP (MatrixNumber/NO_THREAD)         // 

int **a, **b,**c;

pthread_t tid[25];


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
//			delay(10);
		}
	}
}

void delay(int t)
{
	int now;
	now = clock();
	while(clock() - now < t);
}

void printMatrix(int *pArray, int rows, int cols)
{
	int i;
	int j;
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("%d\t", *pArray+i*cols+j);
		}
		printf("\n");
	}
}

int
main()
{
	int i,j;
	
	struct timeval start, finish;

//	srand( (unsigned)time( NULL ) );

	a = (int**)malloc(sizeof(int*)*MatrixNumber);
	b = (int**)malloc(sizeof(int*)*MatrixNumber);
	c = (int**)malloc(sizeof(int*)*MatrixNumber);

	for(i = 0; i < MatrixNumber; i++)
	{
		a[i]=(int*)malloc(sizeof(int)*MatrixNumber);
		b[i]=(int*)malloc(sizeof(int)*MatrixNumber);
		c[i]=(int*)malloc(sizeof(int)*MatrixNumber);
	}
	
	for(i = 0;i < MatrixNumber;i++)
	{
		for(j = 0; j < MatrixNumber;j++)
		{
			a[i][j] = rand()%2000+1;
			b[i][j] = rand()%2000+1;
		}
	}

	gettimeofday(&start, NULL);

//	start = clock();
	for( i = 0; i < NO_THREAD; i++ )
		pthread_create( &tid[ i ], NULL, thread_count, (void *) i );

	for( i = 0; i < NO_THREAD; i++ )
		pthread_join( tid[ i ], NULL );

	
//	printMatrix(C,MatrixNumber,MatrixNumber);
	gettimeofday(&finish, NULL);
	
	printf("Running Time: %d miliseconds\n", finish.tv_sec*1000 + finish.tv_usec/1000 - start.tv_sec*1000 - start.tv_usec/1000);

	return 0;
}




