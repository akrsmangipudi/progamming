# include <stdio.h>
# include <stdlib.h>

struct ListNode
{
	int data;
	struct ListNode *next;
};

int findLengthAndPrintList(struct ListNode *head)
{
	int len = 0;
	printf("\n");
	while(head)
	{
		printf("\t %d", head->data);
		head = head->next;
		len++;
	}
	printf("\n");
	return len;
}

struct ListNode* findAndReturnCommonPoint(struct ListNode *one, struct ListNode *two, int lenOne, int lenTwo)
{
	if(!lenOne || !lenTwo)
		return NULL;

	int lenDiff = (lenOne > lenTwo)	? (lenOne - lenTwo) : (lenTwo - lenOne);

	if(lenOne > lenTwo)
	{
		while(lenDiff > 0)
		{
			one = one->next;
			lenDiff--;
		}
	}
	else
	{
		while(lenDiff > 0)
		{
			two = two->next;
			lenDiff--;
		}
	}

	while(one && two)
	{
		if(one == two)
			return one;

		one = one->next;
		two = two->next;
	}
	return NULL;
}

struct ListNode* mergeLinkedListsIterative(struct ListNode *one, struct ListNode *two)
{
	struct ListNode *head = NULL, *mergeList = NULL;

	if(!one && !two)
	{
		return NULL;
	}
	else if( !one && two)
	{
		return two;
	}
	else if(one && !two)
	{
		return one;
	}
	else
	{		
		while(one && two)
		{
			// Empty merge Linked List. Initialize it.
			if(!head)
			{
				head = (struct ListNode *)malloc(sizeof(struct ListNode));
				head->next = NULL;
				mergeList = head;
			}
			else
			{
				mergeList->next = (struct ListNode *)malloc(sizeof(struct ListNode));
				mergeList = mergeList->next;
				mergeList->next = NULL;
			}
		
			if(one->data < two->data)
			{
				mergeList->data = one->data;
				one = one->next;
			}
			else
			{
				mergeList->data = two->data;
				two = two->next;
			}
		}
		
		while(one && !two)
		{
			if(mergeList)
				mergeList->next = one;
			else
				mergeList = one;
			break;
		}

		while(!one && two)
		{
			if(mergeList)
				mergeList->next = two;
			else
				mergeList = two;
			break;
		}

		if(!head)
			head = mergeList;
	}

	return head;
}

struct ListNode* mergeLinkedListsRecursive(struct ListNode *one, struct ListNode *two)
{
	if(!one && !two)
	{
		return NULL;
	}
	else if(!one && two)
	{
		return two;
	}
	else if(one && !two)
	{
		return one;
	}
	else
	{
		struct ListNode *merge = NULL;
		merge = (struct ListNode *)malloc(sizeof(struct ListNode));
		merge->next = NULL;
		if(one->data == two->data)
		{
			merge->data = one->data;
			merge->next = mergeLinkedListsRecursive(one->next, two->next);
		}
		else if(one->data < two->data)
		{
			merge->data = one->data;
			merge->next = mergeLinkedListsRecursive(one->next, two);
		}
		else	
		{
			merge->data = two->data;
			merge->next = mergeLinkedListsRecursive(one, two->next);
		}
		return merge;
	}	
}

void reverseInPairsIterative(struct ListNode **head)
{
	struct ListNode *current = *head, *temp1 = *head, *temp2 = NULL;
	
	while(current && current->next)
	{
		temp1 = current;
		current = current->next->next;
		temp1->next->next = temp1;
		if(!temp2)
		{
			temp2 = temp1->next;
			*head = temp2;
		}

		if(current)
		{
			if(current->next)
				temp1->next = current->next;
			else
				temp1->next = current;
		}
		else
			temp1->next = NULL;
	}
}

void reverseInPairsRecursive(struct ListNode **head)
{
	if(!(*head) || !(*head)->next)
		return;

	else
	{
		struct ListNode *temp1 = (*head), *current = (*head);

		current = current->next->next;

		temp1->next->next = temp1;	

		(*head) = temp1->next;

		if(current)
		{
			if(current->next)
			{
				temp1->next = current->next;
			}
			else
			{
				temp1->next = current;
			}
		}
		else
		{
			temp1->next = NULL;
		}

		reverseInPairsRecursive(&current);
	}
}

int main()
{
	struct ListNode *one = (struct ListNode *)malloc(sizeof(struct ListNode));
	one->data = 1;
	one->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	one->next->data = 2;
	one->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	one->next->next->data = 6;
	one->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	one->next->next->next->data = 7;
	one->next->next->next->next = NULL;
	printf("\n List One: ");	
	int lenOne = findLengthAndPrintList(one);
	printf("\n");

	struct ListNode *two = (struct ListNode *)malloc(sizeof(struct ListNode));
	two->data = 3;
	two->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	two->next->data = 4;
	two->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	two->next->next->data = 5;
	two->next->next->next = one->next->next;
	printf("\n List Two: ");	
	int lenTwo = findLengthAndPrintList(two);
	printf("\n");
	struct ListNode* ret = findAndReturnCommonPoint(one, two, lenOne, lenTwo);
	
	if(ret)
		printf("\n Intersecting Node: %d \n", ret->data);

	//struct ListNode *three = mergeLinkedListsIterative(one, two);
	
	struct ListNode *three = mergeLinkedListsRecursive(one, two);
	
	printf("\n Merged List: ");	
	int lenThree = findLengthAndPrintList(three);
	printf("\n");

	reverseInPairsIterative(&three);
	printf("\n Reverse in pairs iterative: ");	
	int revInPairIte = findLengthAndPrintList(three);
	printf("\n");

	reverseInPairsRecursive(&three);
	printf("\n Reverse in pairs recursive: ");	
	int revInPairRec = findLengthAndPrintList(three);
	printf("\n");

	return 0;
}
