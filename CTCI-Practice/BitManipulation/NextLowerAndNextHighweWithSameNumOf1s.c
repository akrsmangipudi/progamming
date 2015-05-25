# include <stdio.h>

unsigned int GetNextHighest( int inputNum )
{
	int pivotIdx = -1;
	int i = 0;
	int flag = 0;

	for( i = 0; i < sizeof(int) * 8; i++ )
	{
		if( ( inputNum & ( 1 << i ) )  > 0 )
		{
			// Indicates we encountered at least one '1' in the process.
			flag = 1;
		}
		else
		{
			if( flag == 1 )
			{
				pivotIdx = i;
				break;
			}
		}
	}

	if( -1 == pivotIdx )
		return inputNum;

	// Get the mask and set the pivotIdx position element to 1.
	unsigned int mask = 1 << pivotIdx;
	inputNum = inputNum | mask;
	
	int CountNumOf0s = 0;
	int CountNumOf1s = 0;

	for( i = 0; i < pivotIdx; i++ )
	{
		if( ( inputNum & ( 1 << i ) ) == 0 )
		{
			CountNumOf0s += 1;
		}
		else
		{
			CountNumOf1s += 1;
		}
	}

	CountNumOf1s--;
	CountNumOf0s++;

	// Set all the elements after the pivotIdx to 0s.	
	mask = ~( ( 1 << pivotIdx ) - 1 );
	inputNum = inputNum & mask;
	
	mask = ( 1 << CountNumOf1s ) - 1;
	inputNum = inputNum | mask;

	printf("\n Next Highest Number is %d. \n", inputNum );
	return inputNum;
}

unsigned int GetNextLowest( int inputNum )
{
	int pivotIdx = -1;
	int i = 0;
	int flag = 0;

	for( i = 0; i < sizeof(int) * 8; i++ )
	{
		if( ( inputNum & ( 1 << i ) )  == 0 )
		{
			// Indicates we encountered at least one '0' in the process.
			flag = 1;
		}
		else
		{
			if( flag == 1 )
			{
				pivotIdx = i;
				break;
			}
		}
	}

	if( -1 == pivotIdx )
		return inputNum;

	// Get the mask and set the pivotIdx position element to 0.
	unsigned int mask = ~( 1 << pivotIdx );
	inputNum = inputNum & mask;
	
	int CountNumOf0s = 0;
	int CountNumOf1s = 0;

	for( i = 0; i < pivotIdx; i++ )
	{
		if( ( inputNum & ( 1 << i ) ) == 0 )
		{
			CountNumOf0s += 1;
		}
		else
		{
			CountNumOf1s += 1;
		}
	}

	CountNumOf0s--;
	CountNumOf1s++;

	// Set all the elements after the pivotIdx to 1s.	
	mask = ( ( 1 << pivotIdx ) - 1 );
	inputNum = inputNum | mask;
	

	mask = ~( ( 1 << CountNumOf0s ) - 1 );
	inputNum = inputNum & mask;

	printf("\n Next Lowest Number is %d. \n", inputNum );
	return inputNum;
}

int main()
{
	unsigned int inputNum = 1024;

	printf("\n Input Number: ");
	int i = 0;
	for( i = ( sizeof(unsigned int) * 8 - 1 ) ; i >= 0 ; i-- )
	{
		printf("%d ", ( inputNum >> i ) & 1 );
	}
	printf("\n");

	unsigned int nextHigher = GetNextHighest( inputNum );
	unsigned int nextLower  = GetNextLowest ( inputNum );

	printf("\n Next Higher Number: ");
	for( i = ( sizeof(unsigned int) * 8 - 1 ) ; i >= 0 ; i-- )
	{
		printf("%d ", ( nextHigher >> i ) & 1 );
	}
	printf("\n");

	printf("\n Next Lower Number: ");
	for( i = ( sizeof(unsigned int) * 8 - 1 ) ; i >= 0 ; i-- )
	{
		printf("%d ", ( nextLower >> i ) & 1 );
	}
	printf("\n");

	return 0;
}
