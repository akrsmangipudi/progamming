# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void PrintPermutationsOfString( char *inputStr, char *used, char *outputStr, int endIdx, int level )
{
	static int count = 1;
	if( level == endIdx + 1 )
	{
		printf("%d. %s \n", count++, outputStr );
		return;
	}

	int i = 0;
	for( i = 0; i <= endIdx; i++ )
	{
		if( used[i] )
		{
			continue;
		}

		used[i] = 1;

		outputStr[ level ] = inputStr[ i ];

		PrintPermutationsOfString( inputStr, used, outputStr, endIdx, level + 1 );

		outputStr[ level ] = '\0';

		used[i] = 0; 
	}
}

int main()
{
	char input[] = "abcd";
	
	char *output = ( char * )malloc( sizeof(char) * ( strlen(input) + 1 ) );

	memset( output, 0, strlen(input) + 1 );

	char *used   = ( char * )malloc( sizeof(char) * strlen(input) );

	memset( used, 0, sizeof(char) * strlen(input) );

	PrintPermutationsOfString( input, used, output, strlen(input) - 1, 0 );

	return 0;
}
