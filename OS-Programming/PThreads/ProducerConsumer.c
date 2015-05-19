# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

#define MAX_BUFFER 10

int numOfElem = 0;
int in = -1, out = -1;
int buffer[MAX_BUFFER];

pthread_cond_t empty = PTHREAD_COND_INITIALIZER, full = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

unsigned long gettid()
{
    pthread_t ptid = pthread_self();
    unsigned long threadId = 0;
    memcpy(&threadId, &ptid, sizeof(ptid));
    return threadId;
}

void* ConsumerThread( void *arg )
{
	int count = 0;
	for( count = 1; count <= 15; count++  )
	{
		pthread_mutex_lock( &lock );
		
		// Buffer is empty. Wait till we get an full slot.
		while( numOfElem == 0 )
		{
			printf("\n Child is blocked. \n");
			pthread_cond_wait( &full, &lock );
		}

		numOfElem--;

		out = ( out + 1 ) % MAX_BUFFER;
		printf("\n%d. Consumer %ld consumed item %d at location %d.", count, gettid(), buffer[ out ] , out);
		buffer[ out ] = -1;

		pthread_cond_signal( &empty );
		pthread_mutex_unlock( &lock );
	}
	pthread_exit(0);
}

void* ProducerThread( void *arg )
{
	int count = 0;
	for( count = 1; count <= 15; count++  )
	{
		pthread_mutex_lock( &lock );
		
		// Buffer is full. Wait till we get an empty slot.
		while( numOfElem == MAX_BUFFER )
		{
			pthread_cond_wait( &empty, &lock );
		}

		numOfElem++;

		in = ( in + 1 ) % MAX_BUFFER;
		buffer[ in ] = count;
		printf("\n %d. Producer %ld produced item %d at location %d", count, gettid(), count, in);
		
		pthread_cond_signal( &full );
		pthread_mutex_unlock( &lock );
	}
	pthread_exit(0);
}

int main()
{
	pthread_t producer, consumer;
	pthread_t producer1, consumer1;

	pthread_create( &producer, NULL, ProducerThread, NULL );
	pthread_create( &consumer, NULL, ConsumerThread, NULL );
	pthread_create( &producer1, NULL, ProducerThread, NULL );
	pthread_create( &consumer1, NULL, ConsumerThread, NULL );

	pthread_join( producer, NULL );
	pthread_join( consumer, NULL );
	pthread_join( producer1, NULL );
	pthread_join( consumer1, NULL );

	return 0;
}
