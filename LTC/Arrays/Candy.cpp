# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings)
    {
        if( ratings.size() == 0 )
        {
            return 0;
        }
        else if( ratings.size() == 1 )
        {
            return 1;
        }
        
		vector<int> candies;
		candies.clear();

		for( int i = 0; i < ratings.size(); i++ )
		{
			candies.push_back( 1 );
		}

        for( int i = 1; i < ratings.size(); i++ )
        {
            if( ratings[ i ] > ratings[ i - 1 ] )
            {
                candies[ i ] = candies[ i - 1 ] + 1;
            }
        }
        
        int retVal = candies[ ratings.size() - 1 ];
        
        for( int i = ratings.size() - 2; i >= 0; i-- )
        {
            if( ratings[ i ] > ratings[ i + 1 ] && ( candies[ i ] <= candies[ i + 1] ) )
            {
                candies[ i ] = candies[ i + 1 ] + 1;
            }
            retVal += candies[ i ];
        }
        
        return retVal;
    }
};

int main()
{
	Solution s;

	vector<int> ratings;
	ratings.clear();

	ratings.push_back( 2 );
	ratings.push_back( 2 );

	cout << "Min required candies = " << s.candy( ratings ) << endl;

	return 0;
}
