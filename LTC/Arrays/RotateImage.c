# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void rotate(int **matrix, int n) 
{
    unsigned int level = 0;
    for( level = 0; level < n/2; level++ )
    {
        unsigned int first = level;
        unsigned int last  = n - 1 - level;
        unsigned int layer;
        for( layer = first; layer < last; layer++ )
        {
            unsigned int offset = layer - first;
            
            int temp = matrix[ first ][ layer ];
            
            matrix[ first ][ layer ] = matrix[ last - offset ][ first ];
            
            matrix[ last - offset ][ first ]  = matrix[ last ][ last - offset ];
            
            matrix[ last ][ last - offset ]   = matrix [ layer ][ last ];
            
            matrix [ layer ][ last ] = temp;
        }
    }
}

int main()
{
	int **matrix;

	int n = 4;

	matrix = ( int ** )malloc( sizeof( int * ) * 4 );

	int i = 0;
	for( i = 0; i < n; i++ )
	{
		matrix[ i ] = ( int * )malloc( sizeof( int ) * n );
	}

	matrix[0][0] = 1;
	matrix[0][1] = 2; 
	matrix[0][2] = 3;
	matrix[0][3] = 4;
	matrix[1][0] = 5;
	matrix[1][1] = 6;
	matrix[1][2] = 7;
	matrix[1][3] = 8;
	matrix[2][0] = 9;
	matrix[2][1] = 10;
	matrix[2][2] = 11;
	matrix[2][3] = 12;
	matrix[3][0] = 13;
	matrix[3][1] = 14;
	matrix[3][2] = 15;
	matrix[3][3] = 16;
	
	int j = 0;
	printf("\n Before: ");
	for( i = 0; i < n; i++ )
	{
		printf("\n");
		for( j = 0; j < n; j++ )
		{
			printf("\t %d", matrix[ i ][ j ]);
		}
	}
	printf("\n");

	rotate( matrix, n );

	printf("\n After: ");
	for( i = 0; i < n; i++ )
	{
		printf("\n");
		for( j = 0; j < n; j++ )
		{
			printf("\t %d", matrix[ i ][ j ]);
		}
	}
	printf("\n");

	return 0;
}
