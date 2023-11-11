#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

struct Stack{
	int top;
	unsigned capacity;
	int *array;
};

struct Stack* Createstack(unsigned capacity){
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(int*)malloc(stack->capacity * sizeof(int));
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

int pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return 0;
}

void push(struct Stack* stack, int op)
{
    stack->array[++stack->top] = op;
}

int isNumber(char* exp,int i){
	int c1=i;
	while(exp[++c1]!=' ');
	if(c1==i+1)return -1;
	else
	return c1-i;
}
int eval_Postfix(char* exp)
{
	//exp=' '+exp+' ';
    // Create a stack of capacity equal to expression size
    struct Stack* stack = Createstack(strlen(exp));
    int i;
 
    // See if stack was created successfully
    if (!stack)
    return -1;
    // Scan all characters one by one
    for (i = 0; exp[i]!='\0'; ++i) {
        if(exp[i]==' ')continue;
        
        else if(isNumber(exp,i)!=-1){
        	int push_no=0,c=isNumber(exp,i)-1,count=i+isNumber(exp,i);
        	while(c>=0){
        		push_no=push_no+(pow(10,c) * (exp[i]-'0'));
        		i++;
        		c--;
			}
			push(stack,push_no);
			printf("%d\n",push_no);
			i=count-1;
		}
		
        // If the scanned character is an operand 
        // (number here), push it to the stack.
        
        else if (isdigit(exp[i])){
            push(stack, exp[i] - '0');
            printf("%d\n",stack->array[stack->top]);
        }
 
        // If the scanned character is an operator, 
        // pop two elements from stack apply the operator
        
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
            case '+':
                push(stack, val2 + val1);
                printf("%d\n",stack->array[stack->top]);
                break;
            case '-':
                push(stack, val2 - val1);
                printf("%d\n",stack->array[stack->top]);
                break;
            case '*':
                push(stack, val2 * val1);
                printf("%d\n",stack->array[stack->top]);
                break;
            case '/':
                push(stack, val2 / val1);
                printf("%d\n",stack->array[stack->top]);
                break;
            case '^':
            	push(stack, pow(val2,val1));
            	printf("%d\n",stack->array[stack->top]);
            	break;
            }
        }
    }
    
    return pop(stack);
}

int main()
{
    char exp[] = " 2 3 5 * + 50 5 2 ^ / - ";
    printf("Postfix evaluation: %d", eval_Postfix(exp));
    return 0;
}

