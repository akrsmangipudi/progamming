# include <stdio.h>

unsigned int NumberOfWords( char *inputStr )
{
	int retVal = 0;

	// Get to the first character in the input string.
	while( *inputStr != '\0' && ( *inputStr == ' ' || *inputStr == '\n' || *inputStr == '\t' ) )
	{
		inputStr++;
	}
	
	if( *inputStr == '\0' )
	{
		return 0;
	}

	while( *inputStr != '\0' )
	{
		if( *inputStr == ' ' || *inputStr == '\n' || *inputStr == '\t' )
		{
			retVal++;
			inputStr++;

			while( *inputStr != '\0' && ( *inputStr == ' ' || *inputStr == '\n' || *inputStr == '\t' ) )
			{
				inputStr++;
			}

			if( *inputStr == '\0' )
			{
				break;
			}
		}
		else
		{
			inputStr++;
		}
	}
	return retVal;
}

int main()
{
	char inputStr[]  = "   One two          three\n  four\nfive\n";

	printf("\n Number of words in the given input string is: %d. \n", NumberOfWords( inputStr ) );
	
	return 0;
}
