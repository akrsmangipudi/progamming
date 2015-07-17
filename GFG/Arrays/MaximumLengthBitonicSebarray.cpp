# include <iostream>
# include <vector>
# include <stdlib.h>
# include <string.h>

using namespace std;

bool IsFullIncreasing( int *differenceArr, int length )
{
	for( int i = 0; i < length - 1; i++ )
	{
		if( differenceArr[ i ] >= differenceArr[ i + 1 ] )
		{
			return false;
		}
	}
	return true;
}

bool IsFullDecreasing( int *differenceArr, int length )
{
	for( int i = 0; i < length - 1; i++ )
	{
		if( differenceArr[ i ] <= differenceArr[ i + 1 ] )
		{
			return false;
		}
	}
	return true;
}

int CalculateMaxLength( int *differenceArr, int length )
{
	if( IsFullIncreasing( differenceArr, length ) || IsFullDecreasing( differenceArr, length ) )
	{
		return length + 1;
	}

	int maxLength = 0;

	int startIdx = 0;
	int endIdx   = 0;

	int i = 0;
	while( i < length )
	{		
		while( i < length && differenceArr[ i ] < 0 )
		{
			i++;
		}

		// Update our start index here with the positive.
		startIdx = i;
		endIdx   = i;
		i++;

		while( i < length && differenceArr[ i ] > 0 )
		{
			i++;
		}

		if( !(i < length) )
		{
			break;
		}

		while( i < length && differenceArr[ i ] < 0 )
		{
			endIdx = i;
			i++;
		}

		maxLength = max( maxLength, endIdx - startIdx + 2 ); // Since the operations are done on difference array, add 1 to the 'end - start + 1' value.		

		if( !( i < length ) )
		{
			break;
		}
	}
	return maxLength;
}

int main()
{
	vector<int> input;
	input.clear();

#if 0
	input.push_back( 12 );
	input.push_back( 4 );
	input.push_back( 78 );
	input.push_back( 90 );
	input.push_back( 45 );
	input.push_back( 23 );

	input.push_back( 20 );
	input.push_back( 4 );
	input.push_back( 1 );
	input.push_back( 2 );
	input.push_back( 3 );
	input.push_back( 4 );
	input.push_back( 2 );
	input.push_back( 10 );

	int differenceArr[ input.size() - 1 ];
	memset( differenceArr, 0, sizeof(int) * input.size() - 1 );

	for( int i = 1; i < input.size(); i++ )
	{
		differenceArr[ i - 1 ] = input[ i ] - input[ i - 1 ];
	}
#endif
	
	int *differenceArr = ( int * )malloc( sizeof( int ) * 15 );
	memset( differenceArr, 0, sizeof( int ) * 15 );

	differenceArr[ 0 ] = -16;
	differenceArr[ 1 ] = -3;
	differenceArr[ 2 ] = 1;
	differenceArr[ 3 ] = 1;
	differenceArr[ 4 ] = 1;
	differenceArr[ 5 ] = -2;
	differenceArr[ 6 ] = -6;
	differenceArr[ 7 ] = 8;
	differenceArr[ 8 ] = -2;
	differenceArr[ 9 ] = -3;
	differenceArr[ 10 ] = -14;
	differenceArr[ 11 ] = -3;
	differenceArr[ 12 ] = -10;
	differenceArr[ 13 ] = -11; 
	differenceArr[ 14 ] = -12;

	cout << " Maximum length of the bitonic sequence : " << CalculateMaxLength( differenceArr, sizeof( int ) * 15 ) << endl;

	return 0;
}

