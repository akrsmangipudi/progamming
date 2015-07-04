# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        unsigned int numOfRotations = k % nums.size();
        
        if( numOfRotations == 0 )
        {
            return;
        }
        
        unsigned int firstEndIdx = nums.size() - numOfRotations;
        
        reverse( nums.begin(), nums.begin() + firstEndIdx );

        reverse( nums.begin() + firstEndIdx, nums.end() );
		
        reverse( nums.begin(), nums.end() );        
    }
};

int main()
{
	Solution s;

	vector<int> input;
	input.push_back( 1 );
	input.push_back( 2 );
	input.push_back( 3 );
	input.push_back( 4 );
	input.push_back( 5 );
	input.push_back( 6 );
	input.push_back( 7 );

	s.rotate( input, 1 );
	
	for( unsigned int i = 0; i < input.size(); i++ )
	{
		cout << input[i] << endl;
	}

}
