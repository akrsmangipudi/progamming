# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if( nums.size() == 0 )
        {
            return 0;
        }
        
        int curr_start = 0, curr_end = 0, max_window_size = -1;
        int curr_sum   = nums[ curr_start ];
        
        while( curr_end < nums.size() )
        {
            while( curr_sum >= s )
            {
                if( ( -1 == max_window_size ) || ( max_window_size > ( curr_end - curr_start + 1 ) ) )
                {
                    max_window_size = curr_end - curr_start + 1;
                }
                
                curr_sum -= nums[ curr_start ];
                curr_start++;
                
                if( curr_start > curr_end )
                {
                    curr_end = curr_start;
                    
                    if( curr_end < nums.size() )
                    {
                        curr_sum += nums[ curr_end ];
                    }
                    break;
                }
            }
            
            if( !( curr_end < nums.size() - 1 ) )
            {
                break;
            }
            
            curr_end++;
            curr_sum += nums[ curr_end ];
        }
        
        if( max_window_size == - 1 )
        {
            return 0;
        }
        
        return max_window_size;
    }
};

int main()
{
	Solution s;

	vector<int> input;
	input.clear();

	input.push_back( 2 );
	input.push_back( 3 );
	input.push_back( 1 );
	input.push_back( 2 );
	input.push_back( 4 );
	input.push_back( 3 );

	cout << " Min subarray size = " << s.minSubArrayLen( 7, input ) << "." << endl;
	
}
