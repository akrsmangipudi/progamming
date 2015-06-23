# include <iostream>

using namespace std;

typedef enum Direction
{
	North = 0,
	East,
	South,
	West
} Direction;

void UpdateCoordinates( unsigned int &x_coordinate, unsigned int &y_coordinate, Direction d )
{
	switch( d )
	{
		case North:
			 y_coordinate = y_coordinate + 1;
			 return;

		case South:
			 y_coordinate = y_coordinate - 1;
			 return;

		case West:
			 x_coordinate = x_coordinate - 1;
			 return;

		case East:
			 x_coordinate = x_coordinate + 1;
			 return;

		default:
			 cout << " No update in the coordinates. Incorrect direction is referenced. " << endl;
			 return;
	}
}

void FindNewDirection( char inputDir, Direction &d )
{
	if( 'L' == inputDir )
	{
		switch( d )
		{
			case North:
				 d = West;
				 return;

			case South:
				 d = East;
				 return;

			case West:
				 d = South;
				 return;

			case East:
                 d = North;
				 return;

			default:
                 cout << "No update in direction. Incorrect direction is referenced. " << endl;
				 return;
		}
	}
	else
	{
		switch( d )
		{
			case North:
                 d = East;
				 return;

			case South:
                 d = West;
				 return;

			case West:
                 d = North;
				 return;
  
			case East:
                 d = South;
				 return;

			default:
                 cout << "No update in direction. Incorrect direction is referenced. " << endl;
				 return;
		}
	}
}

bool FindIfMovesAreCircular( char *robotMoves )
{
	bool retVal = true;

	if( *robotMoves == '\0' )
	{
		return retVal;
	}

	unsigned int x_coordinate = 0, y_coordinate = 0;

	Direction d = North;

	while( *robotMoves != '\0' )
	{
		if( *robotMoves == 'G' )
		{
			UpdateCoordinates( x_coordinate, y_coordinate, d );
		}
		else if( *robotMoves == 'L' || *robotMoves == 'R' )
		{
			FindNewDirection( *robotMoves, d );
		}
		else
		{
			cout << "Incorrect input string. Returning false." << endl;
			return false;
		}
		robotMoves++;
	}

	if( ( 0 != x_coordinate ) || ( 0 != y_coordinate ) )
	{
		retVal = false;
	}

	return retVal;
}

int main()
{
	char robotMoves[] = "LRRLLRRLRLRLRLLRLLLLRRLRLRGLLG";

	cout << "Are robot moves circular ? " << FindIfMovesAreCircular( robotMoves ) << endl;

	return 0;
}
