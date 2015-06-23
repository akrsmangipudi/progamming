# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void PrintPermutations( char *input, char *output, int inputLen, int level )
{
	if( level == inputLen )
	{
		output[ level ] = '\0';
		printf("\n %s \n", output );
	}
	else
	{
		unsigned int i = 0;
		for( i = 0; i < inputLen; i++ )
		{
			output[ level ] = input[ i ];
			PrintPermutations( input, output, inputLen, level + 1 );
		}
	}
}

int main()
{
	char input[] = "ABC";

	char *output = ( char * )malloc( strlen(input) + 1 );
	memset( output, 0, strlen( input ) + 1 );

	PrintPermutations( input, output, strlen( input ), 0 );

	return 0;
}
