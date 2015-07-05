# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:
    
    void RecurseAndPopulateUniqueCombinations( vector<int> &input, vector<int> &output, vector<vector<int> > &result, int target, int &currSum, int idx )
    {
        for( unsigned int currIdx = idx; currIdx < input.size(); currIdx++ )
        {
            currSum += input[ currIdx ];

			cout << " currSum = "     << currSum << endl;
        
            // If the currentSum > targetSum, return to the previous level.
            if( currSum > target )
            {
				currSum -= input[ currIdx ];
                return;
            }
            
            output.push_back( input[ currIdx ] );
            
            // If the currSum == target, push the result to the output vector and return.
            if( currSum == target )
            {
                result.push_back( output );
				output.pop_back();
				currSum -= input[ currIdx ];
                return;
            }
            
            RecurseAndPopulateUniqueCombinations( input, output, result, target, currSum, currIdx );
           
            output.pop_back();
			currSum -= input[ currIdx ]; 
        }
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        sort( candidates.begin(), candidates.end() );
        
        vector< vector<int> > result;
        result.clear();
        
        vector<int> output;
        
        int currSum = 0;
        
        RecurseAndPopulateUniqueCombinations( candidates, output, result, target, currSum, 0 );

		return result;
    }
};

int main()
{
	vector<int> input;
	input.clear();

	input.push_back( 2 );
	input.push_back( 2 );
	input.push_back( 3 );
	input.push_back( 3 );
	input.push_back( 6 );
	input.push_back( 7 );

	Solution s;
	vector<vector<int> >result = s.combinationSum( input, 7 );

	for( unsigned int i = 0; i < result.size(); i++ )
	{
		cout << endl;
		for( unsigned int j = 0; j < result[i].size(); j++ )
		{
			cout << result[i][j];
		}
		cout << endl;
	}

	return 0;
}
