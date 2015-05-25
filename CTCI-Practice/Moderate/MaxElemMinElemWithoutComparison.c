# include <stdio.h>

int FindMaxElem( int a, int b )
{
	return a - ( (a - b) & ( (a - b) >> ( sizeof(int) * 8 - 1 ) ) );
}

int FindMinElem( int a, int b )
{
	return b + ( (a - b) & ( (a - b) >> ( sizeof(int) * 8 - 1 ) ) );
}

int main()
{
	int a = 10;
	int b = -2;

	int maxElem = FindMaxElem( a, b );
	int minElem = FindMinElem( a, b );

	printf("\n Max Elem: %d. Min Elem: %d. \n", maxElem, minElem );

	return 0;
}
