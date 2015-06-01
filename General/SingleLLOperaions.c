#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

void display(struct node *frontPtr)
{
	while(frontPtr != NULL)
	{
		printf("\t %d", frontPtr->value);
		frontPtr = frontPtr->next;
	}
}

void append(struct node **frontPtr, int value)
{
	struct node *loopPtr = NULL;
	if(*frontPtr == NULL)
	{
		*frontPtr = (struct node *)malloc(sizeof(struct node));
		(*frontPtr)->value = value;
		(*frontPtr)->next = NULL;
	}
	else
	{
		loopPtr = *frontPtr;
		while(loopPtr->next)
			loopPtr = loopPtr->next;
		loopPtr->next = (struct node*)malloc(sizeof(struct node));
		loopPtr->next->value = value;
		loopPtr->next->next= NULL;
	}
}

void addatbeg(struct node **frontPtr, int value)
{
	struct node *tempPtr = (struct node*)malloc(sizeof(struct node));
	if(!tempPtr)
		return;
	tempPtr->next = (*frontPtr);
	tempPtr->value = value;
	(*frontPtr) = tempPtr;
}

#if 0
void addafter(struct node *frontPtr, int position, int value)
{
	int i;
	for(i = 0; i < position; i++)
	{
		frontPtr = frontPtr->next;
		if(frontPtr == NULL)
		{
			printf("\n End of LL. \n");
			return;
		}
	}

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->value = value;
	temp->next  = frontPtr->next;
	frontPtr->next = temp;
}
#endif

void addafter(struct node *frontPtr, int position, int value)
{
	while(position > 0)
	{
		frontPtr = frontPtr->next;
		if(!frontPtr)
		{
			printf("\n End of LL is hit. \n");
			return;
		}
		position--;
	}
	
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->value = value;
	temp->next  = frontPtr->next;
	frontPtr->next = temp;
}

void add(struct node **asc, int value)
{
	struct node *temp = (*asc);
	struct node *create = NULL;
	if(!(*asc))
	{
		(*asc) = (struct node*)malloc(sizeof(struct node));
		(*asc)->value = value;
		(*asc)->next = NULL;
	}
	else
	{
		// Insert as the first element in the LL.
		if(temp->value >= value)
		{
			create = (struct node*)malloc(sizeof(struct node));
			create->value = value;
			create->next = temp;
			*(asc) = create;
		}
		else
		{
			while((temp->value < value) && (temp->next != NULL) && (temp->next->value < value))
				temp = temp->next;
			create = (struct node*)malloc(sizeof(struct node));
			create->value = value;
			create->next  = temp->next;
			temp->next = create;
		}
	}
}

void reverse(struct node **asc)
{
	struct node *one = (*asc), *two, *three;
	two = three = NULL;
	while(one)
	{
		three = two;
		two = one;
		one = one->next;
		two->next = three;
	}
	*asc = two;
}

void merge(struct node *firstLL, struct node *secondLL, struct node **mergeLL)
{
	struct node *nav = NULL, *temp = NULL;

	while(firstLL || secondLL)
	{
		nav = (struct node*)malloc(sizeof(struct node));
		
		// Retaining the reference to the head pointer.
		if(!(*mergeLL))
		{
			(*mergeLL) = nav;
		}

		if(temp)
		{
			temp->next = nav;
		}

		temp = nav;

		// Data present in both the LLs.
		if(firstLL && secondLL)
		{
			// First LL current value > Second LL current value.
			if(firstLL->value > secondLL->value)
			{
				nav->value = secondLL->value;
				nav->next = NULL;
				secondLL=secondLL->next;
			}
			// Second LL current value > First LL current value.
			else if(firstLL->value < secondLL->value)
			{
				nav->value = firstLL->value;
				nav->next = NULL;
				firstLL=firstLL->next;
			}
			// Both the LLs have the same value.
			else
			{
				nav->value = firstLL->value;
				nav->next = NULL;
				firstLL=firstLL->next;
				secondLL=secondLL->next;
			}
		}
		// Data present only in the first LL.
		else if(firstLL && !secondLL)
		{
			nav->value = firstLL->value;
			nav->next = NULL;
			firstLL=firstLL->next;
		}
		// Data present only in the second LL.
		else
		{
			nav->value = secondLL->value;
			nav->next = NULL;
			secondLL=secondLL->next;
		}
	}
}

int countNumElem(struct node *headPtr)
{
	int count = 0;
	while(headPtr)
	{
		count++;
		headPtr = headPtr->next;
	}
	return count;
}

void selectionSort(struct node *nodePtr)
{
	int temp = 0, innerIdx =0 , outerIdx = 0, operateIdx = 0;
	int count = countNumElem(nodePtr);
	printf("\n Count = %d \n", count);
	struct node *outerTraversePtr = nodePtr;
	struct node *innerTraversePtr = nodePtr;
	for(outerIdx = 0; outerIdx < count - 1; outerIdx++)
	{
		innerTraversePtr = outerTraversePtr->next;
		for(innerIdx = outerIdx + 1; innerIdx < count; innerIdx++)
		{
			if(outerTraversePtr->value > innerTraversePtr->value)
			{
				temp = outerTraversePtr->value;
				outerTraversePtr->value = innerTraversePtr->value;
				innerTraversePtr->value = temp;
			}
			innerTraversePtr = innerTraversePtr->next;
		}
		outerTraversePtr = outerTraversePtr->next;
	}
}

void bubbleSort(struct node *nodePtr)
{
	int temp = 0, innerIdx =0 , outerIdx = 0, operateIdx = 0;
	int count = countNumElem(nodePtr);
	printf("\n Count = %d \n", count);
	operateIdx = count;
	struct node *traversePtr = nodePtr;

	for(outerIdx = 0; outerIdx < count - 1; outerIdx++, operateIdx--)
	{
		traversePtr = nodePtr;
		for(innerIdx = 1; innerIdx < operateIdx; innerIdx++)
		{
			if(traversePtr->value > traversePtr->next->value)
			{
				temp = traversePtr->value;
				traversePtr->value = traversePtr->next->value;
				traversePtr->next->value = temp;
			}
			traversePtr = traversePtr->next;
		}
	}

}

void copyUsingRecursion(struct node *srcPtr, struct node **destPtr)
{
	if(!srcPtr)
		return;
	else
	{
		(*destPtr) = (struct node *)malloc(sizeof(struct node));
		(*destPtr)->value = srcPtr->value;
		(*destPtr)->next = NULL;
		copyUsingRecursion(srcPtr->next, &((*destPtr)->next));
	}
}

void addNewNodeAtEndRecursive(struct node **s, int value)
{
	if(!(*s))
	{
		(*s) = (struct node*)malloc(sizeof(struct node));
		(*s)->value = value;
		(*s)->next = NULL;
	}
	else
	{
		addNewNodeAtEndRecursive(&((*s)->next), value);
	}
}

int main()
{
	struct node *s = NULL;
	struct node *asc = NULL;
	append(&s, 6);
	append(&s, 5);
	append(&s, 4);
	append(&s, 3);
	append(&s, 2);
	append(&s, 1);
#if 0
	addatbeg(&s, 999);
	addatbeg(&s, 888);
	addatbeg(&s, 777);
	printf("\n");
	display(s);
	addafter(s, 1, 1);
	addafter(s, 1, 99);
	addafter(s, 1, 0);
	printf("\n");
	display(s);
	printf("\n");
	add(&asc, 6);
	add(&asc, 3);
	add(&asc, 45);
	add(&asc, 16);
	add(&asc, 77);
	add(&asc, 1935);
	add(&asc, 1);
	add(&asc, 23);
	printf("\n");
	display(asc);
	printf("\n");
	reverse(&asc);
	printf("\n");
	display(asc);
	printf("\n");
	// Merging the linked lists.
	add(&s, 71);
	add(&s, 61);
	add(&s, 35);
	add(&s, 17);
	add(&s, 14);
	add(&s, 12);
	add(&s, 9);
	printf("\n LL1 Before merge:");
	display(s);
	printf("\n");
	add(&asc, 87);
	add(&asc, 64);
	add(&asc, 59);
	add(&asc, 36);
	add(&asc, 24);
	add(&asc, 17);
	add(&asc, 12);
	printf("\n LL2 Before merge:");
	display(asc);
	printf("\n");
	struct node *mergeLLPtr = NULL;
	merge(s, asc, &mergeLLPtr);
	printf("\n After merge:");
	display(mergeLLPtr);
	printf("\n");
	printf("\n Before sorting:");
	display(s);
	printf("\n");
	bubbleSort(s);
	selectionSort(s);
	printf("\n After sorting:");
	display(s);
	printf("\n");
	copyUsingRecursion(s, &asc);
	printf("\n After recursive copying:");
	display(asc);
	printf("\n");
#endif
	addNewNodeAtEndRecursive(&s, 2000);
	printf("\n After recursively adding a node at the end:");
	display(s);
	printf("\n");
}
