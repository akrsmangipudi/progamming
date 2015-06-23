# include <iostream>
# include <map>
# include <cstring>

using namespace std;

unsigned int NumOfCustomersWithoutComputers( unsigned int numOfComputers, string arrivalSequence )
{
	unsigned int retVal = 0;

	map< char, pair< unsigned int, bool > > hashMap;

	for( int i = 0; i < arrivalSequence.length(); i++ )
	{
		// 1st occurence of the person.
		if( hashMap.find( arrivalSequence[ i ] ) == hashMap.end() )
		{
			if( numOfComputers > 0 )
			{
				hashMap[ arrivalSequence[ i ] ] = make_pair( 1, true );
				numOfComputers--;
			}
			else
			{
				hashMap[ arrivalSequence[ i ] ] = make_pair( 1, false );
				retVal++;
			}
		} 
		else // person is already in our system, the bool pair value of the hash signifies if this user is holding a system or not.
		{
			pair<int, bool> t = hashMap[ arrivalSequence[ i ] ];

			// User was holding a computer resource, once the user leaves, increase the 'numOfComputers' count.
			if( true == t.second )
			{
				numOfComputers++;				
			}
			hashMap.erase( arrivalSequence[ i ] );
		}
	}
	return retVal;
}

int main()
{
	cout << " Number of customers without access to computer is " << NumOfCustomersWithoutComputers( 2, "ABBAJJKZKZ") << "." << endl;
	cout << " Number of customers without access to computer is " << NumOfCustomersWithoutComputers( 3, "GACCBDDBAGEE") << "." << endl;
	cout << " Number of customers without access to computer is " << NumOfCustomersWithoutComputers( 3, "GACCBGDDBAEE") << "." << endl;
	cout << " Number of customers without access to computer is " << NumOfCustomersWithoutComputers( 1, "ABCBCA") << "." << endl;
	cout << " Number of customers without access to computer is " << NumOfCustomersWithoutComputers( 1, "ABCBCADEED") << "." << endl;

	return 0;
}

