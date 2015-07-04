# include <stdio.h>
# include <string.h>
# include <stdbool.h>

bool CheckIfMatches( char *pattern , char *source )
{
	if( ( *pattern == '\0' ) && ( *source == '\0' ) )
	{
		return true;
	}

	if( *pattern == *source )
	{
		return CheckIfMatches( pattern + 1, source + 1 );
	}

	if( *pattern == '?' )
	{
		if( *source == '\0' )
		{
			return false;
		}
		else
		{
			return CheckIfMatches( pattern + 1, source + 1 );
		}
	}

	if( *pattern == '*' )
	{
		if( *(pattern + 1) != '\0' && *source == '\0' )
		{
			return false;
		}
		else if( *(pattern + 1) == '\0' )
		{
			return true;
		}
		else
		{
			return CheckIfMatches( pattern, source + 1 ) || CheckIfMatches( pattern + 1, source );
		}
	}

	return false;
}

int main()
{
//	printf("\n CheckIfMatches(\"g*ks\", \"geeks\") : %d. \n", CheckIfMatches("g*ks", "geeks") );
//	printf("\n CheckIfMatches(\"ge?ks*ge?ks\", \"geeksforgeeks\") : %d. \n", CheckIfMatches("ge?ks*geeks", "geeksforgeeks") );
//	printf("\n CheckIfMatches(\"g*k\", \"gee\") : %d. \n", CheckIfMatches("g*k", "gee") );
//	printf("\n CheckIfMatches(\"pqrs\", \"pqrst\") : %d. \n", CheckIfMatches("pqrs", "pqrst") );
//	printf("\n CheckIfMatches(\"abc*bcd\", \"abcdhghgbcd\") : %d. \n", CheckIfMatches("abc*bcd", "abcdhghgbcd") );
//	printf("\n CheckIfMatches(\"abc*c?d\", \"abcdhghgbcd\") : %d. \n", CheckIfMatches("abc*c?d", "abcdhghgbcd") );
//	printf("\n CheckIfMatches(\"*c*d\", \"abcd\") : %d. \n", CheckIfMatches("*c*d", "abcd") );
//	printf("\n CheckIfMatches(\"*?c*d\", \"abcd\") : %d. \n", CheckIfMatches("*?c*d", "abcd") );

	printf("\n %d. \n", CheckIfMatches("*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*",
                        "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba"));
	
	return 0;
}
