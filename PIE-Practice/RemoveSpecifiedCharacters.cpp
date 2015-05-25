# include <iostream>
# include <map>

using namespace std;

void RemoveCharactersFromInput( char *inputString, char *removeChars )
{
	map< char, int > m;

	while( *removeChars != '\0' )
	{
		m[ *removeChars ] = 1;
		removeChars++;
	}

	int source = 0, dest = 0;

	while( inputString[source] != '\0' )
	{
		if( 0 == m[ inputString[source] ] )
		{
			inputString[dest++] = inputString[source++];
			continue;
		}
		source++;
	}

	inputString[ dest ] = '\0';
}

int main()
{
	char input[] = "Battle of the Vowels: Hawaii vs. Grozny";
	char remove[] = "aeiou";

	RemoveCharactersFromInput( input, remove );

	cout << " Updated string is : " << input << endl;

	return 0;
}
