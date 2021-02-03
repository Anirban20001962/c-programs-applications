#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int number;
    struct Node* next;
} node;
void traversal(node* head);
void append(node* head,int data);
struct Node* insertBegin(node* head, int data);
int main() {
    int choice = 0;
    int data;
    node* head = NULL;
    while (1)
    {
        printf("Press 1 to insert ,press 2 to append , press 3 for display and press other no. to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number\n");
            scanf("%d",&data);
            head = insertBegin(head,data);
            break;
        case 2:
            printf("Enter a number\n");
            scanf("%d",&data);
            append(head,data);
            break;
        case 3:
            traversal(head);
            break;
        default:
            printf("I hope you enjoyed!!!\n");
            exit(1);
            break;
        }
    }
}
void append(node* head,int data) {
    node* newNode = (node*) malloc(sizeof(node));
    node* temp = head;
    newNode->number = data;
    newNode->next=NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
node* insertBegin(node* head,int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->number = data;
    if(head == NULL) {
        newNode->next = NULL;
        head = newNode;
        return head;
    }
    newNode->next = head;
    return newNode;
}
void traversal(node* head) {
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ",temp->number);
        temp= temp->next;
    }
    printf("\n");
}