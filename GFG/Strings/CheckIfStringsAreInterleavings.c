# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

bool AreStringsInterleaved( char *str1, char *str2, char *input )
{
	if( *input == '\0' )
	{
		return true;
	}

	if( ( *str1 == *str2 ) && ( *str2 == *input ) )
	{
		return AreStringsInterleaved( str1 + 1, str2, input + 1 ) || AreStringsInterleaved( str1, str2 + 1, input + 1 );
	}
	else if( *str1 == *input )
	{
		return AreStringsInterleaved( str1 + 1, str2, input + 1 );
	}
	else if( *str2 == *input )
	{
		return AreStringsInterleaved( str1, str2 + 1, input + 1 );
	}
	else
	{
		return false;
	}
}

int main()
{
//	char str1[]  = "AAAAAEFG";
//	char str2[]  = "AAAAACDE";
//	char input[] = "AAAAACADAEAEAAFG";

	char str1[]  = "cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc";
	char str2[]  = "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb";
	char input[] = "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb";

	if( ( strlen( str1 ) + strlen( str2 ) ) == strlen( input ) )
	{
		printf("\n Are strings interleaved ? %d. \n", AreStringsInterleaved( str1, str2, input ) );
	}	

	return 0;
}
