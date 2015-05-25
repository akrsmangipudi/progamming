# include <stdio.h>
# include <string.h>

int AreStringsPermutations( char *string1, char *string2 )
{
	if( strlen(string1) != strlen(string2) )
	{
		return 0;
	}

	int hashArray[26];
	memset( hashArray, 0, sizeof(hashArray) );

	while( *string1 != '\0' )
	{
		hashArray[ *string1 - 'a' ] += 1;
		string1++;
	}
	
	while( *string2 != '\0' )
	{
		if( hashArray[ *string2 - 'a' ] <= 0 )
		{
			return 0;
		}

		hashArray[ *string2 - 'a'] -= 1;
		string2++;
	}

	int i = 0;
	for( i = 0; i < 26; i++ )
	{
		if( hashArray[i] != 0 )
		{
			return 0;
		}
	}

	return 1;

}


int main()
{
	char string1[] = "geeksforgeeks";
	char string2[] = "forgeeksgeek";

	printf("\n Are Strings Permutations of each other? %d. \n", AreStringsPermutations( string1, string2 ) );

	return 0;
}
