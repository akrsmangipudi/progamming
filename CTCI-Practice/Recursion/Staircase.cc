# include <iostream>
# include <stdint.h>
# include <map>

using namespace std;

int CountNumOfPossiblePaths( int numOfSteps )
{
	if( numOfSteps < 0 )
		return 0;

	if( numOfSteps == 0 )
		return 1;

	return CountNumOfPossiblePaths( numOfSteps - 1 ) + CountNumOfPossiblePaths( numOfSteps - 2 ) + CountNumOfPossiblePaths( numOfSteps - 3 );
}

int CountNumOfPossiblePaths( int numOfSteps, map<int, unsigned long> &m )
{
	if( numOfSteps < 0 )
	{
		return 0;
	}
	
	if( numOfSteps == 0 )
		return 1;

	if( m[ numOfSteps ] != 0 )
		return m[numOfSteps];

	m[ numOfSteps ] = CountNumOfPossiblePaths( numOfSteps - 1, m ) + CountNumOfPossiblePaths( numOfSteps - 2, m ) + CountNumOfPossiblePaths( numOfSteps - 3, m );

	return m[ numOfSteps ];
}

int main()
{
	int numOfSteps = 6;

	if( numOfSteps == 0 )
		return 0;

	map<int, unsigned long> m;

	cout << " (DP) Number of possible ways: " << CountNumOfPossiblePaths( numOfSteps, m ) << endl;
	
	// **** BAD CODE **** //
	cout << " (Recursion) Number of possible ways: " << CountNumOfPossiblePaths( numOfSteps ) << endl;

#if 0
	for( int i = 1; i <= numOfSteps; i++ )
	{
		cout << " m[" << i <<"] = " << m[i] << endl;
	}
#endif

	return 0;
}
