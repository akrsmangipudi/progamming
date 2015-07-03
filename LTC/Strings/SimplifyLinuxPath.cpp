# include <iostream>
# include <stack>
# include <string>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> stk;

		string pushToStack;
		pushToStack.clear();
        
        for( unsigned int i = 0; i < path.length(); i++ )
        {
            if( path[ i ] == '/' )
            {
				if( i > 0 && path[ i - 1 ] == '/' )
				{
					continue;
				}
                pushToStack += path[ i ];
            }
            else if( path[ i ] == '.' )
            {
				if( i == path.length() - 1 )
				{
					continue;
				}
				
				// Single dot has been encountered. Disacrd the thus far populated pushToStack string.
				if( i < path.length() - 1 && path[ i + 1 ] != '.' )
				{
					pushToStack += '.';
					if( path[ i + 1 ] == '/' )
					{
						pushToStack.clear();
					}
				}
				else
				{
					unsigned int j = i;
					while( j < path.length() && path[ j ] == '.' )
					{
						pushToStack += path[ j ];
						j++;	
					}


					// We have reached end of the path.
					if( j == path.length() )
					{
						if( ( j - i ) == 2 )
						{
							if( !stk.empty() )
							{
								string discard = stk.top();
								stk.pop();						
							}
						}
						else
						{
                			stk.push( pushToStack );
						}
						pushToStack.clear();
					}
					else
					{
						if( ( j - i ) == 2 && path[ j ] == '/' )
						{
							if( !stk.empty() )
							{
								string discard = stk.top();
								stk.pop();						
							}
							pushToStack.clear();
						}
						else
						{
                			stk.push( pushToStack );
							pushToStack.clear();
						}
					}

					i = j - 1;
				}
            }
            else
            {
                while( i < path.length() && path[ i ] != '/' )
                {
                    pushToStack += path[ i ];
                    i++;
                }
                
                stk.push( pushToStack );
				pushToStack.clear();
				i--;
            }
        }
       
		if( stk.empty() && !pushToStack.empty() )
		{
			stk.push( pushToStack );
		}
		else if( stk.empty() && pushToStack.empty() )
		{
			stk.push( "/" );
		}
 
        string result;
        result.clear();
        
        while( !stk.empty() )
        {
            string stkResult;
            stkResult.clear();
            
            stkResult += stk.top();
            stk.pop();
            
            stkResult += result;
            
            result = stkResult;
       }

       return result;
    }
};

int main()
{
	Solution s;

	string result = s.simplifyPath("/../home/");

	cout << "Simplified path is " << result << endl;

	return 0;
}
