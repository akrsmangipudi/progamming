# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:

    void PopulateUniquePermutations( vector<int>& input, vector<vector<int> >& result, vector<int>& output, vector<bool>& used )
    {
        if( output.size() == input.size() )
        {
            result.push_back( output );
        }
        else
        {
            for( int i = 0; i < input.size(); i++ )
            {
                if( ( i != 0 ) && ( input[ i ] == input[ i - 1 ] ) && ( false == used[ i - 1 ] ) )
                {
                    continue;
                }
               
				if( used[ i ] )
				{
					continue;
				}
 
                output.push_back( input[ i ] );
                used[ i ] = true;
                
                PopulateUniquePermutations( input, result, output, used );
                
                output.pop_back();
                used[ i ] = false;
            }
        }
    }

    vector<vector<int> > permuteUnique(vector<int>& nums)
    {
        vector<vector<int> >result;
        result.clear();
        
        if( nums.size() == 0 )
        {
            return result;
        }
        
        vector<bool> used(nums.size(), false );
        
        vector<int> output;
        output.clear();
        
        PopulateUniquePermutations( nums, result, output, used );
    }
};

int main()
{
	Solution s;

	vector<int> input;
	input.clear();
	input.push_back(1);
	input.push_back(1);
	input.push_back(0);
	input.push_back(0);
	input.push_back(1);

//	sort( input.begin(), input.end() );

//	input.push_back(-1);
//	input.push_back(-1);
//	input.push_back(1);

	vector<vector<int> > result = s.permuteUnique( input );

	for( int i = 0; i < result.size(); i++ )
	{
		cout << endl;
		for( int j = 0; j < result[0].size(); j++ )
		{
			cout << " " << result[ i ][ j ];
		}
	}
	cout << endl;

	return 0;
}
