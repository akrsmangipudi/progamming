# include <iostream>
# include <cstring>
# include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string result;
        result.clear();
        
        if( strs.size() == 0 )
        {
            return result;
        }
       
        if( strs.size() == 1 )
        {
            return strs[0];    
        }
        
        for( unsigned int i = 0; i < strs[0].length(); i++ )
        {
            char reference = strs[0][i];
            for( unsigned int j = 1; j < strs.size(); j++ )
            {
                if( i < strs[j].length() && strs[j][i] == reference )
                {
					if( j == ( strs.size() - 1 ) )
					{
						result += reference;
					}
                    continue;
                }
                else
                {
                    return result;
                }
                
            }
        }
        
        return result;
    }
};

int main()
{
	Solution s;
	vector<string> input;

	input.push_back("c");
	input.push_back("cc");

	string result = s.longestCommonPrefix( input );

	cout << "Result " << result << "." << endl;

	return 0;
}
