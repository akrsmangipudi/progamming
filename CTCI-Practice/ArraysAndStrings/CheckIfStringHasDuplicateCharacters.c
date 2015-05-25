# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int CheckIfStringHasDuplicates( char *str )
{
	unsigned int checker = 0;

	while( *str != '\0' )
	{
		if( *str == ' ' )
		{
			str++;
			continue;
		}

		if( ( checker >> (*str - 'a') ) & 1 )
		{
			return 1;
		}

		checker = checker | ( 1 << (*str - 'a') );

		str++;
	}
	return 0;
}

int main()
{
	char arr[] = "";
//	char arr[] = "crack the coding interview";
//	char arr[] = "helo";
	printf(" \n String %s has duplicates? : %d \n", arr, CheckIfStringHasDuplicates( arr ) );
	return 0;
}

