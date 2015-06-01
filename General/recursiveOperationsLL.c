# include <stdio.h>
# include <stdlib.h>

struct ListNode
{
	int data;
	struct ListNode *next;
};

void printList(struct ListNode *head)
{
	printf("\n");
	while(head)
	{
		printf("\t %d", head->data);
		head = head->next;
	}
	printf("\n");
}

void recursiveReverse(struct ListNode** head_ref)
{
    struct ListNode* first;
    struct ListNode* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;   
 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
       return;

	printf("\n 1) first: %d, rest: %d \n", first->data, rest->data);
 
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;  
     
    /* tricky step -- see the diagram */
    first->next  = NULL;          
 
    /* fix the head pointer */
    *head_ref = rest;
	printf("\n 2) first: %d, rest: %d \n", first->data, rest->data);
}

int recursiveNumOfNodes(struct ListNode *head)
{
	if(!head)
		return 0;
	return 1 + recursiveNumOfNodes(head->next);
}

int recursiveCompareLinkedLists(struct ListNode *node1, struct ListNode *node2)
{
	if((!node1) && (!node2))
	{
		printf("\n \n *** Returning 1 *** \n \n");
		return 1;
	}
	else if((!node1 && node2) || (node1 && !node2))
		return 0;
	else if(node1->data != node2->data)
		return 0;
	else
		return recursiveCompareLinkedLists(node1->next, node2->next);
}

void recursiveCopyLL(struct ListNode *head, struct ListNode **head1)
{
	if(!head)
		return;
	else
	{
		(*head1) = (struct ListNode *)malloc(sizeof(struct ListNode *));
		(*head1)->data = head->data;
		(*head1)->next = NULL;
		recursiveCopyLL(head->next, &(*head1)->next);
	}
}

void recursiveAddNodeAtEndLL(struct ListNode **head, int value)
{
	if(!(*head))
	{
		(*head) = (struct ListNode *)malloc(sizeof(struct ListNode *));
		(*head)->data = value;
		(*head)->next = NULL;
	}
	else
		recursiveAddNodeAtEndLL(&(*head)->next, value);
}

void printListFromEndRecursive(struct ListNode *head)
{
	if(!head)
		return;
	else
	{
		printListFromEndRecursive(head->next);
		printf("\t %d", head->data);
	}
} 

int main()
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->data = 1;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->data = 2;
	head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->data = 3;
	head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->next->data = 4;
	head->next->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->next->next->data = 5;
	head->next->next->next->next->next = NULL;
	printList(head);
	recursiveReverse(&head);
	printList(head);
	printf("\n # of nodes: %d", recursiveNumOfNodes(head));
	struct ListNode *head1 = NULL;
#if 0
	head1->data = 1;
	head1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head1->next->data = 2;
	head1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head1->next->next->data = 3;
	head1->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head1->next->next->next->data = 4;
	head1->next->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head1->next->next->next->next->data = 5;
	head1->next->next->next->next->next = NULL;
	printList(head1);
	printf("\n lists equal: %d \n", recursiveCompareLinkedLists(head, head1));
#endif
	recursiveCopyLL(head, &head1);
	printList(head1);
	recursiveAddNodeAtEndLL(&head1, 6);
	printList(head1);
	printf("\n List Recursive Printing: ");
	printListFromEndRecursive(head1);
	printf("\n");
}
