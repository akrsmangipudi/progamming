# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>

# define MAX_CONCURRENT_READERS 2

unsigned int NumOfReaders = 0;

// Provide mutual-exclusion between reader(s) and writer.
pthread_mutex_t rw_lock = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t r_lock = PTHREAD_MUTEX_INITIALIZER;

unsigned long gettid()
{
    pthread_t ptid = pthread_self();
    unsigned long threadId = 0;
    memcpy(&threadId, &ptid, sizeof(ptid));
    return threadId;
}

void* WriterThread( void* arg )
{
	sleep( 2 );
	int count = 0;
	for( count = 0; count < 10; count++ )
	{
		pthread_mutex_lock( &rw_lock );
		printf("\n Writer %ld has completed writing.", gettid());
		pthread_mutex_unlock( &rw_lock );
	}
}

void* ReaderThread( void* arg )
{
	int count = 0;
	for( count = 0; count < 10; count++ )
	{
		pthread_mutex_lock( &r_lock );
		sleep( 1 );

		if( ++NumOfReaders == 1 )
		{
			printf("\n Thread %ld is holding the RW lock. \n", gettid() );
			pthread_mutex_lock( &rw_lock );
		}
		
		// Release the Readers lock so that the other readers may enter if they wish to.
		pthread_mutex_unlock( &r_lock );

		printf("\n Reader %ld has completed reading.", gettid());

		pthread_mutex_lock( &r_lock );

		sleep(1);
		
		// Last reader is also done reading, release the 
		if( --NumOfReaders == 0 )
		{
			pthread_mutex_unlock( &rw_lock );
			printf("\n Thread %ld released the RW lock. \n", gettid() );
		}
		pthread_mutex_unlock( &r_lock );
	}
}

int main()
{
	pthread_t writer, reader[MAX_CONCURRENT_READERS];

	pthread_create( &writer, NULL, WriterThread, NULL );	
	pthread_create( &reader[0], NULL, ReaderThread, NULL );	
	pthread_create( &reader[1], NULL, ReaderThread, NULL );

	pthread_join( writer, NULL );	
	pthread_join( reader[0], NULL );	
	pthread_join( reader[1], NULL );	

	return 0;
}
