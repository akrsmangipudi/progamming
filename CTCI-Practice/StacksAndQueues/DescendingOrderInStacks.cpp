# include <iostream>
# include <stack>

using namespace std;

void DescendingOrder( stack<int> &source )
{
	stack<int> aux;

	while( !source.empty() )
	{
		// Aux stack is empty, insert the first element into it.
		if( aux.empty() )
		{
			aux.push( source.top() );
			source.pop();
		}
		else
		{
			int temp = source.top();
			source.pop();

			while( !aux.empty() && ( aux.top() > temp )  )
			{
				source.push( aux.top() );
				aux.pop();
			}

			aux.push( temp );
		}
	}
	swap( source, aux );
}

int main()
{
	stack<int> source;

	source.push( 8 );
	source.push( 12 );
	source.push( 5 );
	source.push( 7 );
	source.push( 10 );
	source.push( 1 );
	source.push( 3 );

	DescendingOrder( source );

	cout << endl;
	while( !source.empty() )
	{
		cout << " " << source.top();
		source.pop();
	}
	cout << endl;

	return 0;
}
