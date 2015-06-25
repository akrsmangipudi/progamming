# include <iostream>
# include <vector>
# include <map>
# include <cstring>
# include <algorithm>

using namespace std;

unsigned int CalculateHashValueOfWord( string input )
{
	unsigned int retVal = 0;

	for( unsigned int i = 0; i < input.length(); i++ )
	{
		retVal += input[ i ];
	}

	return retVal;
}

void PrintAllAnagramsTogether( vector<string> &input, vector<string> &output )
{
	if( input.size() == 0 )
	{
		return;
	}

	// string - word, unsigned int - hash, bool - used
	map< string, pair< unsigned int, bool > > hashMap;

	for( unsigned int i = 0; i < input.size(); i++ )
	{
		hashMap[ input[ i ] ] = make_pair( CalculateHashValueOfWord( input[ i ] ), false );
	}

	for( unsigned int outerIdx = 0; outerIdx < input.size(); outerIdx++ )
	{
		pair< unsigned int, bool > outer = hashMap[ input[ outerIdx ] ];

		if( outer.second )
		{
			continue;
		}

		output.push_back( input[ outerIdx ] );

		hashMap[ input[ outerIdx ] ] = make_pair( outer.first, true );

		for( unsigned int innerIdx = outerIdx + 1; innerIdx < input.size(); innerIdx++ )
		{
			// If the lengths don't match, bail out.
			if( input[ innerIdx ].length() != input[ outerIdx ].length() )
			{
				continue;
			}
			
			// If the current word is already used, bail out. 
			pair< unsigned int, bool > inner = hashMap[ input[ innerIdx] ];
			if( inner.second )
			{
				continue;
			}
			
			// If the hash values don't match, bail out.
			if( outer.first != inner.first )
			{
				continue;
			}

			// Now the hash values match, check if the words are anagrams of each other or not.
			string out = input[ outerIdx ];
			string in  = input[ innerIdx ];

			sort( in.begin(), in.end() );
			sort( out.begin(), out.end() );

			if( out.compare( in ) != 0 )
			{
				continue;
			}

			output.push_back( input[ innerIdx ] );
			
			hashMap[ input[ innerIdx ] ] = make_pair( inner.first, true );
		}
	}
}

int main()
{
	vector<string> input;

	input.push_back( "aidtya" );
	input.push_back( "mamd" );
	input.push_back( "cat" );
	input.push_back( "dog" );
	input.push_back( "hell" );
	input.push_back( "acbd" );
	input.push_back( "tac" );
	input.push_back( "bell" );
	input.push_back( "god" );
	input.push_back( "aditya" );
	input.push_back( "idaayt" );
	input.push_back( "admm" );
	input.push_back( "act" );
	input.push_back( "abcd" );
	input.push_back( "dbab" );

	vector<string> output;

	PrintAllAnagramsTogether( input, output );

	for( unsigned int i = 0; i < output.size(); i++ )
	{
		cout << output[ i ] << endl;
	}

	return 0;
}
