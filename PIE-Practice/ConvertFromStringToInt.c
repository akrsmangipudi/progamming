# include <stdio.h>
# include <stdlib.h>

int ConvertFromStringToInt( char *inputStr )
{
	int retVal = 0;

	if( *inputStr == '\0' )
		return retVal;

	int isNumNegative = ( *inputStr == '-' ) ? 1 : 0;

	int i = 0;

	if( isNumNegative )
		i = 1;

	while( inputStr[i] != '\0' )
	{
		retVal = retVal * 10 + ( inputStr[i] - '0' );
		i++;
	}

	if(isNumNegative)
		retVal = retVal * -1;

	return retVal;
}

int main()
{
	char input[] = "1";

	int retVal = ConvertFromStringToInt( input );

	printf("\n Returned Integer Value : %d \n", retVal );

	return 0;
}
