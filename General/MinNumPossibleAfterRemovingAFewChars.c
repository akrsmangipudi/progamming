# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void GenerateLowestNumber( char *input, int numOfElemToRemove )
{
	int length = strlen( input );
	int resultArrLen = length - numOfElemToRemove;

	char *output = ( char * )malloc( resultArrLen + 1 );

	int startIdx = 0;
	int endIdx   = length - numOfElemToRemove;
	int insertCount = 0;

	printf("\n start: %d, end: %d", startIdx, endIdx );

	while( resultArrLen > 0 )
	{
		int  i;
		int  insertIdx = startIdx;
		char insert    = input[ startIdx ];
		for( i = startIdx + 1; i <= endIdx; i++ )
		{
			if( ( input[ i ] - '0' ) < ( insert - '0' ) )
			{
				insertIdx = i;
				insert    = input[i];
			}
		}
		output[ insertCount++ ] = insert;
		startIdx = insertIdx + 1;
		endIdx   = length - numOfElemToRemove + insertCount; 
		resultArrLen--;
	}

	output[ insertCount ] = '\0';

	printf("\n %s \n", output );

}

int main()
{
	char input[] = "000124041033605937";
	GenerateLowestNumber( input, 4 );
}
