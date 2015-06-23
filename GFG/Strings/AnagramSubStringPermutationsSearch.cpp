# include <iostream>
# include <string>
# include <map>

using namespace std;

template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs)
{
    // No predicate needed because there is operator== for pairs already.
    return ( lhs.size() == rhs.size() ) && equal( lhs.begin(), lhs.end(), rhs.begin() );
}

void PrintAllPossibleAnagrams( string input, string pattern )
{
	if( input.length() == 0 || pattern.length() == 0 )
	{
		return;
	}
	if( input.length() < pattern.length() )
	{
		return;
	}

	unsigned int patternHash = 0;
	unsigned int textHash    = 0;
	
	map< char, int > hashMap;	

	for( int i = 0; i < pattern.length(); i++ )
	{
		patternHash += pattern[ i ];
		textHash    += input[ i ]; 

		if( hashMap.find( pattern[ i ] ) == hashMap.end() )
		{
			hashMap[ pattern[ i ] ] = 1;
		}
		else
		{
			hashMap[ pattern[ i ] ] += 1;
		}
	}

	patternHash %= 257;
	textHash %= 257;

	for( int i = 0; i <= ( input.length() - pattern.length() ); i++ )
	{
		// Hash values of the pattern and input have matched ! Iterate through the text and see if it matches any of the characters in the pattern.
		if( patternHash == textHash )
		{
			map< char, int > hashMap2;
			for( int k = i; k < ( i + pattern.length() ); k++ )
			{
				if( hashMap2.find( input[ k ] ) == hashMap.end() )
				{
					hashMap2[ input[ k ] ] = 1;
				}
				else
				{
					hashMap2[ input[ k ] ] += 1;
				}
			}

			if( map_compare( hashMap, hashMap2 ) )
			{
				cout << " Found at position : " << i << endl;
			}

			hashMap2.clear();
		}

		// Recompute the hash for the next window.
		if( i != ( input.length() - pattern.length() ) )
		{
			textHash += 257;
			textHash  = ( textHash - input[ i ] + input[ i + pattern.length() ] ) % 257;
		}
	}
}

int main()
{
	string input   = "AAABABAA";
	string pattern = "AABA";

	PrintAllPossibleAnagrams( input, pattern );

	return 0;
}
