# include <iostream>
# include <vector>
# include <string>

using namespace std;

void PrintAllPossibleSentences( vector< vector< string > > &input, unsigned int level, vector< string >& output )
{
	if( level == input.size() )
	{
		for( int idx = 0; idx < output.size(); idx++ )
		{
			cout << output[ idx ] << " ";
		}
		cout<< endl;
	}
	else
	{
		for( int idx = 0; idx < input[ level ].size(); idx ++ )
		{
			output.push_back( input[ level ][ idx ] );

			PrintAllPossibleSentences( input, level + 1, output );

			output.pop_back();
		}
	}	
}

int main()
{
	vector<string> list;

	vector< vector<string> > input;

	list.push_back( "you" );
	list.push_back( "we" );

	input.push_back( list );

	list.clear();

	list.push_back("have");
	list.push_back("are");
	
	input.push_back( list );
	
	list.clear();

	list.push_back("sleep");
	list.push_back("eat");
	list.push_back("drink");
	
	input.push_back( list );
	
	list.clear();

	vector< string > output;

	PrintAllPossibleSentences( input, 0, output );
	
	return 0;
}
