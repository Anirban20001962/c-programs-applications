#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int coeff;
    int power;
    struct Node* next;
} node;
void display_polynomial(node** head);
void append(node** head,int coeff,int power);
node* add_polynomial(node** head1,node** head2);
int main() {
    int choice = 0;
    int data,data1;
    node* head1 = NULL;
    node* head2 = NULL;
    append(&head1,2,2);
    append(&head1,2,1);
    append(&head1,2,0);
    append(&head2,3,1);
    append(&head2,3,0);
    
    node* result = add_polynomial(&head2,&head1);
    display_polynomial(&head1);
    display_polynomial(&head2);
    display_polynomial(&result);

}
void append(node** head,int coeff,int power) {
    fflush(stdin);
    node* newNode = (node*) malloc(sizeof(node));
    node* temp = *head;
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next=NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void display_polynomial(node** head) {
    node* temp = *head;
    while (temp != NULL)
    {
        printf("%dx%d ",temp->coeff,temp->power);
        temp= temp->next;
    }
    printf("\n");
}

node* add_polynomial(node** head1,node** head2) {
    node* temp1 = *head1;
    node* temp2 = *head2;
    node* soln = NULL;
    if(temp1->power < temp2->power){
        node* temp = temp1;
        temp1 = temp2;
        temp2 = temp;
    }
    while(temp1 != NULL){
        int sum = temp1->coeff;
        if(temp2->power == temp1->power) {
            sum = sum + temp2->coeff;
            temp2 = temp2->next;
        }
        append(&soln,sum,temp1->power);
        temp1 = temp1->next;
    }
    return soln;
}