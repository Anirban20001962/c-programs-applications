#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int number;
    struct Node* next;
} node;
void push(node** start,int data) {
    node* temp = *start;
    node* newNode = (node*) malloc(sizeof(node));
    newNode->next = NULL;
    newNode->number = data;
    if(temp==NULL) {
        *start = newNode;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void pop(node** start) {
    node* temp = *start;
    node* temp1;
    if(temp == NULL){
        printf("Stack is empty\n");
        return ;
    }
    
    if (temp->next == NULL) {
        *start = NULL;
        printf("%d\n",temp->number);
        free(temp);
        return;
    }
    while(temp->next != NULL){
        if(temp->next->next == NULL) {
            temp1 = temp;
        }
        temp = temp->next;
    }
    temp1->next = NULL;
    printf("%d\n",temp->number);
    free(temp);
}
void display(node** start) {
    node* temp = *start;
    if(temp == NULL) {
        printf("Underflow\n");
    }
    while(temp!= NULL){
        printf("%d ",temp->number);
        temp = temp->next;
    }
    printf("\n");
}

void main(){
    int choice,data;
    node* start = NULL;
    printf("Press 1 to push ,press 2 to pop , press 3 for display and press other no. to exit\n");
        
        while(1){
            printf("Enter your choice\n");
            scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number\n");
            scanf("%d",&data);
            push(&start,data);
            break;
        case 2:
            pop(&start);
            break;
        case 3:
            display(&start);
            break;
        default:
            printf("I hope you enjoyed!!!\n");
            exit(1);
            break;
        }
    }
}