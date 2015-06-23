# include <iostream>
# include <cstring>

using namespace std;

bool CheckIfSubsequence_Recursive( string pattern, string source, int patternLen, int sourceLen, int m, int n )
{
	if( m == patternLen )
	{
		return true;
	}

	if( n == sourceLen )
	{
		return false;
	}

	if( pattern[ m ] == source [ n ] )
	{
		return CheckIfSubsequence_Recursive( pattern, source, patternLen, sourceLen, m + 1, n + 1 );
	}
	else
	{
		return CheckIfSubsequence_Recursive( pattern, source, patternLen, sourceLen, m, n + 1 );
	}
}

bool CheckIfSubsequence_Iterative( string pattern, string source, int patternLen, int sourceLen )
{
	unsigned int i =0, j =0;

	for( i = 0; i < sourceLen && j < patternLen; i++ )
	{
		if( pattern[ j ] == source[ i ] )
		{
			j++;
		}
	}
	return ( j == patternLen );
}

int main()
{
	cout << " Is subsequence ? " << CheckIfSubsequence_Iterative( "AXY", "ADXCPY", 3, 6 ) << "." << endl;
	cout << " Is subsequence ? " << CheckIfSubsequence_Iterative( "AXY", "YADXCP", 3, 6 ) << "." << endl;
	cout << " Is subsequence ? " << CheckIfSubsequence_Iterative( "gksrek", "geeksforgeeks", 6, 15 ) << "." << endl;
	
	cout << " Is subsequence ? " << CheckIfSubsequence_Recursive( "AXY", "ADXCPY", 3, 6, 0, 0 ) << "." << endl;
	cout << " Is subsequence ? " << CheckIfSubsequence_Recursive( "AXY", "YADXCP", 3, 6, 0, 0 ) << "." << endl;
	cout << " Is subsequence ? " << CheckIfSubsequence_Recursive( "gksrek", "geeksforgeeks", 6, 15, 0, 0 ) << "." << endl;
	return 0;
}
