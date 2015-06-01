# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

// Holds the number of elements in the infix string (source).
# define MAX 18

// **************** Infix to Postfix Conversion Algorithm  ***************** //
// (1) If scanned element is ' ' or '\t', ignore and move to the next element.
// (2) If scanned element is digit or alphabet, copy to the position that 'p' is pointing to and then increment 'p'.
// (3) If scanned element is '(', push it onto the stack represented by 'opStack'.
// (4) If scanned element is an operator:
//		(a) Keep popping elements from the stack as long as popped element has more priority than the scanned operator.
//		(b) Push the current operator (and last popped operator also if it has less priority than the scanned operator) onto the opStack.
// (5) If scanned element is ')', pop elements from 'opStack' still we encounter ')'. All popped elements (operators) must by copied into the
//     target string (from position 'p' and increment 'p' for each copied element).
// (6) Pop out any remaining operators from the stack one by one and push them onto the target string (by incrementing 'p' for each copy).

// **************** Struct Parameters Explanation ***************** //
// 'postfix' holds the postfix representation of the infix expression (output).
// 'opStack' - stack for holding the operators.
// 'infix' - holds the input expression (infix) expression.
// 'p' - points to the first location in the postfix Array initially and keeps incrementing with every element pushed onto it.
// 'top' - points to the top of the stack.
// 'length' - Holds the length of the infix expression.
typedef struct expression
{
	char postfix[MAX];
	char opStack[MAX];
	char *infix;
	char *p;
	int top;
    int length;
}expression;

unsigned int priority(char operator)
{
	if(operator == '$')
	{
		return 3;
	}
	else if(operator == '*' || operator == '/')
	{
		return 2;
	}
	else if(operator == '+' || operator == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(expression *e, char elem)
{
	e->top++;
	e->opStack[e->top] = elem;
}

char pop(expression *e)
{
	if(e->top == -1)
	{
		printf("\n Stack is empty. Nothing to Pop. \n");
		return '0';
	}
	else
	{
		return e->opStack[e->top--];
	}
}

void convertInfixToPostfix(expression *e)
{
	while(*(e->infix))
	{
		if((*(e->infix) == ' ') || (*(e->infix) == '\t'))
		{
			e->infix++;
		}

		if(isdigit(*(e->infix)) || isalpha(*(e->infix)))
		{
			*(e->p) = *(e->infix);
			e->p++;
			e->infix++;
		}

		if(*(e->infix) == '(')
		{
			push(e, *(e->infix));
			e->infix++;
		}

		if(*(e->infix) == '$' || *(e->infix) == '*' || *(e->infix) == '/' || *(e->infix) == '+' || *(e->infix) == '-')
		{
			if(*(e->infix) == '/')
			{
				printf("\n AM: Operator is '/'. \n");
			}
			if(e->top != -1)
			{
				char poppedOp = pop(e);
				while(priority(poppedOp) >= priority(*(e->infix)))
				{
					*(e->p) = poppedOp;
					e->p++;
					poppedOp = pop(e);
				}
				push(e, poppedOp);
				push(e, *(e->infix));
#if 0
				char flag = 0;
				while(priority(*(e->infix)) <= priority(poppedOp))
				{
					flag = 1;
					*(e->p) = poppedOp;
					e->p++;
					if(e->top != -1)
					{
						poppedOp = pop(e);
					}
					else
					{
						break;
					}
				}
				if(flag == 0)
				{
					push(e, poppedOp);
				}
				push(e, *(e->infix));
#endif
			}
			else
			{
				push(e, *(e->infix));
			}
			e->infix++;
		}

		if(*(e->infix) == ')')
		{
			char op = pop(e);
			while(op != '(' && e->top != -1)
			{
				*(e->p) = op;
				e->p++;
				op = pop(e);
			}
			e->infix++;
		}
	}

	while(e->top != -1)
	{
		*(e->p) = pop(e);
		e->p++;
	}
	e->p--;
	*e->p = '\0';
}

void initExpression(expression *e)
{
	e->top = -1;
	memset(e->postfix, 0, MAX);
	memset(e->opStack, 0, MAX);
	e->infix = "A+B*C/D";
	//e->infix = "4$2*3-3+8/4/(1+1)";
	e->length = strlen(e->infix);
	printf("\n Length: %d, Original: %s \n", e->length, e->infix);
	e->postfix[e->length] = '\0';
	// Make it point to the first element in the postfixArray.
	e->p = e->postfix;
}

int main()
{
	expression e;
	initExpression(&e);
	convertInfixToPostfix(&e);
	printf("\n %s \n", e.postfix);
	return 0;
}
