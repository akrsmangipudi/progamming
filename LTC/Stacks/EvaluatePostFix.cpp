# include <iostream>
# include <vector>
# include <string>
# include <stack>

using namespace std;

class Solution {
public:

    bool isDigit( string s )
    {
		int idx = 0;

		if( s.length() == 1 )
		{
			if( s[ 0 ] == '-' || s[ 0 ] == '+' )
			{
				return false;
			}
		}
		else if( s[ 0 ] == '-' || s[0] == '+' )
		{
			idx = 1;
		}

        for( int i = idx; i < s.length(); i++ )
        {
            if( !isdigit( s[ i ] ) )
            {
                return false;
            }
        }
        return true;
    }
    
    int convertStrToInt( string s )
    {
        int idx = 0;
        
        if( s[0] == '-' )
        {
            idx = 1;
        }
        
        int retVal = 0;
        
        for( int i = idx; i < s.length(); i++)
        {
            retVal = retVal * 10 + ( s[ idx ] - '0' );
        }
        
        if( s[0] == '-' )
            retVal = -retVal;
        
        return retVal;
    }

    int evalRPN(vector<string>& tokens)
    {
        if( tokens.size() == 0 )
        {
            return 0;
        }
        
        stack<int> stk;
        
        for( unsigned int i = 0; i < tokens.size(); i++ )
        {
			cout << " tokens[" << i << "] = " << tokens[i] << endl;


			cout << " isDigit = " << isDigit( tokens[i] ) << endl;

            // Current token is an integer value, push it onto the stack.
            if( isDigit( tokens[ i ] ) )
            {
                stk.push( convertStrToInt( tokens[ i ] ) );
            }
            else
            {
				int one, two;

                if( !stk.empty() )
                {
                    two = stk.top();
                    stk.pop();
                }
                else
                {
                    return -1;
                }

                if( !stk.empty() )
                {
                    one = stk.top();
                    stk.pop();
                }
                else
                {
                    return -1;
                }
                
                switch( tokens[ i ][0] )
                {
                    case '+':
                        stk.push( one + two );
                        break;
                        
                    case '-':
                        stk.push( one - two );
                        break;
                        
                    case '*':
                        stk.push( one * two );
                        break;
                        
                    case '/':
                        stk.push( one/two );
                        break;
                }
            }
        }
        return stk.top();
    }
};

int main()
{
	Solution s;

	vector<string> tokens;
	tokens.clear();

	tokens.push_back( "-78" );
	tokens.push_back( "-33" );
	tokens.push_back( "196" );
	tokens.push_back( "+" );
	tokens.push_back( "-19" );
	tokens.push_back( "-" );
	tokens.push_back( "115" );
	tokens.push_back( "+" );
	tokens.push_back( "-" );
	
	cout << "Result is " << s.evalRPN( tokens ) << "." << endl;

	return 0;
}
