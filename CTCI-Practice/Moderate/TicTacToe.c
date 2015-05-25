# include <stdio.h>
# include <stdbool.h>

bool CheckForWinner( char arr[][4], int rows, char *c )
{
	// Check for row winners first.
	int i_row = 0, j_col = 0;
	for( i_row = 0; i_row < rows; i_row++ )
	{
		if( arr[i_row][j_col] == ' ' )
		{
			continue;
		}

		for( j_col = 0; j_col < ( rows - 1) ; j_col++ )
		{
			// We have no winner along the current row.
			if( arr[i_row][j_col] != arr[i_row][j_col + 1] )
			{
				break;
			}

			if( j_col == rows - 2 )
			{
				*c = arr[ i_row ][ j_col ];
				return true;
			}
		}	
	}

	// Check for column winners.
	i_row = 0, j_col = 0;
	for( j_col = 0; j_col < rows; j_col++ )
	{
		if( arr[i_row][j_col] == ' ' )
		{
			continue;
		}

		for( i_row = 0; i_row < (rows - 1) ; i_row++ )
		{
			if( arr[i_row][j_col] != arr[i_row + 1][j_col] )
			{
				break;
			}

			if( i_row == rows - 2 )
			{
				*c = arr[ i_row ][ j_col ];
				return true;
			}
		}
	}

	// Check for top-left to bottom-right diagnal.
	i_row = 0, j_col = 0;
	if( arr[i_row][j_col] != ' ' )
	{
		while( i_row < (rows - 1) )
		{
			if( arr[i_row][i_row] != arr[i_row + 1][i_row + 1] )
			{
				break;
			}

			i_row++;
			
			if( i_row == rows - 1 )
			{
				*c = arr[i_row][i_row];
				return true;
			}				
		}
	}

	// Check for top-right to bottom-left diagnal.
	i_row = 0, j_col = rows - 1;
	if( arr[i_row][j_col] != ' ' )
	{
		while( i_row < (rows - 1) && j_col > 0 )
		{
			if( arr[i_row][j_col] != arr[++i_row][--j_col] )
			{
				break;
			}
			
			if( i_row == rows - 1 )
			{
				*c = arr[i_row][j_col];
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int rows = 4, columns = 4;

	char arr[4][4] = {
						{'x', 'x', 'o', 'o'},
						{'x', 'x', 'o', 'o'},
						{'o', 'o', 'x', 'x'},
						{'o', 'o', 'o', 'x'}
					};
	
	char c;
	bool result = CheckForWinner( arr, rows, &c );

	if( result )
	{
		printf("\n Winner is %c. \n", c );
	}
	else
	{
		printf("\n No Winner. \n");
	}
	
	return 0;
}
