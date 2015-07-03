# include <iostream>
# include <vector>
# include <map>
# include <string.h>

using namespace std;

class Solution
{
public:

    void PrintKeyPadMappings( string input, string &output, vector<string> &result, map<int, string> &hashMap, unsigned int inputLen, unsigned int level )
    {
        if( level == inputLen )
        {
			cout << output << endl;
            result.push_back(output);
        }
        else
        {
            for( unsigned int i = 0; i < hashMap[ input[ level ] -'0' ].length(); i++ )
            {
                output += hashMap[ input[ level ] - '0' ][ i ];
                
                PrintKeyPadMappings( input, output, result, hashMap, inputLen, level + 1 );
                
                output.erase( output.length() - 1, 1 );
            }
        }
    }
    
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        result.clear();
        
        if( digits.length() == 0 )
        {
            return result;    
        }
        
        map<int, string> hashMap;
        
        hashMap[ 0 ] = "0";
        hashMap[ 1 ] = "1";
        hashMap[ 2 ] = "abc";
        hashMap[ 3 ] = "def";
        hashMap[ 4 ] = "ghi";
        hashMap[ 5 ] = "jkl";
        hashMap[ 6 ] = "mno";
        hashMap[ 7 ] = "pqrs";
        hashMap[ 8 ] = "tuv";
        hashMap[ 9 ] = "wxyz";

		string output;
		output.clear();       
 
        PrintKeyPadMappings( digits, output, result, hashMap, digits.length(), 0 );
    }
};

int main()
{
	Solution s;
	s.letterCombinations( "23" );
	return 0;
}
