# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void ConvertNumToChars( char *inputNum, int numOfDigits, char NumToCharMapping[][4], char *outputStr, int level )
{	
	static int count = 1;

	if( level == numOfDigits )
	{
		printf("%d. %s \n", count++, outputStr );
	}

	int i = 0;
	for( i = 0; i < strlen( NumToCharMapping[ inputNum[ level ] - '0' ] ); i++ )
	{
		outputStr[ level ] = NumToCharMapping[ inputNum[ level ] - '0' ][ i ];

		outputStr[ level + 1 ] = '\0';

		ConvertNumToChars( inputNum, numOfDigits, NumToCharMapping, outputStr, level + 1 );

		outputStr[ level ] = '\0';
	}
}

int main()
{
	char *inputNum = "234";

	char NumToCharMapping[][4] = { "0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
	
	char *outputStr = ( char * )malloc( sizeof(char) * ( strlen(inputNum) + 1 ) );
	memset( outputStr, 0, strlen(inputNum) + 1 );

	ConvertNumToChars( inputNum, strlen(inputNum), NumToCharMapping, outputStr, 0 );

	return 0;
}
