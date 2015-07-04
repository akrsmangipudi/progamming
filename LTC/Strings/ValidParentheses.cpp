class Solution {
public:
    bool isValid(string s)
    {
        if( s.length() == 0 )
        {
            return true;
        }
        
        stack<char> stk;
        
        unsigned int i = 0;
        
        while( i < s.length() )
        {
            if( s[i] == '(' || s[i] == '{' || s[i] == '[' )
            {
                stk.push( s[i] );
            }
            else
            {
                if( s[i] == ')' )
                {
                    if( !stk.empty() )
                    {
                        if( stk.top() == '(' )
                        {
                            stk.pop();
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                    
                }
                else if( s[i] == '}' )
                {
                    if( !stk.empty() )
                    {
                        if( stk.top() == '{' )
                        {
                            stk.pop();
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if( !stk.empty() )
                    {
                        if( stk.top() == '[' )
                        {
                            stk.pop();
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            i++;
        }
        if( stk.empty() )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
