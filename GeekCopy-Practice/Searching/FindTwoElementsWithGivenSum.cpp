# include "stlHeader.h"
# include <algorithm>
# include <iterator>
# include <map>

void FindUsingHashMap( const vector<unsigned int> &v, unsigned int sum )
{	
	map<int, bool> m;
	int tempSum = 0;
	for( int i = 0; i < v.size(); i++ )
	{
		tempSum = sum - v[i];
		if( ( tempSum >= 0 ) && m[ tempSum ] )
		{
			cout << " Element 1: " << v[i] << " Element 2: " << tempSum << endl;
		}

		m[ v[i] ] = true;
	}
}

#if 0
void FindUsingSort( vector<int> v )
{
	int a[ v.size() ]; // = new int[v.size()];
	copy(v.begin(), v.end(), a);
	sort(a, a + v.size() );
//	sort( a, v.size());
	
//	sort( v.begin(), v.end() );
	for( int i = 0; i < (v.size() - 1); i++ )
	{
		if( a[i] == a[i+1] )
		{
				cout << " Element " << a[i] << " found as duplicate." <<endl;
				while( i < (v.size() - 1) && (a[i+1] == a[i] ) )
				{
					i++;
				}
		}
	}
}
#endif

int main()
{
	vector< unsigned int > v;
	CreateArray( v );
	FindUsingHashMap( v, 10 );

	return 0;
}
