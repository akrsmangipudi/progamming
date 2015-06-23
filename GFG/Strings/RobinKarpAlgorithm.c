# include <stdio.h>
# include <string.h>

// Defines the number of possible different characters in the given input set.
# define d 256

void search( char *pattern, char *text, int q )
{
	if( strlen( pattern ) > strlen( text ) )
	{
		printf("\n Invalid evaluation set. Return. \n");
		return;
	}

	int textHash  = 0; // Hash value of the window from the text of length equal to the length of the pattern.
	int pattHash  = 0; // Hash value of the pattern that we want to compare in the text
	int helperVal = 1; // Helper variable for hash value computations, equal to d^m-1; where 'd' is the number of possible character sets in the input and 'm' is the pattern length.

	// Indices on which we iterate.
	int i = -1, j = -1;

	// Calculate the value of the 'helperVal' variable.
	for( i = 0; i < strlen( pattern ) - 1; i++ )
	{
		helperVal = ( helperVal * d ) % q;
	}

	// Calculate the hash value for the pattern and for the initial pattern length window from the text.
	for( i = 0; i < strlen( pattern ); i++ )
	{
		pattHash = ( pattHash * d + pattern[ i ] ) % q;
		textHash = ( textHash * d + text[ i ] ) % q;
	}

	for( i = 0; i <= ( strlen( text ) - strlen( pattern ) ); i++ )
	{
		if( pattHash == textHash )
		{
			for( j = 0 ; j < strlen( pattern) ; j++ )
			{
				if( pattern[ j ] != text[ i + j ] )
				{
					break;
				}

				if( j == ( strlen( pattern ) - 1 ) )
				{
					printf("\n Pattern %s found at position %d. \n", pattern, i );
				}
			}
		}

		if( i != ( strlen( text ) - strlen( pattern ) ) )
		{
			textHash = ( d * ( textHash - ( text[ i ] * helperVal ) ) + text[ i + strlen( pattern ) ] ) % q;
			if( textHash < 0 )
				textHash += q;
		}
	}
}

int main()
{
	char *txt = "23590131415267314159921";
    char *pat = "31415";
    int q = 101;  // A prime number
    search(pat, txt, q);
	return 0;
}
