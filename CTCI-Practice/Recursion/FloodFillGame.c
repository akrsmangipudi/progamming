# include <stdio.h>

void FillColorStartingAtPosition( int screen[][8], int x_row, int y_col, int targetColor, int colorToReplace )
{
	
	if( x_row < 0 || x_row > 7 || y_col < 0 || y_col > 7 )
	{
		return;
	}

	if( screen[x_row][y_col] != colorToReplace )
		return;

	screen[x_row][y_col] = targetColor;

	//  Go North
	FillColorStartingAtPosition( screen, x_row - 1, y_col, targetColor, colorToReplace );

	//  Go South
	FillColorStartingAtPosition( screen, x_row + 1, y_col, targetColor, colorToReplace );

	//  Go East
	FillColorStartingAtPosition( screen, x_row, y_col + 1, targetColor, colorToReplace );

	//  Go West
	FillColorStartingAtPosition( screen, x_row, y_col - 1, targetColor, colorToReplace );
}

int main()
{
	
	int screen[8][8] = {
			  		    {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1, 0, 1, 1},
                        {1, 2, 2, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 2, 2, 0},
                        {1, 1, 1, 1, 1, 2, 1, 1},
                      	{1, 1, 1, 1, 1, 2, 2, 1}
                      };

	int x = 0, y = 0;

	int targetColor = 3;

	int colorToReplace = screen[x][y];

	if( colorToReplace != targetColor ) 
		FillColorStartingAtPosition( screen, x, y, targetColor, colorToReplace ); 

	int i = 0, j = 0;
	for( i = 0; i < 8; i++ )
	{
		printf("\n");
		for( j = 0; j < 8; j++ )
		{
			printf("\t %d", screen[i][j] );
		}
	}
	printf("\n");

	return 0;
}
