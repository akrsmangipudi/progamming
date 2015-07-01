# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void PrintAllInterleavings( char *i1, char *i2, char *o, int ol, int c1, int c2, int co )
{
	if( co == ol - 1 )
	{
		o[ co + 1 ] = '\0';
		printf("\n %s \n", o );		
	}
	else
	{
		unsigned int i = 0;
		for( i = 0; i < 2; i++ )
		{
			if( 0 == i )
			{
				if( i1[ c1 ] == '\0' )
				{
					continue;
				}

				o[ co ] = i1[ c1 ];
				PrintAllInterleavings( i1, i2, o, ol, c1 + 1, c2, co + 1 );		
			}
			else
			{
				if( i2[ c2 ] == '\0' )
				{
					return;
				}
				
				o[ co ] = i2[ c2 ];
				PrintAllInterleavings( i1, i2, o, ol, c1, c2 + 1, co + 1 );		
			}
		}
	}
}

int main()
{
	char *input1 = "ABE";
	char *input2 = "CD";

	char *output = ( char * )malloc( strlen( input1 ) + strlen ( input2 ) + 1 );
	memset( output, 0, strlen( input1 )+ strlen( input2 ) + 1 );

	PrintAllInterleavings( input1, input2, output, strlen( input1 ) + strlen( input2 ) + 1, 0, 0, 0 );

	return 0;
}
