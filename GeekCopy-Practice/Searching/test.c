# include <stdio.h>

void TestFunction( int arr[][2] )
{
	arr[0][0] = 5;
	arr[0][1] = 6;
	arr[1][0] = 7;
	arr[1][1] = 8;
}

int main()
{
	int arr[2][2] = { {1, 2}, {3, 4} };

	int i = 0, j = 0;

	printf("\n Original Array: \n");
	for( i = 0; i < 2; i++ )
	{
		printf("\n");
		for( j = 0; j < 2; j++ )
		{
			printf("\t %d", arr[i][j] );
		}
	}
	printf("\n");


	TestFunction( arr );

	printf("\n Modified Array: \n");
	for( i = 0; i < 2; i++ )
	{
		printf("\n");
		for( j = 0; j < 2; j++ )
		{
			printf("\t %d", arr[i][j] );
		}
	}
	printf("\n");

	return 0;
}
