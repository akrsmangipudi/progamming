# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct Graph
{
	unsigned int NumOfVertices;
	unsigned int NumOfEdges;
	bool         *visited;	
	unsigned int **AdjMatrix;
} Graph;

void DoDFSTraversal( Graph *gPtr, unsigned int vertex )
{
	gPtr->visited[ vertex ] = true;

	printf("\n Visited vertex %d. \n", vertex + 1 );

	unsigned int i = 0;
	for( i = 0; i < gPtr->NumOfVertices; i++ )
	{
		if( !gPtr->visited[ i ] && ( 1 == gPtr->AdjMatrix[ vertex ][ i ] ) )
		{
			DoDFSTraversal( gPtr, i );
		}
	}	
}

int main()
{
	unsigned int v = 0, e = 0;

	scanf("%d %d", &v, &e );

	if( v == 0 || e == 0 )
	{
		return;
	}

	Graph *gPtr = ( Graph * )malloc( sizeof( Graph ) );

	if( !gPtr )
	{
		printf("\n Malloc fail ! \n");
		return;
	}

	gPtr->NumOfVertices = v;
	gPtr->NumOfEdges    = e;

	gPtr->AdjMatrix = ( unsigned int ** )malloc( sizeof( unsigned int * ) * v );

	gPtr->visited   = ( bool * )malloc( sizeof( bool ) * v );
	memset( gPtr->visited, 0, sizeof( bool ) * v );

	unsigned int i = 0, j = 0;
	for( i = 0; i < v; i++ )
	{
		gPtr->AdjMatrix[ i ] = ( unsigned int * )malloc( sizeof( unsigned int ) * v );
		memset( gPtr->AdjMatrix[ i ], 0, sizeof( unsigned int ) * v );
	}

	// Read the each edge information and populate the corresponding matrix.
	for( i = 0; i < e; i++ )
	{
		// Edge from ( 1 ) to ( 2 ).
		unsigned int one = 0, two = 0;
		scanf("%d %d",  &one, &two );

		gPtr->AdjMatrix[ one - 1 ][ two - 1 ] = 1;
		gPtr->AdjMatrix[ two - 1 ][ one - 1 ] = 1;
	}

	printf("\n Construced Adjacency Matrix: ");
	for( i = 0; i < v; i++ )
	{
		printf("\n");
		for( j = 0; j < v; j++ )
		{
			printf(" \t %d ", gPtr->AdjMatrix[ i ][ j ] );
		}
	}
	printf("\n");

//	for( i = 0; i < v; i++ )
//	{
//		if( false == gPtr->visited[ i ] )
//		{
			DoDFSTraversal( gPtr, 0 );
//		}
//	}

	return 0;
}
