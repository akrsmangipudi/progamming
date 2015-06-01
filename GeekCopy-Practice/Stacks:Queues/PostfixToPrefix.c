# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

// Holds the number of elements in the infix string (source).
# define MAX 18


// **************** Postfix to Prefix Conversion Algorithm  ***************** //
// (1) If scanned element is ' ' or '\t', ignore and move to the next element.
// (2) If scanned element is digit or alphabet, push it onto the stack.
// (3) If scanned element is an operator, pop first two elements from the stack, append 2nd popped element to the operator, followed by the
//	   first popped element and then push the trio onto the stack !

typedef struct expression
{
	char prefix[MAX];
	char opStack[MAX][MAX];
	char *postfix;
	int top, length;
	char str1[MAX], str2[MAX], str3[MAX];
	char temp1[2], temp2[2];
}expression;

void push(expression *e, char *elem)
{
	e->top++;
	strcpy(e->opStack[e->top], elem);
}

char* pop(expression *e)
{
	if(e->top == -1)
	{
		printf("\n Stack is empty. Nothing to Pop. \n");
		return NULL;
	}
	else
	{
		return e->opStack[e->top--];
	}
}

void initExpression(expression *e)
{
	e->top = -1;
	memset(e->prefix, 0, MAX);
	memset(e->opStack, 0, MAX*MAX);
	e->postfix = "42$3*3-84/11+/+";
	e->length = strlen(e->postfix);
	printf("\n Length: %d, Original: %s \n", e->length, e->postfix);
	e->prefix[e->length] = '\0';
	memset(e->str1, 0, MAX);
	memset(e->str2, 0, MAX);
	memset(e->str3, 0, MAX);
	memset(e->temp1, 0, 2);
	memset(e->temp2, 0, 2);
}

void convertPostFixToPreFix(expression *e)
{
	while(*(e->postfix))
	{
		if(*(e->postfix) == ' ' || *(e->postfix) == '\t')
		{
			e->postfix++;
			continue;
		}
		else if(*(e->postfix) == '$' || *(e->postfix) == '*' || *(e->postfix) == '/' || *(e->postfix) == '+' || *(e->postfix) == '-')
		{
			strcpy(e->str2, pop(e));
			strcpy(e->str3, pop(e));
			e->temp1[0] = *(e->postfix);
			e->temp1[1] = '\0';
			strcpy(e->str1, e->temp1);
			strcat(e->str1, e->str3);
			strcat(e->str1, e->str2);
			push(e, e->str1);	
		}
		else
		{
			e->temp1[0] = *(e->postfix);
			e->temp1[1] = '\0';
			push(e, e->temp1);
		}
		e->postfix++;
	}
}

int main()
{
	expression e;
	initExpression(&e);
	convertPostFixToPreFix(&e);
	printf("\n Converted prefix expression: ");
	int i = 0;
	printf("\n %s \n", e.opStack[i]);

//	while(i != e.top)
//	{
//		printf("\t %s", e.opStack[i]);
//		i++;
//	}
//	printf("\n");
	return 0;
}
