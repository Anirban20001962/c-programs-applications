#include<stdio.h>
#include<stdlib.h>
int capacity;
typedef struct  stack
{
    int top;
    int* arr;
} STACK;

void push(STACK* s,int data) {
    if (s->top == capacity-1) 
    {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(STACK* s) {
    if (s->top == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void display(STACK* s) {
    if (s->top == -1)
    {
        printf("Underflow\n");
        return;
    }
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int main() {
    int n,ch,no;
    STACK* stack_main = (STACK*) malloc(sizeof(STACK));
    stack_main->top = -1;
    printf("Enter length of stack\n");
    scanf("%d",&n);
    capacity = n;
    stack_main->arr = (int*)calloc(n,sizeof(int));
    printf("Press 1 to push ,press2 to pop,press 3 to display and press 4 to exit\n");
    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter a number\n");
            scanf("%d",&no);
            push(stack_main,no);
            break;
        case 2:
            printf("%d",pop(stack_main));
            break;
        case 3:
            display(stack_main);
            break;
        default : 
            exit(0);
            break;
        }
    }
    return 0;
}