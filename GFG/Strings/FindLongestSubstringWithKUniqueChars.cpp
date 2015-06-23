# include <iostream>
# include <cstring>
# include <map>

using namespace std;

bool IsValid( map< char, int > &hashMap, unsigned int k )
{
	unsigned int count = 0;
	for ( map< char, int >::iterator it = hashMap.begin(); it != hashMap.end(); it++ )
	{
		if( it->second > 0 )
			count++;
	}

	return ( count <= k );
}

void PrintLongestSubString( string inputStr, unsigned int k )
{
	if( ( inputStr.length() == 0 ) || ( 0 == k ) )
	{
		return;
	}

	map<char, int> hashMap;

	unsigned int numOfUniqueChars = 0;

	for( int i = 0; i < inputStr.length() ; i++ )
	{
		if( hashMap.find( inputStr[ i ] ) == hashMap.end() )
		{
			hashMap[ inputStr[ i ] ] = 1;
			numOfUniqueChars++; 
		}
		else
		{
			hashMap[ inputStr[ i ] ] += 1;
		}
	}

	if( numOfUniqueChars < k )
	{
		cout << " Number of unique chars is less." << endl;
		return;
	}

	unsigned int current_start = 0, current_end = 0;

	unsigned int max_window_size = 1, max_window_start = 0;

	hashMap.clear();

	// Copy the first element into the hashmap.
	hashMap[ inputStr[ 0 ] ] = 1;

	for( int i = 1; i < inputStr.length(); i++ )
	{
		if( hashMap.find( inputStr[ i ] ) == hashMap.end() )
		{
			hashMap[ inputStr[ i ] ] = 1;
			current_end++;
		}
		else
		{
			hashMap[ inputStr[ i ] ] += 1;
			current_end++;
		}

		while( !IsValid( hashMap, k ) )
		{
			hashMap[ inputStr[ current_start ] ]--;
			current_start++;
		}

		if( ( current_end - current_start + 1 ) > max_window_size )
		{
			max_window_size  = current_end - current_start + 1;
			max_window_start = current_start;
		}
	}

	cout << "Max subtring is : " << inputStr.substr( max_window_start, max_window_size ) << " with length " << max_window_size << endl;
}

int main()
{
	unsigned int k = 3;

	PrintLongestSubString( "aabacbebebe", k );
	
	//PrintLongestSubString( "abcdadjgasewtaadsrrrrsadsajytjjyytttjaaaa", k );
	//PrintLongestSubString( "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdefghijklmnopqrstuvwxyzaabbccdd", k );

	return 0;
}
