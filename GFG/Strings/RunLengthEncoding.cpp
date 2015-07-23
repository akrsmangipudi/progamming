# include <iostream>
# include <string>

using namespace std;

string EncodedString( string inputStr )
{
	string output;
	output.clear();

	if( inputStr.length() == 0 )
	{
		return output;
	}

	int i = 0;

	while( i < inputStr.length() )
	{
		int  count    = 1;
		char copyElem = inputStr[ i ]; 
		if( inputStr[ i ] == inputStr[ i + 1 ] )
		{
			while( ( i < inputStr.length() ) && ( inputStr[ i ] == inputStr[ i + 1 ] ) )
			{
				count++;
				i++;
			}
		}
		
		output += copyElem;
		output += to_string( count);
		i++;
	}

	return output;
}

int main()
{
	string input  = "wwwwaaadexxxxxxz";

	cout << " Input String = " << input << "." << endl;

	string output = EncodedString( input ); 

	cout << " Encoded String = " << output << "." << endl;

	return 0;
}
