# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > result( n, vector<int> ( n, 0 ) );
        result.clear();

		vector<int> temp( n, 0 );

		for( int i = 0; i < n; i++ )
		{
			result.push_back( temp );
		}

        
        if( n == 0 )
        {
            return result;
        }
        
        int count = 1;
        
        for(  int level = 0; level < (n+1)/2; level++ )
        {
            for( int i = level; i < n - level; i++ )
            {
                result[ level ][ i ] = count++;
            }
            
            for( int i = level + 1; i < n - 1 - level; i++ )
            {
                result[ i ][ n - 1 - level ] = count++;
            }
            
            for( int i = n - 1 - level; i >= level && ( n - 1 - level != level ) ; i-- )
            {
                result[ n - 1 - level ][ i ] = count++;
            }
            
            for( int i = n - 2 - level; i > level && ( n - 1 - level != level ); i-- )
            {
                result[ i ][ level ] = count++;
            }
        }
        
        return result;
    }
};

int main()
{
	Solution s;

	vector< vector<int> > result = s.generateMatrix( 4 );

	for( int outer = 0; outer < result.size(); outer++ )
	{
		cout << endl;
		for( int inner = 0; inner < result[0].size(); inner++ )
		{
			cout << " " << result[ outer ][ inner ];
		}
	}
	cout << endl;

	return 0;
}
