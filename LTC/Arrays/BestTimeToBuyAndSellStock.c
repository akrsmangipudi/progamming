# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

int FindCrossMax( int *diffArray, int low, int mid, int high )
{
    int leftSum  = INT_MIN;
    int rightSum = INT_MIN;
    int currSum  = 0;
    
    int i = 0;
    for( i = mid; i >= low; i-- )
    {
        currSum += diffArray[ i ];
        
        if( leftSum < currSum )
        {
            leftSum = currSum;
        }
    }
    
    currSum = 0;
    
    for( i = mid + 1; i <= high; i++ )
    {
        currSum += diffArray[ i ];
        
        if( rightSum < currSum )
        {
            rightSum = currSum;
        }
    }
    
    return leftSum + rightSum;
}

int FindMaxSumInSubArray( int *diffArray, int low, int high )
{
	printf("\n low: %d, high: %d mid: %d \n", low, high, (low+high)/2 );

    if( low == high )
    {
       return diffArray[ low ]; 
    }
    
    int mid = ( low + high )/2;
    int leftMax  = FindMaxSumInSubArray( diffArray, low, mid );
    int rightMax = FindMaxSumInSubArray( diffArray, mid + 1, high );

    int crossMax = FindCrossMax( diffArray, low, mid, high );

    if( ( leftMax >= rightMax ) && ( leftMax >= crossMax ) )
    {
        return leftMax;
    }
    else if( ( rightMax >= leftMax ) && ( rightMax >= crossMax ) ) 
    {
        return rightMax;
    }
    else
    {
        return crossMax;
    }
}

int maxProfit(int* prices, int pricesSize)
{
    if( pricesSize < 2 )
    {
        return 0;
    }
    
    int diff[ pricesSize - 1 ];
    memset( diff, 0, pricesSize - 1 );
    
    int i = 0;
    for( i = 1; i < pricesSize; i++ )
    {
        diff[ i - 1 ] = prices[ i ] - prices[ i - 1 ];
    }

	for( i = 0; i < pricesSize - 1; i++ )
	{
		printf("\n diff[ %d ] = %d", i, diff[ i ] );
	}
    
    int retVal = FindMaxSumInSubArray( diff, 0, pricesSize - 2 );
    
    if( retVal < 0 )
    {
        return 0;
    }
    
    return retVal;
}

int main()
{
	int *prices = ( int * )malloc( sizeof( int ) * 6 );
	memset( prices, 0, sizeof( int ) * 6 );

	prices[ 0 ] = 3;
	prices[ 1 ] = 2;
	prices[ 2 ] = 6;
	prices[ 3 ] = 5;
	prices[ 4 ] = 0;
	prices[ 5 ] = 3;


	printf(" \n %d \n", maxProfit( prices, 6 ) );

	return 0;
}
