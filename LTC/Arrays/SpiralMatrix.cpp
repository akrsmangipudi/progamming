# include <iostream>
# include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
		vector<int> result;
		result.clear();

		int west  = matrix[0].size() - 1;
		int east  = 0;
		int north = 0;
		int south = matrix.size() - 1;

		cout << " east = " << east << " west = " << west << " north " << north << " south = " << south << endl;

		while( east <= west && north <= south )
		{
			for( int i = east; i <= west; i++ )
			{
				result.push_back( matrix[north][i] );
			}
			east++;

			for( int i = north + 1; i <= south ; i++ )
			{
				result.push_back( matrix[i][west] );
			}
			north++;

			if( east < west )
			{
				for( int i = west - 1; i>= east; i-- )
				{
					result.push_back( matrix[ south ][ i ] );
				}
				west--;
			}

			if( north < south )
			{
				for( int i = south; i >= north; i-- )
				{
					result.push_back( matrix[ i ][ east - 1 ] );
				}
				south--;
			}
		}
		return result;
	}       
};

int main()
{
	vector< vector<int> > matrix;
	matrix.clear();

	vector<int> input;
	input.clear();

	input.push_back( 1 );
	input.push_back( 2 );
	input.push_back( 3 );
	input.push_back( 4 );
	input.push_back( 5 );
	input.push_back( 6 );
	matrix.push_back( input );
	input.clear();

	input.push_back( 7 );
	input.push_back( 8 );
	input.push_back( 9 );
	input.push_back( 10 );
	input.push_back( 11 );
	input.push_back( 12 );
	matrix.push_back( input );
	input.clear();
	
	input.push_back( 13 );
	input.push_back( 14 );
	input.push_back( 15 );
	input.push_back( 16 );
	input.push_back( 17 );
	input.push_back( 18 );
	matrix.push_back( input );
	input.clear();
	
	Solution s;
	vector<int> result = s.spiralOrder( matrix );

	cout << endl;
	for( unsigned int i = 0; i < result.size(); i++ )
	{
		cout << " " << result[i];
	}
	cout << endl;
	
	return 0;
}
