# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void PrintParanthesisCombinations( char *output, int level, int openIdx, int closeIdx, int numberofParanthesis )
{
	static int count = 1;
	if( ( openIdx == numberofParanthesis ) && ( closeIdx == numberofParanthesis ) )
	{
		output[ level + 1 ] = '\0';
		printf("\n %d. %s \n", count++, output );
		return;
	}

	if( openIdx < numberofParanthesis )
	{
		output[ level ] = '{';
		PrintParanthesisCombinations( output, level + 1, openIdx + 1, closeIdx, numberofParanthesis );
	}
	
	if( closeIdx < openIdx )
	{
		output[ level ] = '}';
		PrintParanthesisCombinations( output, level + 1, openIdx, closeIdx + 1, numberofParanthesis );
	}	
}

int main()
{
	int numberofParanthesis = 10;

	char *output = (char *)malloc( ( 2 * numberofParanthesis ) + 1 );

	memset( output, 0, 2 * numberofParanthesis + 1 );

	PrintParanthesisCombinations( output, 0, 0, 0, numberofParanthesis );

	return 0;
}
