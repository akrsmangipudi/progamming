# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void PrintPossibleCombinations( char *inputStr, unsigned int level, unsigned int outputPos, char *outputStr )
{
	if( level == strlen( inputStr ) )
	{
		outputStr[ outputPos ] = '\0';
		printf("\n %s", outputStr );
		return;
	}
	else
	{
		unsigned int i = 0;
		for( i = 0; i < 2; i++ )
		{
			if( ( 0 == level ) && ( 1 == i ) )
			{
				return;
			}

			if( 1 == i )
			{
				outputStr[ outputPos ] = ' ';
				outputStr[ outputPos + 1 ] = inputStr[ level ];
				outputPos += 1;
			}

			if( 0 == i )
			{
				outputStr[ outputPos ] = inputStr[ level ];
			}

			PrintPossibleCombinations( inputStr, level + 1, outputPos + 1, outputStr );		
		}
	}
}

int main()
{
	char inputStr[] = "ABCDE";

	char *outputStr = ( char * )malloc( strlen( inputStr ) * 2 - 1 );
	memset( outputStr, 0, strlen( inputStr ) * 2 - 1 );

	PrintPossibleCombinations( inputStr, 0, 0, outputStr );

	return 0;
}
