#include <stdio.h>
#include <stdlib.h>

void push(int* top,int *arr,int n,int data) {
    if(*top == (n-1)){
        printf("Stack overflow\n");
        return;
    }
    arr[++*top] = data;
}

int pop(int *top,int *arr) {
    if(*top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    *top = *top - 1;
    return arr[*top+1];
}
void display(int* top,int* arr) {
    if(*top == -1) {
        printf("Underflow\n");
    }
    for(int i=0;i<=*top;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main(){
    int *arr,n,choice,data,top;
    top = -1;
    printf("Enter length of stack \n");
    scanf("%d",&n);
    arr = (int*)calloc(n,sizeof(int));
    printf("Press 1 to push ,press 2 to pop , press 3 for display and press other no. to exit\n");
        
        while(1){
            printf("Enter your choice\n");
            scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number\n");
            scanf("%d",&data);
            push(&top,arr,n,data);
            break;
        case 2:
            printf("%d\n",pop(&top,arr));
            break;
        case 3:
            display(&top,arr);
            break;
        default:
            printf("I hope you enjoyed!!!\n");
            exit(1);
            break;
        }
    }
}