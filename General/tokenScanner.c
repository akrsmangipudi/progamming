# include <stdio.h>
# include <stdlib.h>
# include <string.h>


void reverseWordsInString(char *srcString)
{
	int tokenScanIdx = strlen(srcString) - 1;
	int wordEnd = 0, wordStart = 0, writePos = 0;
	char *buffer = (char *)malloc(sizeof(char)*(strlen(srcString)+1));
	if(!buffer)
		return;
	memset(buffer, 0, sizeof(char)*(strlen(srcString)+1));

	while(tokenScanIdx >= 0)
	{
		if(srcString[tokenScanIdx] == ' ')
		{
			buffer[writePos++] = srcString[tokenScanIdx--];
		}
		else
		{
			wordEnd = tokenScanIdx;
			while(tokenScanIdx != ' ' && tokenScanIdx >= 0)
				tokenScanIdx--;
			wordStart = tokenScanIdx + 1;
			while(wordStart <= wordEnd)
			{
				buffer[writePos++] = srcString[wordStart++];
			}
		}
	}
	buffer[writePos] = '\0';
	printf("\n %s \n", buffer);
	free(buffer);
}


int main()
{
	char srcString[] = "Hello Aditya. Welcome to India.";
	reverseWordsInString(srcString);
}
