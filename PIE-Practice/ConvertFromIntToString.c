# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

int CalculateNumOfDigits( int number )
{
	int retVal = 0;
	while( number > 0 )
	{
		number = number/10;
		retVal++;
	}
	return retVal;
}

void ConvertFromIntToString ( int number, char **output )
{
	int isNumNegative = ( number < 0 ) ? 1 : 0;

	if( isNumNegative )
		number = number * -1;

	int numDigits = CalculateNumOfDigits( number );

	(*output) = (char *)malloc( numDigits + 1 + isNumNegative );

	int i = numDigits + isNumNegative - 1;
	
	while( number > 0 )
	{
		(*output)[i] = ( (number % 10) + '0');
		number = number/10;
		i--;
	}

	if( isNumNegative )
		(*output)[0] = '-';

	(*output)[numDigits + 1 + isNumNegative] = '\0';

}

int main()
{
	int input = -1234;

	char *string = NULL;

	ConvertFromIntToString( input, &string );

	printf("\n %s \n", string );

	return 0;
}
