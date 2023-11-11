#include <stdio.h>
#include <string.h>

#define MAX 100
int temp = 0;

struct stack {
  char stck[MAX];
  int top;
}s;

void push(char item) {
  if (s.top == (MAX - 1))
    printf("Stack is Full\n");

  else {
    s.top = s.top + 1;
    s.stck[s.top] = item;
  }
}

void pop() {
  if (s.top == -1)
    printf("Stack is Empty\n");

  else
    s.top = s.top - 1;
}

void checkPair(char val1,char val2){
    if (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' )){
        pop();
    }
    else{
        temp++;
    }
}

int parenthesismatch (char arr[]){
    char exp[MAX], j = 0;
    int i;
    for (i=0; arr[i] != '\0'; i++){
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[' || arr[i] == ']' || arr[i] == '}' || arr[i] == ')'){
            exp[j] = arr[i];
            j ++;
        }
    }
    printf("The parenthesis in the equation are as follows : ");
    puts(exp);
    i = 0;
    if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
        return 0;
    }
    for(i=0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[' ){
            push(exp[i]);
            printf("%d \n", s.top);
        }
        else{
            checkPair(s.stck[s.top],exp[i]);
            printf("%d \n",s.top);
        }
    }
    printf("temp = %d\n", temp);
    if(s.top == -1 && temp == 0){
        return 1;
    }
    else{
        return 0;
    }
}


int main() {
  char exp[MAX] = "[a+c}";
  s.top = -1;

  int chk = parenthesismatch(exp);
  if (chk == 1) printf("Balanced\n");
  else printf("Not  Balanced\n");

}
