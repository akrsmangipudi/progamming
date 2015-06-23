# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct ListNode
{
	unsigned int vertex;
	struct ListNode *next;
}ListNode;

typedef struct Graph
{
    unsigned int NumOfVertices;
    unsigned int NumOfEdges;
    bool         *visited;
    ListNode     **AdjList;
    ListNode     **TailPtr;
} Graph;

void DoDFSTraversal( Graph *gPtr, unsigned int vertex )
{
	gPtr->visited[ vertex ] = true;

	printf("\n Visited vertex %d. \n", vertex );

	ListNode *temp = gPtr->AdjList[ vertex ]->next;

	while( temp )
	{
		if( !gPtr->visited[ temp->vertex ] )
		{
			DoDFSTraversal( gPtr, temp->vertex );
		}
		temp = temp->next;
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

	gPtr->AdjList  = ( ListNode ** )malloc( sizeof( ListNode * ) * v );
	gPtr->TailPtr = ( ListNode ** )malloc( sizeof( ListNode * ) * v );

	gPtr->visited   = ( bool * )malloc( sizeof( bool ) * v );
    memset( gPtr->visited, 0, sizeof( bool ) * v );

	unsigned int i = 0, j = 0;
	for( i = 0; i < v; i++ )
	{
		gPtr->AdjList[ i ]  = ( ListNode * )malloc( sizeof( ListNode ) );

		if( !gPtr->AdjList[ i ] )
		{
			printf("\n Malloc fail ! ");
			return;
		}
		
		gPtr->TailPtr[ i ] = gPtr->AdjList[ i ];

		gPtr->AdjList[ i ]->vertex = i;
		gPtr->AdjList[ i ]->next   = NULL;
	}
	
	// Read the each edge information and update the List Structure.
    for( i = 0; i < e; i++ )
    {
        // Edge from ( 1 ) to ( 2 ).
        unsigned int one = 0, two = 0;
        scanf("%d %d",  &one, &two );

		ListNode *tempOne = ( ListNode * )malloc( sizeof( ListNode ) );

		if( !tempOne )
		{
			printf("\n Malloc fail ! ");
			return;
		}

		tempOne->vertex = two;
		tempOne->next   = NULL;

		gPtr->TailPtr[ one ]->next = tempOne;
		gPtr->TailPtr[ one ] = tempOne;
		
		ListNode *tempTwo = ( ListNode * )malloc( sizeof( ListNode ) );

		if( !tempTwo )
		{
			printf("\n Malloc fail ! ");
			return;
		}

		tempTwo->vertex = one;
		tempTwo->next   = NULL;

		gPtr->TailPtr[ two ]->next = tempTwo;
		gPtr->TailPtr[ two ] = tempTwo;
    }

	printf("\n Constructed Adjacency List : ");

	for( i = 0; i < v; i++ )
	{
		ListNode *temp = gPtr->AdjList[ i ];

		printf("\n");
		while( temp )
		{
			printf("\t %d", temp->vertex );
			temp = temp->next;
		}
		printf("\n");
	}

	printf("\n");

//	for( i = 0; i < v; i++ )
  //  {
    //    if( false == gPtr->visited[ i ] )
      //  {
            DoDFSTraversal( gPtr, 0 );
       // }
   // }

	return 0;
}
