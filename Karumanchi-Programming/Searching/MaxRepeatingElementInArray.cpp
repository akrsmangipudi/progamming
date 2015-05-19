# include <iostream>
# include <algorithm>
# include <iterator>
# include "stlHeader.h"
# include <map>

unsigned int FindMaxRepeatingElem( vector< unsigned int > &v )
{
	int retVal = -1;
	int n = v.size();
	int k = *(max_element( v.begin(), v.end() )) + 1;

	cout << " k == " << k << endl;

	for( int i = 0; i < n; i++ )
	{
		v[ v[i] % k ] += k;
	}
	
	cout << " After Manipulation" << endl;
	for( int i = 0; i < n; i++ )
	{
		cout << "\t" << v[i];
	}
	cout << endl;

	retVal =  ( find( v.begin(), v.end(), (*max_element( v.begin(), v.end() ) ) ) - v.begin() );

	for( int i = 0; i < n; i++ )
	{
		v[ i ] = v[ i ] % k;
	}
	
	cout << " After Restoration" << endl;
	for( int i = 0; i < n; i++ )
	{
		cout << "\t" << v[i];
	}
	cout << endl;

	return retVal;
}

unsigned int FindMaxRepeatingElemUsingSort( vector< unsigned int > v )
{
	int arr[ v.size() ];

	// Copy from vector to array.
	copy( v.begin(), v.end(), arr );

	// Sort the array.	
	sort( arr, arr + v.size() );

	int maxCount = 0;
	int element  = arr[0];

	for( int i = 0; i < v.size(); i++ )
	{
		int count = 1;

		while( ( i < v.size() - 1 ) && ( arr[i] == arr[i + 1] ) )
		{
			count++;	
			i++;
		}

		if( count > maxCount )
		{
			maxCount = count;
			element  = arr[i];
		}
	}
	cout << "Element " << element << " has repeated " << maxCount << " number of times." << endl;
	return maxCount;
}

unsigned int FindMaxRepeatingElemUsingHash( vector< unsigned int > v )
{
	// key is the element, and value is the number of times the element has repeated.
	map< int, int > m;

	// Insert the element into hash and increase its corresponding count.
	unsigned int maxCount = 0;
	unsigned int element  = 0;

	for( int i = 0; i < v.size(); i++ )
	{
		if( m.find( v[i] )  == m.end() )
		{
			m[ v[i] ] = 1;
			if( maxCount < m[ v[i] ] )
			{
				maxCount = m[ v[i] ];
				element  = v[i];
			}
		}
		else
		{
			m[ v[i] ] += 1;
			if( maxCount < m[ v[i] ] )
			{
				maxCount = m[ v[i] ];
				element  = v[i];
			}
		}
	}

	cout << "Element " << element << " has repeated " << maxCount << " number of times." << endl;
	return maxCount;
}

int main()
{
	vector< unsigned int > v;
	CreateArray( v );

	unsigned int retVal = FindMaxRepeatingElem( v );
	cout << " Return Val: " << retVal << "." << endl;
	
	unsigned int retVal1 = FindMaxRepeatingElemUsingHash( v );
	cout << " Return Val: " << retVal1 << "." << endl;

	unsigned int retVal2 = FindMaxRepeatingElemUsingSort( v );
	cout << " Return Val: " << retVal2 << "." << endl;

	return 0;
}
