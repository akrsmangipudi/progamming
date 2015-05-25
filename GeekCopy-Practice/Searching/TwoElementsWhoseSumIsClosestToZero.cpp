# include <iostream>
# include <algorithm>
# include <stdio.h>

using namespace std;

void PrintElementsCloseToZero( int arr[], int low, int high )
{
	if( low >= high )
		return;

	int l_low = low, l_high = high;
	int minSum = arr[ l_low ] + arr[ l_high ];
	
	while( low < high )
	{
		int currSum = arr[ low ] + arr[ high ];

		if( currSum == 0 )
		{
			l_low  = low;
			l_high = high;
			break;
		}

		if( abs(minSum) > abs(currSum) )
		{
			minSum = currSum;
			l_low  =  low;
			l_high = high;
		}

		if( currSum > 0 )
		{
			high--;
		}
		else
		{
			low++;
		}
	}

	cout << " Closest Combo: " << arr[l_low]  << " and " << arr[l_high] << endl;
}

int main()
{
	int arr[] = { -90, -85, -78, -32, 11, 14, 32, 79, 87 };	
//	int arr[] = {1, 60, -10, 70, -80, 85};
	sort( arr, arr + (sizeof(arr)/sizeof(arr[0]) - 1) );
	PrintElementsCloseToZero( arr, 0, ( sizeof(arr)/sizeof(arr[0]) ) - 1 );
}
