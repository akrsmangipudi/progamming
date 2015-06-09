int FindCrossMax( int *arr, int low, int mid, int high )
{
    int leftSum  = INT_MIN;
    int rightSum = INT_MIN;
    int currSum  = 0;
    
    int i = 0;
    for( i = mid; i >= low; i-- )
    {
        currSum += arr[ i ];
        
        if( leftSum < currSum )
            leftSum = currSum;
    }
    
    currSum = 0;
    
    for( i = mid + 1; i <= high; i++ )
    {
        currSum += arr[ i ];
        
        if( rightSum < currSum )
            rightSum = currSum;

    }   
    return leftSum + rightSum;
}

int FindMaxSumInSubArray( int* arr, int low, int high )
{
    if( low == high )
    {
        return arr[ low ];
    }
    
    int mid = ( low + high )/2;
    int leftMax  = FindMaxSumInSubArray( arr, low, mid  );
    int rightMax = FindMaxSumInSubArray( arr, mid + 1, high );
    int crossMax = FindCrossMax( arr, low, mid, high );
    
    if( ( leftMax >= crossMax ) && ( leftMax >= rightMax ) )
    {
        return leftMax;
    }
    else if( ( rightMax >= crossMax ) && ( rightMax >= leftMax ) )
    {
        return rightMax;
    }
    else
    {
        return crossMax;
    }
}

int maxSubArray(int* nums, int numsSize)
{
    return FindMaxSumInSubArray( nums, 0, numsSize - 1 );
}
