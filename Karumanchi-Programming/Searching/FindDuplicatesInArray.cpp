# include "stlHeader.h"
# include <algorithm>
# include <iterator>
# include <map>
# include <string>
# include <stdlib.h>

void FindUsingHashMap( const vector<unsigned int> &v )
{
	map< int, pair <bool, bool> > m;

	for( int i = 0; i < v.size(); i++ )
	{
		if( m.find(v[i]) == m.end() )
		{
			m[ v[i] ] = make_pair(true, false);
		}
		else
		{
			pair<bool, bool> t = m[ v[i] ];
			if( !t.second )
				cout << " Element " << v[i] << " found as duplicate." <<endl;
			m[ v[i] ] = make_pair(true, true);			
		}
	}
}

void FindUsingSort( vector<unsigned int> v )
{
	int a[ v.size() ]; // = new int[v.size()];
	
	copy(v.begin(), v.end(), a);
	
	sort(a, a + v.size() );
	
	cout << " Size: " << v.size() << endl;
	cout << "Sorted Elements : " << endl;
	for( int i = 0; i < v.size(); i++ )
	{
		cout << " " << a[i];
	}
	cout << endl;

	for( int i = 0; i < (v.size() - 1); i++ )
	{
		if( a[i] == a[i+1] )
		{
				cout << " Element " << a[i] << " found as duplicate." <<endl;
				while( ( i < (v.size() - 1 ) ) && ( a[i+1] == a[i] ) )
				{
					i++;
				}
		}
	}
}

int main()
{
	vector< unsigned int > v;
	CreateArray( v );
//	FindUsingHashMap( v );
//	FindUsingSort( v );

	vector< int > n;
	n.push_back( 3 );
	n.push_back( 1 );
	n.push_back( 1 );
	n.push_back( 2 );
	n.push_back( 2 );
	n.push_back( 3 );
	n.push_back( 1 );

//	FindDuplicateElements( n );	

	return 0;
}
