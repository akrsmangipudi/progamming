# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char* ReverseWords( char *input )
{
	int wordStart = 0, wordEnd = 0, readPosition = 0, writePosition = 0;

	int length = strlen( input );

	char *buffer = ( char * )malloc(length + 1);

	readPosition = length - 1;

	while( readPosition >= 0 )
	{
		if( input[readPosition] == ' ' )
		{
			buffer[writePosition++] = input[readPosition--];
		}
		else
		{
			wordEnd = readPosition;

			while( ( readPosition >= 0 ) && ( input[readPosition] != ' ' ) )
			{
				readPosition--;
			}

			wordStart = 1 + readPosition;

			while( wordStart <= wordEnd )
			{
				buffer[writePosition++] = input[wordStart++];
			}
		}
	}
	buffer[writePosition] = '\0';
	return buffer;
}

void ReverseString( char *string, int start, int end )
{
	while( start < end )
	{
		char temp = string[ start ];
		string[ start ] = string[ end ];
		string[ end ] = temp;
		start++;
		end--;
	}
}

void ReverseWords_NoExtraBuffer( char *input )
{
	int length = strlen( input );
	
	// Step (1) is to reverse the entire input string.
	ReverseString( input, 0, length - 1 );

	// Step (2) is to reverse the indivual words inside the string.
	int start = 0, end = 0;
	
	while( input[end + 1] != '\0' )
	{
		while( ( input[end + 1] != '\0' ) && ( input[end + 1] != ' ' ) )
		{
			end  = end + 1;
		}
		
		ReverseString( input, start, end );

		end = end + 1;

		if( input[end] == ' ' )
		{
			end = end + 1;
			start = end;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	char input[] = "Hello Aditya. Have a great day.";

	char *retString = ReverseWords( input );

	printf("\n Input  string: %s \n", input);
	printf("\n Return string: %s \n", retString);
	
	ReverseWords_NoExtraBuffer( input );
	
	printf("\n Return string: %s \n", input);

	return 0;
}
