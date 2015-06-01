# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

// Holds the number of elements in the infix string (source).
const int MAX = 18;


// **************** Infix to Prefix Conversion Algorithm  ***************** //
// (1) If scanned element is ' ' or '\t', ignore and move to the next element.
// (2) If scanned element is digit or alphabet, copy to the position that 'p' is pointing to and then decrement 'p'.
// (3) If scanned element is ')', push it onto the stack represented by 'opStack'.
// (4) If scanned element is an operator:
//		(a) Keep popping elements from the stack as long as popped element has more priority than the scanned operator.
//		(b) Push the current operator (and last popped operator also if it has less priority than the scanned operator) onto the opStack.
// (5) If scanned element is '(', pop elements from 'opStack' still we encounter ')'. All popped elements (operators) must by copied into the
//     target string (from position 'p' and decrement 'p' for each copied element).
// (6) Pop out any remaining operators from the stack one by one and push them onto the target string (by decrement 'p' for each copy).

// **************** Struct Parameters Explanation ***************** //
// 'prefix' holds the prefix representation of the infix expression (output).
// 'opStack' - stack for holding the operators.
// 'infixRev' - holds the input expression (infix) expression in reverse order.
// 'p' - points to the last location in the prefix Array initially and keeps decrementing with every element pushed onto it.
// 'top' - points to the top of the stack.
// 'length' - Holds the length of the infix expression.
typedef struct expression
{
	char prefix[MAX];
	char opStack[MAX];
	char *infixRev;
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
	else
	{
		return 1;
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

void convertInfixToPrefix(expression *e)
{
	int dummyCount = 0;
	while(*(e->infixRev))
	{
		if((*(e->infixRev) == ' ') || (*(e->infixRev) == '\t'))
		{
			e->infixRev++;
		}

		if(isdigit(*(e->infixRev)) || isalpha(*(e->infixRev)))
		{
			*e->p = *(e->infixRev);
			e->p--;
			e->infixRev++;
		}

		if(*(e->infixRev) == ')')
		{
			push(e, *(e->infixRev));
			e->infixRev++;
		}

		if(*(e->infixRev) == '$' || *(e->infixRev) == '*' || *(e->infixRev) == '/' || *(e->infixRev) == '+' || *(e->infixRev) == '-')
		{
			if(e->top != -1)
			{
				char poppedOp = pop(e);
#if 0
				while(priority(poppedOp) > priority(*(e->infixRev)))
				{
					*(e->p) = poppedOp;
					e->p--;
					poppedOp = pop(e);
				}
				push(e, poppedOp);
				push(e, *(e->infixRev));	
#endif
				char flag = 0;
				while(priority(*(e->infixRev)) < priority(poppedOp))
				{
					flag = 1;
					*(e->p) = poppedOp;
					e->p--;
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
				push(e, *(e->infixRev));
			}
			else
			{
				push(e, *(e->infixRev));
			}
			e->infixRev++;
		}

		if(*(e->infixRev) == '(')
		{
			char op = pop(e);
			while(op != ')' && e->top != -1)
			{
				*(e->p) = op;
				e->p--;
				op = pop(e);
			}
			e->infixRev++;
		}
	}

	while(e->top != -1)
	{
		*(e->p) = pop(e);
		e->p--;
	}
	e->p++;
}

void initExpression(expression *e, char *infixExpr)
{
	e->top = -1;
	e->length = strlen(infixExpr);
	memset(e->prefix, 0, MAX);
	memset(e->opStack, 0, MAX);
	e->infixRev = ")1+1(/4/8+3-3*2$4";
	printf("\n Original: %s \n", infixExpr);
	printf("\n Length: %d Reversed: %s\n", e->length, e->infixRev);
	e->prefix[e->length] = '\0';
	e->p = &e->prefix[e->length - 1];
}

int main()
{
	expression e;
	char* infixExpr = "4$2*3-3+8/4/(1+1)";
	initExpression(&e, infixExpr);
	convertInfixToPrefix(&e);
	printf("\n \n %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n \n", e.prefix[2], e.prefix[3], e.prefix[4], e.prefix[5], e.prefix[6], e.prefix[7], e.prefix[8], e.prefix[9], e.prefix[10], e.prefix[11], e.prefix[12], e.prefix[13], e.prefix[14], e.prefix[15], e.prefix[16], e.prefix[17], e.prefix[1]);
	return 0;
}
