# include <iostream>
# include <stdlib.h>

using namespace std;

typedef struct MDL
{
	int size;
	struct MDL* next;
}MDL;

MDL* CreateNode( int size )
{
	MDL *returnNode  = ( MDL * )malloc( sizeof( MDL ) );
	returnNode->size = size;
	returnNode->next = NULL;

	return returnNode;
}

void CopyFromSourceToDest( MDL* source, MDL* dest )
{
	int bytesRemainingFromSrc = source->size;
	int bytesRemainingInDst   = dest->size;

	static int count = 1;

	while( source && dest )
	{
		if( bytesRemainingFromSrc > bytesRemainingInDst )
		{
			bytesRemainingFromSrc -= bytesRemainingInDst;

			cout << count++ << ". Copying " << bytesRemainingInDst << " bytes from source to destination." << endl;

			bytesRemainingInDst = 0;

			dest = dest->next;
			if( dest )
			{
				bytesRemainingInDst = dest->size;
			}
		}
		else if( bytesRemainingFromSrc < bytesRemainingInDst )
		{
			bytesRemainingInDst -= bytesRemainingFromSrc;
			
			cout << count++ << ". Copying " << bytesRemainingFromSrc << " bytes from source to destination." << endl;

			bytesRemainingFromSrc = 0;	

			source = source->next;
			if( source )
			{
				bytesRemainingFromSrc = source->size;
			}
		}
		else
		{
			bytesRemainingInDst   = 0;
			bytesRemainingFromSrc = 0;	
			cout << count++ << ". Copying " << source->size << " bytes from source to destination." << endl;
			
			source = source->next;
			dest   = dest->next;
			if( source )
			{
				bytesRemainingFromSrc = source->size;
			}
			if( dest )
			{
				bytesRemainingInDst   = dest->size;
			}
		}
	}
}

int main()
{
	MDL* source        = CreateNode( 10 );
	source->next       = CreateNode( 3 );
	source->next->next = CreateNode( 15 );

	MDL* dest              = CreateNode( 5 );
	dest->next             = CreateNode( 3 );
	dest->next->next       = CreateNode( 5 );
	dest->next->next->next = CreateNode( 20 );

	CopyFromSourceToDest( source, dest );

	return 0;
}
