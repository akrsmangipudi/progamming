# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void PrintCombinationsOfString( char *inputStr, char *outputStr, int level, int start, int endIdx  )
{
	static int count = 1;

	int i = 0;
	for( i = start; i <= endIdx; i++ )
	{
		outputStr[ level ] = inputStr[ i ];
		outputStr[ level + 1 ] = '\0';

		printf("\n %s \n", outputStr );

		PrintCombinationsOfString( inputStr, outputStr, level + 1, i + 1, endIdx );

		outputStr[ level ] = '\0';
	}	
}

int main()
{
	char *inputStr  = "wxyz";
	char *outputStr = ( char * )malloc( sizeof(char) * ( strlen( inputStr ) + 1 ) );

	PrintCombinationsOfString( inputStr, outputStr, 0, 0, strlen( inputStr ) - 1 );
	
	return 0;
}
