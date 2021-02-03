#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct  stack
{
    int top;
    unsigned capacity;
    int *arr;
} STACK;


int isDigit(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch== '/' || ch== '^' || ch==' ') {
        return 0;
    }
        return 1;
}

void stack_push(int n,STACK* s) {
    if(s->top == s->capacity) {
        printf("Overflow");
        exit(0);
    }
    s->arr[++s->top] = n;
}

int pop(STACK* s) {
    if (s->top == -1)
    {
        printf("Underflow");
        exit(1);
    }
    return s->arr[s->top--];
}


int main() {
    int len;
    char input_string[80];
    printf("Enter expression\n");
    gets(input_string);
    STACK* stack_main =  (STACK*) malloc(sizeof(STACK));
    stack_main->top = -1;
    len = strlen(input_string);
    stack_main->capacity = len;
    stack_main->arr = (int*)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++){
        char ch;
        ch = input_string[i];
        if(ch==' ')continue;
        else if(isDigit(ch)){
            int num=0; 
              
            //extract full number 
            while(isDigit(input_string[i]))  
            { 
            num=num*10 + (int)(input_string[i]-'0'); 
                i++; 
            } 
            i--; 
            stack_push(num,stack_main);
        }
        else
        {
            int val1 = pop(stack_main);
            int val2 = pop(stack_main);
            switch (ch) 
            { 
            case '+': stack_push(val2 + val1,stack_main); break; 
            case '-': stack_push(val2 - val1,stack_main); break; 
            case '*': stack_push(val2 * val1,stack_main); break; 
            case '/': stack_push(val2/val1,stack_main); break; 
            case '^': stack_push(val2 ^ val1,stack_main); break;
            } 
        }
    }
    printf("%d",stack_main->arr[stack_main->top]);
    return 0;
}

