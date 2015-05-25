# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int ConvertCharToHashIdx( char c )
{
	switch(c)
	{
		case ('R'):
			return 0;

		case ('G'):
			return 1;

		case ('B'):
			return 2;

		case ('y'):
			return 3;

		default:
			return -1;
	}
}

void CalculateHits( char *inputStr, char *guessStr, int *hits, int *pseudoHits )
{
	int hash[4];
	memset( hash, 0, sizeof(hash) );

	// Calculate the number of hits.
	int i = 0;
	while( inputStr[i] != '\0' )
	{
		if( inputStr[i] == guessStr[i] )
		{
			*hits += 1;
		}
		else
		{
			int hashIdx = ConvertCharToHashIdx( inputStr[i] );
			if( -1 != hashIdx )
			{
				hash[ hashIdx ] += 1;
			}
			else
			{
				printf("\n Source: -1 hash Idx returned for %c. \n", inputStr[i] );
			}
		}
		i++;
	}

	// Calculate the number of pseudo hits.	
	i = 0;
	while( guessStr[i] != '\0' )
	{
		if( guessStr[i] != inputStr[i] )
		{
			int hashIdx = ConvertCharToHashIdx( guessStr[i] );
			if( -1 != hashIdx )
			{
				if( 0 != hash[ hashIdx ] )
				{
					hash[ hashIdx ] -= 1;
					*pseudoHits += 1;
				}
			}
			else
			{
				printf("\n Guess: -1 hash Idx returned for %c. \n", guessStr[i] );
			}
		}
		i++;
	}
}

int main()
{
	char inputStr[ ] = "RGBY";
//	char guessStr[]  = "GGRY";
	char guessStr[]  = "GGRG";

	int hits = 0, pseudoHits = 0;

	CalculateHits( inputStr, guessStr, &hits, &pseudoHits );

	printf("\n Hits: %d. PseudoHits: %d. \n", hits, pseudoHits );

	return 0;
}
