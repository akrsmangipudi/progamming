# include <iostream>
# include <cstring>
# include <vector>

using namespace std;

void CheckIfCircleCanBeFormed( vector<string> &input, vector<string> &output, vector<bool> &used, unsigned int level, bool &seqFound )
{
	if( level == input.size() )
	{
		string s = output[ 0 ];
		string t = output[ output.size() - 1 ];

		if( s[ 0 ] == t[ t.length() - 1 ] )
		{
			cout << endl;
			for( int i = 0; i < output.size(); i++ )
			{
				cout << " " << output[ i ];
			}
			cout << endl;
			seqFound = true;
		}
	}

	for( int i = 0; i < input.size(); i++ )
	{
		if( true == used[ i ] )
		{
			continue;
		}

		if( 0 != level )
		{
			string s = output[ level - 1 ];
			string t = input[ i ];
			if( s[ s.length() - 1 ] != t[ 0 ] )
			{
				continue;
			}
		}

		used[ i ] = true;

		output.push_back( input[ i ] );

		CheckIfCircleCanBeFormed( input, output, used, level + 1, seqFound );

		if( true == seqFound )
			return;

		used[ i ] = false;

		output.pop_back( );
	}
}

int main()
{
	vector<string> input;

//  Input set 1
//	input.push_back( "geek" );
//	input.push_back( "king" );

//  Input set 2
//	input.push_back( "geek" );
//	input.push_back( "kaf" );
//	input.push_back( "rig" );
//	input.push_back( "for" );

//  Input set 3
	input.push_back( "bbb" );
	input.push_back( "aab" );
	input.push_back( "aaa" );
	input.push_back( "baa" );

//  Input set 4
//	input.push_back( "aaa" );
//	input.push_back( "bbb" );
	
//  Input set 5
//	input.push_back( "aaa" );

//  Input set 5
//	input.push_back( "aab" );
//	input.push_back( "abb" );

	vector<string> output;

	vector<bool> used( input.size() );
	for( int i = 0; i < input.size(); i++ )
	{
		used[ i ] = false;
	}
	
	bool seqFound = false;

	CheckIfCircleCanBeFormed( input, output, used, 0, seqFound );

	cout << " Can form a circle with strings? " << seqFound << "." << endl;

	return 0;
}
