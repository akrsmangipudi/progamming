# include <stdio.h>
# include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;



void insertAfter(struct node *elem, int value, int pos)
{
	int count = 0;
	struct node *temp = NULL, *temp1 = NULL;
	// Empty linked list.
	if(head == NULL)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->value = value;
		head->next = NULL;
		tail = head;
	}
	// Exactly one element in the LL.
	else if (head == tail)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->value = value;
		if(0 == pos)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
			tail->next = NULL;
		}
	}
	// We have more than 1 element in the LL.
	else
	{
		if(0 == pos)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->value = value;
			temp->next  = head;
			head = temp;
		}
		else
		{
			temp = head;
			while((count < pos) && (temp != tail))
			{
				temp = temp->next;
				count++;
			}

			// If temp = tail; element needs to be inserted after the tail element.
			// Else, temp is pointing to a node after which the element needs to be inserted.		

			if(temp == tail)
			{
				temp->next = (struct node *)malloc(sizeof(struct node));
				temp->next->value = value;
				temp->next->next = NULL;
				tail = temp->next;
			}
			else
			{
				temp1 = (struct node *)malloc(sizeof(struct node));
				temp1->value = value;
				temp1->next = temp->next;
				temp->next = temp1;
			}
		}
	}
}

void display(struct node *elem)
{
	for(elem = head; elem != NULL; elem = elem->next)
	{
		printf("\n %d \n", elem->value);
	}
	printf("\n head: %d, tail: %d \n", head->value, tail->value);
}

struct node* mThToLast(struct node *elem, int m)
{
	struct node *temp = head;
	elem = head;
	// List is empty.
	if(!elem)
	{
		return NULL;
	}
	// Only one element in the LL.
	else if (!elem->next)
	{
		return elem;
	}
	// We have more than 1 element in the LL.
	else
	{
		
		while((m > 0) && (temp->next != NULL))
		{
			temp = temp->next;
			m--;
		}

		if(temp->next == NULL)
			return elem;

		while(temp->next != NULL)
		{
			temp = temp->next;
			elem = elem->next;
		}
		return elem;
	}
}

int main()
{
	struct node *elem;
	insertAfter(elem, 10, 2);
	insertAfter(elem, 20, 1);
	insertAfter(elem, 30, 0);
	insertAfter(elem, 40, 2);
	insertAfter(elem, 50, 2);
	insertAfter(elem, 60, 2);
	insertAfter(elem, 70, 1);
	insertAfter(elem, 80, 0);
	insertAfter(elem, 90, 1);
	display(elem);
	struct node *temp = mThToLast(elem, 0);
	if(!temp)
		printf("\n mThToLast is NULL. \n");
	else
		printf("\n mThToLast: %d \n", temp->value);
	return 0;
}
