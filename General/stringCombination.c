# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void append(char *destPtr, char c)
{
	while(*destPtr != '\0')
		destPtr++;
	*(destPtr) = c;
	return;
}

void doCombination(char *srcPtr, char *destPtr, int length, int start)
{
	int i = 0;
	for(i = start; i < length; i++)
	{
		append(destPtr, srcPtr[i]);
		printf("\n %s", destPtr);
		doCombination(srcPtr, destPtr, length, i+1);
		destPtr[strlen(destPtr)-1] = '\0';
	}
}

int main()
{
	char *src = "ABCD";
	char *dest = (char *)malloc(sizeof(char)*strlen(src));
	doCombination(src, dest, strlen(src), 0);
}
