# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if( nums.size() == 0 )
        {
            return 1;
        }
        
        int i_left  = 0;
        int j_right = nums.size() - 1;
        
        // Segregate all negative numbers to the start of the array, followed by all the positive elements.
        while( i_left < j_right )
        {
            while( i_left < nums.size() && nums[ i_left ] < 0 )
            {
                i_left++;
            }
            
            while( j_right >= 0 && nums[ j_right ] > 0 )
            {
                j_right--;
            }
            
            if( i_left > j_right )
            {
                break;
            }
            
            swap( nums[ i_left ], nums[ j_right ] );
            
            i_left++;
            j_right--;
        }
        
        // At the end of this operation, i_left is pointing to the first positive element in the input array.
        // Toggle the sign on all the negative elements, i.e. make all of these positive.
        for( int i = 0; i < i_left; i++ )
        {
            nums[ i ] = -nums[ i ];
        }
        
        // At this point, the entire input array is consisting of all positive elements.
        for( int i = i_left; i < nums.size(); i++ )
        {
            nums[ abs( nums[ i ] - 1 ) ] = -nums[ abs( nums[ i ] - 1 ) ];
        }
        
        for( int i = 0; i < nums.size(); i++ )
        {
            if( nums[ i ] > 0 )
            {
                return i + 1;
            }
        }
        
        return nums.size() + 1;
    }
};

int main()
{
	Solution s;

	vector<int> input;
	input.clear();

	input.push_back( 1 );
	input.push_back( 2 );
	input.push_back( 3 );
	input.push_back( 4 );
	input.push_back( 5 );
	input.push_back( 6 );
	input.push_back( 7 );
	input.push_back( 8 );
	input.push_back( 9 );
	input.push_back( 10 );

	cout << " First missing positive is: " << s.firstMissingPositive( input ) << endl;

	return 0;
}
