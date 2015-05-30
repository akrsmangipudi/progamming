# include <stdio.h>

int FindNumOfBitsToFlip( int source, int target )
{
	int retVal = 0;
	int i = 0;
	for( i = 0; i < sizeof(int) * 8; i++ )
	{
		if( ( ( source >> i ) & 1 ) != ( ( target >> i ) & 1 ) )
		{
			retVal++;
		}
	}
	return retVal;
}

int main()
{
	int source = 14987;
	int target = 17983;

	int i = 0;
	printf("\n Source Number: ");
	for( i = sizeof(int) * 8 - 1; i >= 0; i-- )
	{
		printf(" %d", ( source >> i ) & 1 );
	}
	printf("\n");
	
	printf("\n Target Number: ");
	for( i = sizeof(int) * 8 - 1; i >= 0; i-- )
	{
		printf(" %d", ( target >> i ) & 1 );
	}
	printf("\n");

	int numOfBits = FindNumOfBitsToFlip( source, target );

	printf("\n Number of bits to flip is %d. \n", numOfBits );

	return 0;
}
