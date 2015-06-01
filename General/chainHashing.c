# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define MAX_ROWS 10

struct element
{
	int position;
	int key;
	struct element *nextElem;
};

struct elemRow
{
	int rowIdx;
	struct element *firstElem;
};

void setUpRowPointers(struct elemRow *rowPtr[MAX_ROWS])
{
	int i = 0;
	for(i = 0; i < MAX_ROWS; i++)
	{
		rowPtr[i] = (struct elemRow *)malloc(sizeof(struct elemRow));
		if(!(rowPtr[i]))
		{
			printf("\n Memory allocation issue. Returning. \n");
			return;
		}
		rowPtr[i]->rowIdx = i;
		rowPtr[i]->firstElem = NULL;
	}
}

void insertElementIntoHashTables(struct elemRow *rowPtr[MAX_ROWS], int value)
{
	int hashIdx = value % MAX_ROWS;
	if(!rowPtr[hashIdx])
	{
		printf("Cannnot access the row where element %d needs to be inserted. Returning.\n", value);
		return;
	}

	// If the element is the first element that needs to be inserted.
	if(!rowPtr[hashIdx]->firstElem)
	{
		rowPtr[hashIdx]->firstElem = (struct element *)malloc(sizeof(struct element));
		if(!rowPtr[hashIdx]->firstElem)
		{
			printf("Memory allocation failed for inserting element %d. Returning.", value);
			return;
		}
		rowPtr[hashIdx]->firstElem->key = value;
		rowPtr[hashIdx]->firstElem->position = 1;
		rowPtr[hashIdx]->firstElem->nextElem = NULL;
	}
	// Element already exists in the current row. Get a pointer to the last element and add an element after it.
	else
	{
		struct element *tempPtr = rowPtr[hashIdx]->firstElem;
		while(tempPtr->nextElem != NULL)
			tempPtr = tempPtr->nextElem;
		tempPtr->nextElem = (struct element *)malloc(sizeof(struct element));
		tempPtr->nextElem->position = tempPtr->position + 1;
		tempPtr->nextElem->key = value;
		tempPtr->nextElem->nextElem = NULL;		
	}
}

void deleteKeyFromHashTable(struct elemRow *elemRow[MAX_ROWS], int valToDel)
{
	int hashIdx = valToDel % MAX_ROWS;

	// Row where element should have been stored has no links; return error.	
	if(! elemRow[hashIdx]->firstElem)
	{
		printf("\n Cannot delete %d, as the row where this element should have been stored if it is in the hash table is empty.", valToDel);
		return;
	}
	else
	{
		struct element *searchPtr = elemRow[hashIdx]->firstElem;
		struct element *delPtr= NULL;

		// Element to delete is the first element in the hash list.
		if(searchPtr->key == valToDel)
		{
			elemRow[hashIdx]->firstElem = searchPtr->nextElem;
			printf("\n Element %d deleted from position %d in row %d", valToDel, searchPtr->position, hashIdx);
			free(searchPtr);
			return;
		}

		// Element is not the first element in the has table; loop through to find the location of our desired element.
		while(searchPtr->nextElem != NULL)
		{
			if(searchPtr->nextElem->key == valToDel)
			{
				delPtr = searchPtr->nextElem;
				searchPtr->nextElem = delPtr->nextElem;
				printf("\n Element %d deleted from position %d in row %d", valToDel, delPtr->position, hashIdx);
				free(delPtr);
				return;
			}
			searchPtr = searchPtr->nextElem;
		}
		printf("\n Element %d not found in the hash table. \n", valToDel);
	}
}

int main()
{
	int i = 0;
	struct elemRow **rowPtr;


	if(!rowPtr)
	{
		printf("\n %p \n ", rowPtr);
	}
	else
	{
		printf("\n rowPtr is NULL. \n");
	}

	setUpRowPointers(rowPtr);
#if 0
	for(i = 0; i < MAX_ROWS; i++)
	{
		printf("\n %d", rowPtr[i]->rowIdx);
	}

	insertElementIntoHashTables(rowPtr,21 );
	insertElementIntoHashTables(rowPtr, 4);
	insertElementIntoHashTables(rowPtr, 6);
	insertElementIntoHashTables(rowPtr, 71);
	insertElementIntoHashTables(rowPtr, 56);
	insertElementIntoHashTables(rowPtr, 8);
	insertElementIntoHashTables(rowPtr, 26);
	insertElementIntoHashTables(rowPtr, 9);
	insertElementIntoHashTables(rowPtr, 10);
	insertElementIntoHashTables(rowPtr, 11);
	insertElementIntoHashTables(rowPtr, 10);
	insertElementIntoHashTables(rowPtr, 12);
	insertElementIntoHashTables(rowPtr, 32);
	insertElementIntoHashTables(rowPtr, 44);
	insertElementIntoHashTables(rowPtr, 72);

	printf("\n Before Deletion: ");
	for(i = 0; i < MAX_ROWS; i++)
	{
		struct element *tempPtr = rowPtr[i]->firstElem;
		printf("\n Elements in row %d: ", i);
		while(tempPtr != NULL)
		{
			printf("\t position: %d key: %d", tempPtr->position, tempPtr->key);
			tempPtr = tempPtr->nextElem;
		}
		printf("\n");
	}

	deleteKeyFromHashTable(rowPtr, 41);
	deleteKeyFromHashTable(rowPtr, 31);
	deleteKeyFromHashTable(rowPtr, 11);
	deleteKeyFromHashTable(rowPtr, 32);
	deleteKeyFromHashTable(rowPtr, 17);
	
	printf("\n After Deletion: ");
	for(i = 0; i < MAX_ROWS; i++)
	{
		struct element *tempPtr = rowPtr[i]->firstElem;
		printf("\n Elements in row %d: ", i);
		while(tempPtr != NULL)
		{
			printf("\t position: %d key: %d", tempPtr->position, tempPtr->key);
			tempPtr = tempPtr->nextElem;
		}
		printf("\n");
	}
#endif
}
