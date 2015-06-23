# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void FindColName( unsigned int num, char *output )
{
	unsigned int i = 0;
	while( num > 0 )
	{
		if( num % 26 == 0 )
		{
			output[ i++ ] = 'Z';
			num = num/26 - 1; 
		}
		else
		{
			output[ i++ ] = 'A' + ( num % 26 ) - 1;
			num = num/26;
		}
	}
	output[ i ] = '\0';
}

int main()
{
	unsigned int num = 51;
	char *output = ( char * )malloc( sizeof( char ) * 10 );
	memset( output, 0, 10 );

	FindColName( num, output );

	int i = 0;
	while( i < ( strlen( output )/2 ) )
	{
		char temp = output[ i ];
		output[ i ] = output[ strlen( output ) - 1 - i ];
		output[ strlen( output ) - 1 - i ] = temp;
		i++;
	}

	printf("\n Excel col name for a number %d is %s. \n", num,  output );
	return 0;
}
