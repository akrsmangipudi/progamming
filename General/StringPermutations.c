# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void doPermute(char *src, char *dest, int *used, int length, int level, int k)
{
	int i = 0;
	if(level == k)
	{
		printf("\n %s", dest);
		return;
	}
	else
	{
		for(i = level; i < length; i++)
		{
			if(used[i])
				continue;
			dest[level] = src[i];
			used[i] = 1;
			doPermute(src, dest, used, length, level + 1, k);
			used[i] = 0;
			dest[level] = 0;
			level--;
		}
	}
}

int main()
{
	char *src = "ABCD";
	char *dest = (char *)malloc(sizeof(char)*strlen(src));
	memset(dest, 0, sizeof(char)*strlen(src));
	int *used = (int *)malloc(sizeof(int)*strlen(src));
	memset(used, 0, sizeof(int)*strlen(src));
	doPermute(src, dest, used, strlen(src),0, 2);
}
