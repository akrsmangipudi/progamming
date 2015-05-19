# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

void EvenFollowedByOdd( vector<int> & v )
{
	int i = 0;
	int j = v.size() - 1;

	while( i < j )
	{
		while( v[i] % 2 == 0 )
		{
			i++;
		}

		while( v[j] % 2 == 1 )
		{
			j--;
		}

		if( i < j )
		{
			swap( v[i], v[j] );
			i++;
			j--;
		}
	}

}

int main()
{
	vector<int> v;
	v.push_back( 1 );
	v.push_back( 2 );
	v.push_back( 3 );
	v.push_back( 4 );
	v.push_back( 5 );
	v.push_back( 6 );
	v.push_back( 7 );
	v.push_back( 8 );

	EvenFollowedByOdd( v );

	cout << endl;
	for( int i = 0; i < v.size(); i++ )
	{
		cout << " " << v[i];
	}
	cout << endl;

	return 0;
}
