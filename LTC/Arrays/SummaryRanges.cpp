# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> result;
        result.clear();
        
        int currentStartValue = 0;
        int currentEndValue   = 0;
        
        for( unsigned int i = 0; i < nums.size(); i++ )
        {
            currentStartValue = nums[i];
            currentEndValue   = nums[i];
            
            while( ( i < ( nums.size() - 1 ) ) && (  ( nums[ i ] + 1 ) == nums [ i + 1 ] ) )
            {
                currentEndValue = nums[ i + 1];
                i++;
            }
            
            if( currentStartValue == currentEndValue )
            {
                string pushString = to_string( currentStartValue );
                result.push_back( pushString );
            }
            else
            {
                string pushString = to_string( currentStartValue ) + "->" + to_string( currentEndValue );
                result.push_back( pushString );
            }
        }
		return result;
    }
};

int main()
{
	Solution s;

	vector<int> input;
	input.push_back( 0 );
	input.push_back( 2 );
	input.push_back( 3 );
	input.push_back( 4 );
	input.push_back( 5 );
	input.push_back( 7 );

	vector<string> result = s.summaryRanges( input );

	for( unsigned int i = 0; i < result.size(); i++ )
	{
		cout << result[i] << endl;
	}
}
