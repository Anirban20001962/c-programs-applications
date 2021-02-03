#include <stdio.h>
#include <stdlib.h>
struct Node {
    int number;
    struct Node* next;
    struct Node* prev;
};
void append(struct Node** head,struct Node** tail,int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* temp = *tail;
    newNode->number = data;
    newNode->next = NULL;
    if(temp == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        *tail = newNode;
        return;
    }
    newNode -> prev = temp;
    temp->next = newNode;
    *tail = temp->next;
}
void insertBegin(struct Node** head,struct Node** tail,int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->number = data;
    newNode->prev = NULL;
    if(temp == NULL) {
        newNode->next = NULL;
        *head = newNode;
        *tail = newNode;
        return;
    }
    newNode -> next = temp;
    temp->prev = newNode;
    *head = temp->prev;
}
int forwardtraversal(struct Node* head,int flag) {
    struct Node* temp = head;
    int length =0;
    while (temp != NULL)
    {
        length++;
        if(flag)
            printf("%d ",temp->number);
        temp= temp->next;
    }
    if(flag)
        printf("\n");
    return length;
}
void reversetraversal(struct Node* tail) {
    struct Node* temp = tail;
    while (temp != NULL)
    {
        printf("%d ",temp->number);
        temp= temp->prev;
    }
    printf("\n");
}
void insertAnyPosition(struct Node** head,struct Node** tail,int index,int data,int length) {
    struct Node* temp = *head;
    int temp_index = 0;
    if(index > length) {
        printf("Invalid index\n");
        return;
    }  
    if(index==0) {
        insertBegin(head,tail,data);
    }
    else if(index==length){
        append(head,tail,data);
    }
    else {
        while(temp_index < index -1) {
            temp = temp->next;
            temp_index++;
        }
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
            newNode->number = data;
            struct Node* temp1 = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            temp1->prev = newNode;
            newNode->next = temp1;
        }
    }
void deleteAtBegin(struct Node** head,struct Node** tail) {
    struct Node* temp = *head;
    if(temp == NULL){
        printf("Deletion not possible\n");
    }
    else {
        struct Node* temp1 = temp;
        temp = temp -> next;
        if(temp == NULL){
            *head = NULL;
            *tail= NULL;
            free(temp1);
            return;
        }
        temp -> prev = NULL;
        *head = temp;
        free(temp1);
    }
}

void deleteAtEnd(struct Node** head,struct Node** tail){
    struct Node* temp = *tail;
    if(temp == NULL){
        printf("Deletion not possible\n");
    }
    else {
        struct Node* temp1 = temp;
        temp = temp -> prev;
        if(temp == NULL){
            *head = NULL;
            *tail= NULL;
            free(temp1);
            return;
        }
        temp -> next = NULL;
        *tail = temp;
        free(temp1);
    }
}

void DeleteAnyPosition(struct Node** head,struct Node** tail,int index,int length) {
    if(head == NULL && tail == NULL) {
        printf("Deletion not possible\n");
    }
    struct Node* temp = *head;
    int temp_index = 0;
    if(index > length) {
        printf("Invalid index\n");
        return;
    }
    if(index==0) {
        deleteAtBegin(head,tail);
    }
    else if(index==length-1){
        deleteAtEnd(head,tail);
    }
    else {
        while(temp_index < index -1) {
            temp = temp->next;
            temp_index++;
        }
            struct Node* temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next->prev = temp;
            free(temp1);
        }
    }
int main() {
    int choice = 0;
    int data,length,index;
    struct Node* head = NULL; 
    struct Node* tail = NULL;
    printf("Press 1 to insert\npress 2 to append\npress 3 for forward display\npress 4 to reverse display\npress 5 to insert at any position\npress 6 to deletion at begining\npress 7 to deletion at end\npress 8 to deletion at any position\npress other no. to exit\n");
    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number\n");
            scanf("%d",&data);
            insertBegin(&head,&tail,data);
            break;
        case 2:
            printf("Enter a number\n");
            scanf("%d",&data);
            append(&head,&tail,data);
            break;
        case 3:
            forwardtraversal(head,1);
            break;
        case 4:
            reversetraversal(tail);
            break;
        case 5:
            printf("Enter a data and index respevitvely\n");
            scanf("%d %d",&data,&index);
            length = forwardtraversal(head,0);
            insertAnyPosition(&head,&tail,index,data,length);
            break;
        case 6:
            deleteAtBegin(&head,&tail);
            break;
        case 7:
            deleteAtEnd(&head,&tail);
            break;
        case 8:
             printf("Enter index respevitvely\n");
            scanf("%d",&index);
            length = forwardtraversal(head,0);
            DeleteAnyPosition(&head,&tail,index,length);
            break;
        default:
            printf("I hope you enjoyed!!!\n");
            exit(1);
            break;
        }
    }
}
    