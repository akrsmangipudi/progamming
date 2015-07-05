# include <iostream>
# include <string>

using namespace std;

class Solution 
{
public:

    void reverseII( string &s )
    {
        unsigned int i = 0;
        while( i < ( s.length()/2 ) )
        {
            char temp = s[ i ];
            s[ i ]    = s[ s.length() - 1 - i ];
            s[ s.length() - 1 - i ] = temp;
            i++;
        }
    }

    string convertToTitle(int n)
    {
        string result;
        result.clear();
        
        while( n > 0 )
        {
            if( n % 26 == 0 )
            {
                result += 'Z';
                n = n/26 - 1;
            }
            else
            {
                result += 'A' + ( n % 26 ) - 1;
                n = n/26;
            }
        }
        
        reverseII( result );
        return result;
    }
};

int main()
{
	Solution s;

	string result = s.convertToTitle( 28 );
	
	return 0;
}
