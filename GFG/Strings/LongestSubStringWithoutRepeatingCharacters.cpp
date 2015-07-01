# include <iostream>
# include <map>

using namespace std;

bool IsValidHash( map< char, int > &hashMap )
{
	bool retVal = true;

	for( map< char, int >::iterator it = hashMap.begin(); it != hashMap.end(); it++ )
	{
		if( it->second > 1 )
		{
			retVal = false;
			break;
		}
	}
	return retVal;
}

void PrintLongestUniqueSubsttr( string inputStr )
{
	unsigned int idx = 0;
	while( idx < inputStr.length() && inputStr[idx] == ' ' )
	{
		idx++;
	}

	if( ( 0 == inputStr.length() ) || ( idx == inputStr.length() ) )
	{
		return;
	}

	map< char, int > hashMap;
	hashMap.clear();

	unsigned int current_start = 0, current_end = 0;

	unsigned int max_window_size = 1, max_window_start = 0;

	hashMap[ inputStr[ 0 ] ] = 1;

	for( unsigned int idx = 1; idx < inputStr.length(); idx++ )
	{
		if( hashMap.find( inputStr[ idx ] ) == hashMap.end() )
		{
			hashMap[ inputStr[ idx ] ] = 1;
			current_end++;
		}
		else
		{
			hashMap[ inputStr[ idx ] ] += 1;
			current_end++;
		}

		while( !IsValidHash( hashMap ) )
		{
			hashMap[ inputStr[ current_start ] ] -= 1;
			current_start++;
		}

		if( current_end - current_start + 1 > max_window_size )
		{
			max_window_size  = current_end - current_start + 1;
			max_window_start = current_start;
		}
	}

	cout << "Max subtring is : " << inputStr.substr( max_window_start, max_window_size ) << " with length " << max_window_size << endl;
}

int main()
{
//	string inputStr = "ABDEFGABEF";

	string inputStr = "aabacbebebe";

    cout << "The input string is " << inputStr << endl;

    PrintLongestUniqueSubsttr( inputStr );
	
	return 0;
}
