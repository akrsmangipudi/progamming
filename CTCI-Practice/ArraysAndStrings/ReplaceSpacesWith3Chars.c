# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void ReplaceSpaces( char *inputStr )
{
	int stringEnd = 0, stringStart = 0;

	int readPosition = strlen( inputStr ) - 1;

	while( readPosition >= 0 )
	{
		stringEnd = strlen( inputStr ) - 1;

		while( ( readPosition >= 0 ) && ( inputStr[readPosition] != ' ' ) )
		{
			readPosition--;
		}

		if( readPosition >= 0 )
		{
			stringStart = readPosition + 1;

			while( stringEnd >= stringStart )
			{
				inputStr[stringEnd + 2] = inputStr[ stringEnd ];
				stringEnd--;
			}

			if( readPosition >= 0 )
			{
				int temp = readPosition;
				inputStr[ temp ] = '%';
				inputStr[ temp + 1 ] = '2';
				inputStr[ temp + 2 ] = '0';
				readPosition--;
			}
		}
	}
}

int main()
{
	char arr[100] = " crack the coding interview";

	ReplaceSpaces( arr );

	printf("\n %s \n", arr );

	return 0;
}
