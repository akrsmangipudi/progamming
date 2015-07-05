# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target)
    {
        vector<vector<int> > result;
        result.clear();
        
        if( nums.size() < 4 )
        {
            return result;
        }
        
        sort( nums.begin(), nums.end() );
        
        int one, two, three, four;
        
        for( four = nums.size() - 1; four > 2; four-- )
        {
			if( ( four != nums.size() - 1 ) && ( nums[ four ] == nums[ four + 1 ] ) )
			{
				continue;
			}

            for( three = four - 1; three > 1; three-- )
            {
				if( ( three != ( four - 1 ) ) && ( nums[ three ] == nums[ three + 1 ] ) )
				{
					continue;
				}
                
				one = 0;
                two = three - 1;

				cout << one << two << three << four << endl;
                
                while( two > one )
                {
					int tempSum = nums[ one ] + nums[ two ] + nums[ three ] + nums[ four ];
                    
                    if( tempSum == target )
                    {
                        vector<int> temp;
                        temp.push_back( nums[ one ] );
                        temp.push_back( nums[ two ] );
                        temp.push_back( nums[ three ] );
                        temp.push_back( nums[ four ] );
                        
                        result.push_back( temp );
                        temp.clear();
					
						while( ( one < nums.size() - 1 ) && ( nums[ one ] == nums[ one + 1 ] ) )
                    	{
                        	one++;
	                    }
                    
    	                while( ( two > 0 ) && ( nums[ two ] == nums[ two - 1 ] ) )
        	            {
            	            two--;
                	    }
                        
                        one++;
                        two--;
                        continue;
                    }
                    
                    if( tempSum > target )
                    {
                        two--;
					}                    

                    else
                    {
                        one++;
                    }
                }
            }
        }
		return result;
    }
};

int main()
{
	Solution s;

	vector<int> input;

#if 0
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	input.push_back(2);
	input.push_back(2);
	input.push_back(2);
	input.push_back(2);
	input.push_back(2);
	input.push_back(2);
	input.push_back(3);
	input.push_back(3);
	input.push_back(3);
	input.push_back(3);
	input.push_back(3);
	input.push_back(3);
	input.push_back(4);
	input.push_back(4);
	input.push_back(4);
	input.push_back(4);
	input.push_back(4);
	input.push_back(4);
	input.push_back(5);
	input.push_back(5);
	input.push_back(5);
	input.push_back(5);
	input.push_back(5);
	input.push_back(5);
#endif

	input.push_back( 0 );
	input.push_back( 0 );
	input.push_back( 0 );
	input.push_back( 0 );

	vector<vector<int> > result = s.fourSum( input, 0 );

	for( unsigned int i = 0; i < result.size(); i++ )
	{
		cout << endl;
		for( unsigned int j = 0; j < result[0].size(); j++ )
		{
			cout << result[i][j];
		}
		cout << endl;
	}

	return 0;
}
