# include <stdio.h>
# include <stdlib.h>

void RemoveSpaces( char *inputStr )
{
	char *src = inputStr;
    char *dst = inputStr;

	while( *src != '\0' )
	{
		if( *src == ' ' )
		{
			src++;
		}
		else
		{
			*dst++ = *src++;
		}
	}
	*dst = '\0';
}

int main()
{
	char inputStr[] = " g  eeks         for gee ks       ";

	printf("\n String before removing the spaces: %s. \n", inputStr );

	RemoveSpaces( inputStr );

	printf("\n String after removing the spaces: %s. \n", inputStr );
}
