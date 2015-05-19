# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <string.h>

# define MAX_CONCURRENT_READERS 2

sem_t mutex, r_mutex;

unsigned int NumOfReaders = 0;

unsigned long gettid()
{
    pthread_t ptid = pthread_self();
    unsigned long threadId = 0;
    memcpy(&threadId, &ptid, sizeof(ptid));
    return threadId;
}

void* ReaderThread( void *arg )
{
	int count = 0;
	for( count = 1; count <= 1000; count++ )
	{
		sem_wait( &r_mutex );
		NumOfReaders++;
		if( 1 == NumOfReaders )
		{
			sem_wait( &mutex );
		}
		sem_post( &r_mutex );
		
		printf("\n Reader %ld has completed reading.", gettid());

//		sleep( 1 );
		
		sem_wait( &r_mutex );
		NumOfReaders--;
		if( 0 == NumOfReaders )
		{
			sem_post( &mutex );
		}
		sem_post( &r_mutex );
	}
	pthread_exit( 0 );
}

void* WriterThread( void* arg )
{
	int count = 0;
	for( count = 1; count <= 1000; count++ )
	{
		sem_wait( &mutex );
		printf("\n Writer %ld has completed writing.", gettid());
		sem_post( &mutex );
	}
	pthread_exit( 0 );
}

int main()
{
	pthread_t writer, reader[MAX_CONCURRENT_READERS];

	pthread_create( &writer, NULL, WriterThread, NULL );
	pthread_create( &reader[0], NULL, ReaderThread, NULL );
	pthread_create( &reader[1], NULL, ReaderThread, NULL );

	sem_init( &mutex,   0, 1 );
	sem_init( &r_mutex, 0, 1 );
	
	pthread_join( writer, NULL );
	pthread_join( reader[0], NULL );
	pthread_join( reader[1], NULL );

	return 0;
}
