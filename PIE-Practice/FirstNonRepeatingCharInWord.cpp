# include <iostream>
# include <string>
# include <map>
# include <stdio.h>

using namespace std;

char FirstNonRepeatingChar( char *input )
{
	char *iterator = input;

	map<char, int> m;

	while( *iterator != '\0' )
	{
		if( m.find( *iterator ) == m.end() )
		{
			m[ *iterator ] = 1;
			iterator++;
			continue;
		}
		
		m[ *iterator ] += 1;
		iterator++;
	}

	iterator = input;

	while( *iterator != '\0' )
	{
		if( m[ *iterator ] == 1 )
		{
			break;
		}
		iterator++;
		continue;
	}

	return *iterator;
}

using namespace std;

int main()
{
	char arr[] = "total";

	printf("\n First non-repeating character is %c. \n", FirstNonRepeatingChar( arr ) );	

	return 0;
}
