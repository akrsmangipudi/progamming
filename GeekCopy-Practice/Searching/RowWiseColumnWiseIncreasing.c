# include <stdio.h>
# include <stdlib.h>

int ElementFound( int **mat, int rows, int element )
{	
	int retVal = 0;
	// Start from the last element in the first row.
	
	int i = 0, j = rows;
	int currElement = (int)*( ( mat + (i * rows) ) + j );
	printf("\n %d %d \n", currElement);
	
	while(1)
	{
		if( ( j < 0 ) || ( i > ( rows - 1 ) ) )
		{
			break;
		}

		currElement = *( (mat + i * rows) + j);
		printf("\n currElement = %d. \n", currElement );

		if( element == currElement )
		{
			retVal = 1;
			break;
		}

		// Go to the left.
		if( element < currElement )
		{
			j--;
		}
		else // Go down.
		{
			i++;
		}
	}
	return retVal;
}

int main()
{
	int mat[4][4] = { 
                    {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
	
	int element = 20;
	int found = ElementFound( (int **) mat, 4, element );
	printf("\n %d found: %d. \n", element, found);
	return 0;
}
