# include <iostream>
# include <vector>
# include <string>
# include <stdlib.h>
# include <algorithm>

using namespace std;

class Solution

{

public:

    void PrintAllPossibleIPAddressGenerations( string input, string &output, vector<string> &result, unsigned int currStartIdx, unsigned int insertIdx, unsigned int level )
    {
        if( level == 4 )
        {
            if( currStartIdx != input.length() )
            {
                return;
            }

            cout << output << endl;
            result.push_back( output );
        }
        else
        {
            for( unsigned int i = 0; i < 3; i++ )
            {
                if( currStartIdx + i + 1 > input.length() )
                {
                    return;    
                }
                
                string insertStr = input.substr( currStartIdx, i + 1 );
                
                if( i > 0 )
                {
                    if( insertStr[ 0 ] == '0' )
                    {
                        continue;
                    }
                }
    
                if( atoi( insertStr.c_str() ) > 255 )
                {
                    return;
                }
    
                unsigned int count = ( level == 3 ) ? i + 1 : i + 2;
    
                output += insertStr;
    
                if( level != 3)
                    output += '.';
    
                PrintAllPossibleIPAddressGenerations( input, output, result, currStartIdx + i + 1, insertIdx + count, level + 1 );
    
                output.erase( insertIdx, count );
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        result.clear();

        if( s.length() < 4 || s.length() > 12 )
        {
            return result;
        }

        string output;
        output.clear();

        PrintAllPossibleIPAddressGenerations( s, output, result, 0, 0, 0 );
    }
};

int main()
{
	Solution s;
	string str ="010010";
	vector<string> output = s.restoreIpAddresses( str );
	return 0;
}
