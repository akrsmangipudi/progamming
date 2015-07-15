# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:

    void PopulateAllPossibleCombinations( vector<vector<int> > &result, vector<int> &output, int level, int targetSum, int &currSum, int k, int startIdx )
    {
        for( int i = startIdx; i <= 9; i++ )
        {

			if( output.size() > 0 && output[ 0 ] == 1 )
			{
				cout << " Hello " << endl;
			}

            if( level > ( k - 1 ) )
            {
                return;
            }
            
            currSum += i;
            output.push_back( i );
            
            if( currSum > targetSum )
            {
                output.pop_back();
                
                currSum -= i;
                
                return;
            }
            
            if( currSum == targetSum )
            {
                if( level == ( k - 1 ) )
                {
                    result.push_back( output );
				}
                    
                output.pop_back();
                    
                currSum -= i;
                
				return;   
            }
            
            PopulateAllPossibleCombinations( result, output, level + 1, targetSum, currSum, k, i + 1 );
           

			if( 0 == level )
			{
				cout << " Hi; currSum = " << currSum << " output.size() = " << output.size() << endl;
			}
 
            output.pop_back();
            
            currSum -= i;
        }
    }

    vector<vector<int> > combinationSum3(int k, int n)
    {
        vector<vector<int> > result;
        result.clear();
        
        if( n <= 0 )
        {
            return result;
        }
        
        vector<int> output;
        output.clear();
        
        int currSum = 0;
        PopulateAllPossibleCombinations( result, output, 0, n, currSum, k, 1 );
        
        return result;
    }
};

int main()
{
	Solution s;

	vector< vector<int> > result = s.combinationSum3( 3, 9 );

	for( unsigned int i = 0; i < result.size(); i++ )
	{
		cout << endl;
		for( unsigned int j = 0; j < result[0].size(); j++ )
		{
			cout << result[ i ][ j ];
		}
		cout << endl;
	}

	return 0;
}
