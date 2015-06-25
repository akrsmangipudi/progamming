# include <stdio.h>
# include <string.h>

void RemoveCharAndPattern( char *input )
{
	if( strlen( input ) == 0 )
	{
		return;
	}

	unsigned int src = 0, dst = 0;

	for( src = 0; src < strlen( input ); src++ )
	{
		if( input[ src ] == 'b' )
		{
			continue;
		}

		if( input[ src ] == 'a' )
		{
			if( ( src < ( strlen( input ) - 1 ) ) && ( input[ src + 1 ] == 'c' ) )
			{
				src++;
			}
			else
			{
				input[ dst++ ] = input[ src ];
			}
		}
		else
		{
			input[ dst++ ] = input[ src ];
		}
	}

	input[ dst ] = '\0';
}

int main()
{
//	char inputStr[] = "acbac";
//	char inputStr[] = "aaaca";
//	char inputStr[] = "ababac";
//	char inputStr[] = "bbbbd";
	char inputStr[] ="acbdacacbacbeac";


	printf("\n Original string: %s \n", inputStr );

	RemoveCharAndPattern( inputStr );
	
	printf("\n Modified string: %s \n", inputStr );

	return 0;
}
