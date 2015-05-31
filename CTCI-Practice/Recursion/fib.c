# include <stdio.h>

int Find( int k )
{
	if( k == 0 || k == 1 )
	{
		return 1;
	}

	return Find( k - 1 ) + Find( k - 2 );
}

int main()
{
	printf("\n %d \n", Find( 100 - 1 ) );
	return 0;
}
