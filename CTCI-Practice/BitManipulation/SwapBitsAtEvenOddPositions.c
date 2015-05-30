# include <stdio.h>

int SwapEvenAndOddPositions( int *source )
{
	*source = ( ( ( *source ) & 0x55555555 ) << 1 ) | ( ( ( *source ) & 0xaaaaaaaa ) >> 1 );
	return;
}

int main()
{
	int source = 0xAAAAAAAA;
	
	int i = 0;
	printf("\n Source Number: ");
	for( i = sizeof(int) * 8 - 1; i >= 0; i-- )
	{
		printf(" %d", ( source >> i ) & 1 );
	}
	printf("\n");

	SwapEvenAndOddPositions( &source );
	
	printf("\n Manipulated Number: ");
	for( i = sizeof(int) * 8 - 1; i >= 0; i-- )
	{
		printf(" %d", ( source >> i ) & 1 );
	}
	printf("\n");

	return 0;
}
