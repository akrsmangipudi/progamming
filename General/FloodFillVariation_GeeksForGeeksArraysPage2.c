# include <stdio.h>
# include <stdlib.h>

int Recurse( char arr[][6], int rows, int cols, int i_row, int j_col )
{

	if( i_row == 0 || j_col == 0 || i_row == ( rows - 1 ) || j_col == ( cols - 1 ) )
	{
		if( arr[ i_row ][ j_col ] == '0' )
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}

	if( i_row < 0 || j_col < 0 || i_row > ( rows - 1 ) || j_col > ( cols - 1 ) )
	{
		return -1;
	}

	if( arr[ i_row ][ j_col ] != '0' )
	{
		return 1;
	}

	arr[ i_row ][ j_col ] = '-';

	if( -1 == Recurse( arr, rows, cols, i_row, j_col - 1 ) )
	{
		arr[ i_row ][ j_col ] = '0';
		return -1;
	}

	if( -1 == Recurse( arr, rows, cols, i_row, j_col + 1 ) )
	{
		arr[ i_row ][ j_col ] = '0';
		return -1;
	}

	if( -1 == Recurse( arr, rows, cols, i_row - 1, j_col ) )
	{
		arr[ i_row ][ j_col ] = '0';
		return -1;
	}

	if( -1 == Recurse( arr, rows, cols, i_row + 1, j_col ) )
	{
		arr[ i_row ][ j_col ] = '0';
		return -1;
	}

	return 1;
}

int main()
{
	unsigned int M = 6, N = 6;

#if 0
	char arr[5][4] = {{'X', 'X', 'X', 'X'},
                       {'X', '0', 'X', 'X'},
                       {'X', '0', '0', 'X'},
                       {'X', '0', 'X', 'X'},
                       {'X', 'X', '0', '0'},
                      };
#endif

	char arr[][6] =  {{'X', '0', 'X', '0', 'X', 'X'},
                     {'X', '0', 'X', 'X', '0', 'X'},
                     {'X', 'X', 'X', '0', 'X', 'X'},
                     {'0', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', '0', 'X', '0'},
                     {'0', '0', 'X', '0', '0', '0'},
                    };

#if 0
	char arr[ 6 ][ 6 ] = {  {'X', '0', 'X', 'X', 'X', 'X'},
                        {'X', '0', 'X', 'X', '0', 'X'},
                        {'X', 'X', 'X', '0', '0', 'X'},
                        {'0', 'X', 'X', 'X', 'X', 'X'},
                        {'X', 'X', 'X', '0', 'X', '0'},
                        {'0', '0', 'X', '0', '0', '0'},
                    };
#endif

	int i = 0, j = 0;
	for( i = 0; i < M; i++ )
	{
		for( j = 0; j < N; j++ )
		{
			if( arr[ i ][ j ] == 'X' )
			{
				continue;
			}
			int retVal = Recurse( arr, M, N, i, j );
		}
	}

#if 0	
	for( i = 0; i < 6; i++ )
	{
		for( j = 0; j < 6; j++ )
		{
			if( arr[ i ][ j ] == '-' )
			{
				arr[ i ][ j ] = 'X';
			}
		}
	}
#endif
	
	for( i = 0; i < M; i++ )
	{
		printf("\n");
		for( j = 0; j < N; j++ )
		{
			printf("\t %c", arr[ i ][ j ] );
		}
		printf("\n");
	}
}
