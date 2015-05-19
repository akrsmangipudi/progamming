# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <string.h>

#define MAX_BUFFER 10

unsigned long gettid()
{
    pthread_t ptid = pthread_self();
    unsigned long threadId = 0;
    memcpy(&threadId, &ptid, sizeof(ptid));
    return threadId;
}

// Empty and Full are the counting semaphores and mutex is the binary semaphore.
sem_t empty, full, mutex;

int in = -1, out = -1;
unsigned int buffer[ MAX_BUFFER ];

void* ProducerThread( void* arg )
{
	int count = 0;
	for( count = 0; count < 10; count++ )
	{
		sem_wait( &empty );
		sem_wait( &mutex );

		buffer[ (in + 1) % MAX_BUFFER ] = count;
		in = (in + 1) % MAX_BUFFER;
		
		printf("\n %d. Producer %ld produced item %d at location %d", count, gettid(), count, in);

		sem_post( &mutex );
		sem_post( &full );
	}
}

void* ConsumerThread( void* arg )
{
	int count = 0;
	for( count = 0; count < 10; count++ )
	{
		sem_wait( &full );
		sem_wait( &mutex );

		out = (out + 1) % MAX_BUFFER;	
		printf("\n%d. Consumer %ld consumed item %d at location %d.", count, gettid(), buffer[ out ] , out);
		
		sem_post( &mutex );
		sem_post( &empty );
	}
}

int main()
{
	pthread_t producer, consumer;
	pthread_t producer1, consumer1;
	
	sem_init( &mutex, 0, 1 );
	sem_init( &empty, 0, MAX_BUFFER );
	sem_init( &full, 0, 0 );
	
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
