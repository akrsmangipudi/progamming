#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>

using namespace std;

unsigned int EvaluateExpression( unsigned int val1, unsigned int val2, char op)
{
    switch(op)
    {
        case '+':
            return val1 + val2;
        case '*':
            return val1 * val2;
        case '-':
            return val2 - val1;        
        case '/':
            return val2 / val1;           
    }
}

int main()
{
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
string input = "";
getline(cin, input);

cout << "Input str: " << input << input.size() << endl;

stack<unsigned int> stk;
    
for( string::iterator it = input.begin(); it != input.end(); )
{
    if( *it == ' ')
    {
		++it;
        continue; 
    }
    
    if( isdigit(*it) )
    {
		unsigned int pushInt = *it - '0';
		while( isdigit( *(it + 1) ) )
        {
          pushInt = pushInt * 10 + isdigit( *(it + 1) );
		  ++it;
        }

		cout << "Pushing operand" << pushInt << endl;
        stk.push(pushInt);
		++it;
    }
    else if( *it == '+' || *it == '-' || *it == '/' || *it == '*')  // It is an operator.
    {
        unsigned int val_1 = stk.top();
        stk.pop();
        unsigned int val_2 = stk.top();
        stk.pop();        
        unsigned int retVal = EvaluateExpression( val_1, val_2, *it );
        stk.push( retVal );
		++it;
    }
	else
	{
		++it;
		continue;
	}
}
    
if( !stk.empty() )
{
    cout << stk.top() << endl;
    stk.pop();
}
    
return 0;
}
