#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define LIMIT 500

typedef struct prefix_expression
{
      int top;
      int stack[LIMIT];
}stack_structure;

void initialize(stack_structure *temp)
{
      temp->top = -1;
}

void push(stack_structure *temp, int num)
{
      if(temp->top == LIMIT)
      {
            printf("\nStack Overflow\n");
            exit(-1);
      }
      else
      {
            temp->top++;
            temp->stack[temp->top]=num;
      }
}

int pop(stack_structure *temp)
{
      int num;
      if(temp->top < 0)
      {
            printf("\nStack Underflow\n");
            exit(-1);
      }
      num = temp->stack[temp->top];
      temp->top--;
      return num;
}

int top(stack_structure *temp)
{
      return temp->stack[0];
}

void evaluate_prefix(stack_structure *temp, char op, int x, int y)
{
      int result;
      switch(op)
      {
            case '-': result = x - y;
                      break;
            case '*': result = x * y;
                      break;
            case '%': result = x % y;
                      break;
            case '/': result = x / y;
                      break;
            case '+': result = x + y;
                      break;
            case '$': result = pow(x, y);
                      break;
      }
      push(temp, result);
}

int find_op(char ch)
{
      switch(ch)
      {
            case '%': return 20;
            case '/': return 20; 
            case '*': return 20;
            case '-': return 20;
            case '$': return 20;
            case '+': return 20;
            default : return 10;
      }
}

int main()
{
      int x, y, element, length, count;
      char * expression;
      stack_structure expression_stack;
      initialize(&expression_stack);
      printf("\nEnter Prefix Expression:\t");
      scanf("%s", expression);
      length = strlen(expression);
      for(count = length - 1; count >= 0; count--)
      {
            if(expression[count] == '\0' || expression[count] == ' ')
            {
                  continue;
            }
            switch(find_op(expression[count]))
            {
                  case 20 : x = pop(&expression_stack);
                            y = pop(&expression_stack);
                            evaluate_prefix(&expression_stack, expression[count], x, y);
                            break;
                  case 10 : element = expression[count] - '0';
                            push(&expression_stack, element);
                            break;
            }
      }
      if(expression_stack.top != 0)
      {
            printf("\nInvalid Expression!\n");
            return -1;
      }
      printf("\nEvaluation of Prefix Expression:\t %d\n", top(&expression_stack));
      return 0 ;
}
