# include <iostream>

using namespace std;

int MaxDepthOfNestedParanthesis( string input )
{
	unsigned int openCount = 0, closeCount = 0, maxCount = 0;

	unsigned int i = 0;	
	while( i < input.length() )
	{
		if( input[i] == '(' )
		{
			openCount++;
			if( maxCount < ( openCount - closeCount ) )
			{
				maxCount = openCount - closeCount;
			}
		}
		else if( input[i] == ')' )
		{
			closeCount++;
			if( closeCount > openCount )
			{
				break;
			}			
		}
		i++;
	}

	if( openCount == closeCount )
	{
		return maxCount;
	}
	else
	{
		return -1;
	}
}

int main()
{
	cout << " Max depth of nested paranthesis is : " << MaxDepthOfNestedParanthesis( "( a(b) (c) (d(e(f)g)h) I (j(k)l)m)" ) << endl;
	cout << " Max depth of nested paranthesis is : " << MaxDepthOfNestedParanthesis( "( p((q)) ((s)t) )" ) << endl;
	cout << " Max depth of nested paranthesis is : " << MaxDepthOfNestedParanthesis( "" ) << endl;
	cout << " Max depth of nested paranthesis is : " << MaxDepthOfNestedParanthesis( "b) (c) ()" ) << endl;
	cout << " Max depth of nested paranthesis is : " << MaxDepthOfNestedParanthesis( "(b) ((c) ()" ) << endl;
	cout << " Max depth of nested paranthesis is : " << MaxDepthOfNestedParanthesis( " ( ((X)) (((Y))) ) " ) << endl;
	return 0;
}
