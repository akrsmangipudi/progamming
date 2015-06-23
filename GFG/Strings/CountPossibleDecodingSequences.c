# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void PrintPossibleMappings( char *input, char *output, unsigned int insertPos, unsigned int readPos, unsigned int inputLen )
{
	if( input[ readPos ]  == '\0' )
	{
		output[ insertPos ] = '\0';
		printf("\n %s \n", output );
	}
	else
	{
		unsigned int i = 0;
		for( i = 0; i < 2; i++ )
		{
			if( i == 0 )
			{
				output[ insertPos ] = input[ readPos ] - '0' + 'A' - 1;
				PrintPossibleMappings( input, output, insertPos + 1, readPos + 1, inputLen );
			}
			else
			{
				if( readPos + 1 > inputLen - 1 )
				{
					return;
				}

				int j = input[ readPos ] - '0';
				j = j * 10 + input[ readPos + 1 ] - '0';
				if( j > 26 )
				{
					return;
				}

				output[ insertPos ] = j + 'A' - 1;
				
				PrintPossibleMappings( input, output, insertPos + 1, readPos + 2, inputLen );
			}
		}
	}
} 

int main()
{
	char inputNum[] = "121";

	char *output = ( char * )malloc( strlen( inputNum ) + 1 );
	memset( output, 0, strlen( inputNum ) + 1 );

	PrintPossibleMappings( inputNum, output, 0, 0, strlen( inputNum ) );

	return 0;
}
