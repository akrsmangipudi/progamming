# include <iostream>
# include <vector>
# include <algorithm>
# include <stdio.h>

using namespace std;

void S0s1s2s( vector<int> & v )
{
	int i = 0;
	int j = v.size() - 1;

	// Step 1 is to segreate 0s and 1s.
	while( i < j )
	{
		while( v[i] == 0 )
		{
			i++;
		}

		while( v[j] != 0 )
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

	j = v.size() - 1;

	printf("\n %d %d \n", i, j);

	// Step 2 is to segreate 1s and 2s.
	while( i < j )
	{
		while( v[i] == 1 )
		{
			i++;
		}

		while( v[j] != 1 )
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
	v.push_back( 0 );
	v.push_back( 1 );
	v.push_back( 1 );
	v.push_back( 0 );
	v.push_back( 1 );
	v.push_back( 2 );
	v.push_back( 1 );
	v.push_back( 2 );
	v.push_back( 0 );
	v.push_back( 0 );
	v.push_back( 0 );
	v.push_back( 1 );

	S0s1s2s( v );

	cout << endl;
	for( int i = 0; i < v.size(); i++ )
	{
		cout << " " << v[i];
	}
	cout << endl;

	return 0;
}
