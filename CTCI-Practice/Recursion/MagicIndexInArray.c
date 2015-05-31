# include <stdio.h>
# include <math.h>
# include <stdlib.h>

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

int CheckIfMagicNumExists( int *arr, int low, int high )
{
	if( low <= high )
	{
		int mid = (low + high)/2;
		printf("\n mid = %d, arr[mid] = %d \n", mid, arr[mid] );

		if( mid == arr[mid] )
			return 1;

		if( mid < arr[mid] )
		{
			return CheckIfMagicNumExists( arr, low, mid - 1 );
		}
		else
		{
			return CheckIfMagicNumExists( arr, mid + 1, high );
		}
	}
	return -1;
}

int CheckIfMagicNumExistsInDupElementsArray( int *arr, int low, int high )
{
	if( low <= high )
	{
		int mid = (low + high)/2;

		if( arr[mid] == mid )
			return 1;

		int left  = CheckIfMagicNumExistsInDupElementsArray( arr, low, min( arr[mid], mid - 1 ) ) ;

		if( left != -1 )
			return left;
		
		int right = CheckIfMagicNumExistsInDupElementsArray( arr, max( arr[mid], mid + 1 ), high );
		
		if( right != -1 )
			return right;

	}
	return -1;
}

int main()
{
	//int arr[] = { -40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13 };
	int arr[] = { -40, -20, -1, 1, 2, 3, 5, 8, 9, 12, 13 };

	printf("\n Magic number is present in the array : %d. \n", CheckIfMagicNumExists( arr, 0, sizeof(arr)/sizeof(arr[0]) - 1 ) ); 

	int arr1[] = { -10, -5, -3, -2, -1, 3, 4, 7, 9, 12, 13 };
	
	int arr2[] = { -10, -5, 1, 2, 2, 8, 8, 8, 9, 12, 13 };
	
	printf("\n Magic number is present in the array : %d. \n", CheckIfMagicNumExistsInDupElementsArray( arr1, 0, sizeof(arr)/sizeof(arr[0]) - 1 ) ); 
	
	printf("\n Magic number is present in the array : %d. \n", CheckIfMagicNumExistsInDupElementsArray( arr2, 0, sizeof(arr)/sizeof(arr[0]) - 1 ) ); 

	return 0;
}
