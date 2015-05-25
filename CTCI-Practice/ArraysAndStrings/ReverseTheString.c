# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void ReverseString( char *start, char *end )
{
	while( start < end )
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void ReverseWords( char *str )
{
	int start = 0, end = 0;
	while( str[ start ] != '\0' )
	{
		while( ( str[end + 1] != ' ' ) && ( str[end + 1] != '\0' )	)
		{
			end = end + 1;
		}

		ReverseString( str + start, str + end );

		start = end;
		start = start + 1;
		end   = start;

		if( str[start] == ' ' )
		{
			start = start + 1;
			end = start;
		}
	}
} 

void ReverseWordsInString( char *str )
{
	ReverseWords( str );

	ReverseString( str, str + strlen(str) - 1 );
}

int main()
{
	char arr[] = "crack the coding interview";

	printf(" \n Before In Place Reversals: %s \n", arr );

	ReverseWordsInString( arr );

	printf("\n After In Place Reversals: %s \n", arr );

	return 0;
}
