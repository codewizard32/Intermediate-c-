#include <bits/stdc++.h>
using namespace std;

struct Stack *create (int max);
int stackFull (struct Stack *stack);
int stackEmpty (struct Stack *stack);
void pushElement (struct Stack *stack, int item);
int popElement (struct Stack *stack);
int peekElement (struct Stack *stack);
int checkOperand (char ch);
int precedence (char ch);
int postfix (char *expression);
void reverse (char *exp);
void brackets (char *exp);
void conversionInfixToPrefix (char *exp);

struct Stack
{
  int top;
  int maxSize;
  int *array;
};
int main ()
{
  int n = 10;
  cout << "The infix expression is: \n";
  char expression[] = "(P+(Q*R)/(S-T))";
  cout << expression << "\n";
  conversionInfixToPrefix (expression);
  cout << "The prefix expression is: \n";
  cout << expression;
  return 0;
}

struct Stack * create (int max)
{
  struct Stack *stack = (struct Stack *) malloc (sizeof (struct Stack));
  stack->maxSize = max;
  stack->top = -1;
  stack->array = (int *) malloc (stack->maxSize * sizeof (int));
  return stack;
}


int stackFull (struct Stack *stack)
{
  if (stack->top == stack->maxSize - 1)
    {
      cout << "Will not be able to push maxSize reached\n";
    }
  
  return stack->top == stack->maxSize - 1;
}

int stackEmpty (struct Stack *stack)
{
  return stack->top == -1;
}


void pushElement (struct Stack *stack, int item)
{
  if (stackFull (stack))
    return;
  stack->array[++stack->top] = item;
}

 
int popElement (struct Stack *stack)
{
  if (stackEmpty (stack))
    return INT_MIN;
  return stack->array[stack->top--];
}


int peekElement (struct Stack *stack)
{
  if (stackEmpty (stack))
    return INT_MIN;
  return stack->array[stack->top];
}


int checkOperand (char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}


int precedence (char ch)
{
  switch (ch)
    {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
    }
  return -1;
}


int postfix (char *expression)
{
  int i, j;
  struct Stack *stack = create (strlen (expression));
  if (!stack)		
    return -1;

  for (i = 0, j = -1; expression[i]; ++i)
    {
      
      if (checkOperand (expression[i]))
	expression[++j] = expression[i];

      else if (expression[i] == '(')
	pushElement (stack, expression[i]);

     
      else if (expression[i] == ')')
	{
	  while (!stackEmpty (stack) && peekElement (stack) != '(')
	    expression[++j] = popElement (stack);
	  if (!stackEmpty (stack) && peekElement (stack) != '(')
	    return -1;		             
	  else
	    popElement (stack);
	}
      else			
	{
	  while (!stackEmpty (stack)
		 && precedence (expression[i]) <=
		 precedence (peekElement (stack)))
	    expression[++j] = popElement (stack);
	  pushElement (stack, expression[i]);
	}

    }

 
  while (!stackEmpty (stack))
    expression[++j] = popElement (stack);
    expression[++j] = '\0';
    
    return 0;
}

void reverse (char *exp)
{				

  int size = strlen (exp);
  int j = size, i = 0;
  char temp[size];

  temp[j--] = '\0';
  while (exp[i] != '\0')
    {
      temp[j] = exp[i];
      j--;
      i++;
    }
  strcpy (exp, temp);
}

void brackets (char *exp)
{
  int i = 0;
  while (exp[i] != '\0')
    {
      if (exp[i] == '(')
	exp[i] = ')';
      else if (exp[i] == ')')
	exp[i] = '(';
      i++;
    }
}

void conversionInfixToPrefix (char *exp)
{
  int size = strlen (exp);
  reverse (exp);
  brackets (exp);
  postfix (exp);
  reverse (exp);
}