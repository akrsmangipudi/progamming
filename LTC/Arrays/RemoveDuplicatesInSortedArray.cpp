# include <iostream>
# include <vector>
# include <climits>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if( nums.size() < 3 )
        {
            return nums.size();
        }
        
        int src = 0, dst = 0;
        
        int  previousElement = INT_MIN;
        bool elementCopiedTwice = false;
        
        while( src < nums.size() )
        {
            if( elementCopiedTwice )
            {
                if( !( nums[ src ] == previousElement ) )
                {
                    elementCopiedTwice = false;
                    previousElement = nums[ src ];
                    nums[ dst++ ]   = nums[ src ];
                }
            }
            else
            {
            	if( nums[ src ] == previousElement )
            	{
                	elementCopiedTwice = true;
                }
                
				nums[ dst++ ]   = nums[ src ];
				previousElement = nums[ src ];
            }
			src++;
        }
        return dst;
    }
};

int main()
{
	vector<int> input;
	input.push_back( 1 );
	input.push_back( 1 );
	input.push_back( 1 );
	input.push_back( 2 );
	input.push_back( 2 );
	input.push_back( 3 );
	
	Solution s;
	int count = s.removeDuplicates( input );

	cout << " count = " << count << endl;

	for( unsigned int i = 0; i < count; i++ )
	{
		cout << input[ i ] << endl;
	}
	
	return 0;
}
