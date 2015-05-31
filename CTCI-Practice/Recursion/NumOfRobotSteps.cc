# include <iostream>
# include <map>
# include <algorithm>
# include <stdint.h>

using namespace std;

int NumOfPossiblePaths( map< pair<int, int>, uint32_t > &hashMap, int X, int Y, int currentRow, int currentColumn )
{
	if( ( currentColumn == ( Y  - 1 ) ) || ( currentRow == ( X - 1 ) ) )
	{
		return 1;
	}

	if( hashMap.find( make_pair( currentRow, currentColumn ) ) != hashMap.end() )
	{
		return hashMap[make_pair( currentRow, currentColumn ) ];
	}

	hashMap[ make_pair( currentRow, currentColumn ) ] = NumOfPossiblePaths( hashMap, X, Y, currentRow + 1, currentColumn ) + NumOfPossiblePaths( hashMap, X, Y, currentRow, currentColumn + 1 );

	return hashMap[ make_pair( currentRow, currentColumn ) ];
}


int main()
{
	int X = 2, Y = 2;

	map< pair<int, int>, uint32_t > hashMap;


	int row = 0, column = 0;

	cout << " Number of possible paths for robot: " << NumOfPossiblePaths( hashMap, X, Y, row, column ) << endl;

	return 0;
}
