# include <iostream>
# include <string>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        
        if( n == 1 )
        {
            return "1";
        }
        
        if( n == 2 )
        {
            return "11";
        }
        
        string previous = "11";
        string current;
		current.clear();
        
        for( unsigned int i = 3; i <= n; i++ )
        {
            for( unsigned int j = 0; j < previous.length(); j++ )
            {
                unsigned char currVal = previous[j]; 
                unsigned int count   = 1;
                
                while( ( j != previous.length() - 1 ) && previous[ j ] == previous[ j + 1 ] )
                {
                    count++;

                    j++;
                }

				cout << " count = " << count << " and currVal = " << currVal << endl;
                
                current += to_string( count );
                current += currVal;
            }
            previous.clear();
            previous = current;
			current.clear();
        }
    	return previous;
    }    
};

int main()
{
	Solution s;

	string result = s.countAndSay( 7 );

	cout << "Result is " << result << "." << endl;
}
