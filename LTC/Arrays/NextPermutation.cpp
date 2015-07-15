# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        if( nums.size() == 0 || nums.size() == 1 )
        {
            return;
        }
        
        // Find an element that need to be manipulated to get our desired output.
        // This element is the first element that is decreasing when traversed from the right side of the array.
        // If no such element is found, we just sort the entire input set and return.
        
        // Start from the last but one element to the right of the array.
        int idx = nums.size() - 2;
        
        for( ; idx >= 0; idx-- )
        {
            if( nums[ idx ]  < nums[ idx + 1 ] )
            {
                break;
            }
        }
        
        // No element to replace has been found. We just need to sort the entire input set and return.
        if( idx < 0 )
        {
            sort( nums.begin(), nums.end() );
            return;
        }
        
        // At this point, 'idx' is referring to the index of the element that can be swapped with the next highest number to the right of it.
        // We can achieve this by sorting all the elements to the right of the idx, and by swapping the smallest element which is larger than
        // the element at 'idx' with it.
        sort( nums.begin() + idx + 1, nums.end() );
        
        int nextHighestIdx = idx + 1;
        for( ; nextHighestIdx < nums.size(); nextHighestIdx++ )
        {
            if( nums[ nextHighestIdx ] > nums[ idx ] )
            {
                break;
            }
        }
        
        swap( nums[ idx ], nums[ nextHighestIdx ] );
    }
};

int main()
{
	Solution s;

	vector<int> input;
	input.clear();

	input.push_back( 1 );
	input.push_back( 1 );
	input.push_back( 5 );
#if 0
	input.push_back( 1 );
	input.push_back( 8 );
	input.push_back( 6 );
	input.push_back( 6 );
	input.push_back( 0 );
#endif

	s.nextPermutation( input );
	
	cout << endl;
	for( int i = 0; i < input.size(); i++ )
	{
		cout << " " << input[ i ];
	}
	cout << endl;

	return 0;
}
