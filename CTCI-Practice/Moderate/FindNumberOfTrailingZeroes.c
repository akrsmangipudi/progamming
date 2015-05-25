# include <stdio.h>

int FindNumOfTrailingZeroes( int num )
{
	int retVal = 0;
	int i = 0;
	for( i = 5; num/i > 0; i *= 5 )
	{
		retVal += num/i;		
	}
	return retVal;
}

int main()
{
	int num = 612894;
	printf("\n Number Of trailing zeroes in %d factorial is %d. \n", num, FindNumOfTrailingZeroes( num ) ); 
	return 0;
}
