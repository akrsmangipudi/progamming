# include <stdio.h>
# include <stdlib.h>

void SetPattern( unsigned int *number,
                 unsigned int start,
				 unsigned int end,
				 unsigned int pattern)
{
	unsigned int maskLength = end - start + 1;	

	unsigned int inputMask = ~( ( (1 << maskLength ) - 1 ) << start );

	pattern = pattern << start;
	
//	int l_startIdx = start;
//	int l_endIdx = end;

//	while( l_startIdx )
//	{
//		inputMask = inputMask << 1;
//		l_startIdx--;
//	}

#if 0	
	printf("\n Input mask: %d %d \t", maskLength, inputMask);
	int i = 0;
	for( i = ( sizeof(inputMask) * 8 - 1 ); i >= 0; i--)
	{
		printf("%d", ( inputMask >> i ) & 1 );
	}
	printf("\n");
#endif

	// Flip the bits in the inputMask.
//	inputMask = ~inputMask;
	
	// Sets the bits at positions 'i' through 'j' to 0.
	(*number) = (*number) & inputMask;

#if 0
	printf("\n After Setting 0 bits at desired positions in Number: ");
	for( i = ( sizeof(*number) * 8 - 1 ); i >= 0; i--)
	{
		printf("%d", ( (*number) >> i ) & 1 );
	}
	printf("\n");
#endif
	
//	l_startIdx = start;
//	while( l_startIdx )
//	{
//		pattern = pattern << 1;
//		l_startIdx--;
//	}

	(*number) = (*number) | pattern;
}

int main()
{
	unsigned int number = 0xFFFFFFFF;
	unsigned int patternStart = 2;
	unsigned int patternEnd   = 6;
	unsigned int pattern =     19;

	int i = 0;
	printf("\n Input Number: ");
	for( i = ( sizeof(number) * 8 - 1 ); i >= 0; i--)
	{
		printf("%d", ( number >> i ) & 1 );
	}
	printf("\n");

	SetPattern( &number, patternStart, patternEnd, pattern );
	
	printf("\n Pattern Set Number: ");
	for( i = ( sizeof(number) * 8 - 1 ); i >= 0; i--)
	{
		printf("%d", ( number >> i ) & 1 );
	}
	printf("\n");

	return 0;
}
