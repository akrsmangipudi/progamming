# include <stdio.h>

int main()
{
	int a = 10;
	int b = -5;

	printf("\n Before ! a: %d, b: %d \n", a, b );

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("\n After ! a: %d, b: %d \n", a, b );

	return 0;
}
