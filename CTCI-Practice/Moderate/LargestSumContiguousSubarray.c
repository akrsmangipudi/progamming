# include <stdio.h>

int LargestSubarraySum( int *arr, int low, int high )
{
	int i = 0;
	int max_sum_end  = 0;
	int max_sum_here = 0;

	for( i = low; i <= high; i++ )
	{
		max_sum_here = max_sum_here + arr[i];

		if( max_sum_here < 0 )
			max_sum_here = 0;

		if( max_sum_end < max_sum_here )
			max_sum_end = max_sum_here;
	}
	return max_sum_end;
}

int main()
{
//	int arr[] = { -2, -3, 4, -1, -2, 6, -5, -3 };

	int arr[] = { 2, 1, -3, 4, -1, 2, 1, -5, 4 };

	int maxSum = LargestSubarraySum( arr, 0, ( sizeof(arr)/sizeof(arr[0]) - 1 ) );

	printf("\n Maximum contiguous subarray sum: %d. \n", maxSum );

	return 0;
}
