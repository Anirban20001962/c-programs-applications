#include <stdio.h>
#include <stdlib.h>

struct Node{
  struct Node* prev;
  int data;
  struct Node* next;
};

struct Node* last(struct Node** head){
  struct Node* temp = *head;

  while(temp->next){
    temp= temp->next;
  }

  return temp;
}

void insert_at_first(int data, struct Node** head){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next= NULL;

    if(*head == NULL){
      *head = newNode;
      return;
    }

    struct Node* temp = *head;
    temp->prev = newNode;
    newNode->next = temp;
    *head = newNode;

}

// print reverse
void print_rev(struct Node** head ){
  struct Node* temp = last(head);

  while(temp){
    printf("%d, ", temp->data);
    temp = temp->prev;
  }

  printf("\n");
}

// insert After
void insert_after(int after, int data, struct Node** head){

  struct Node* temp = *head;

  if(*head == NULL){
    return;
  }

  while(temp-> data != after){
    temp = temp->next;
  }

  struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
  temp2->data = data;

  struct Node* prev_next = temp->next;
  temp->next = temp2;
  temp2->prev = temp;
  temp2->next = prev_next;


}

void insert_at_end(int data, struct Node** head){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->next = newNode->prev = NULL;
  newNode-> data = data;


  if (*head == NULL){
    *head = newNode;
    return;
  }

  struct Node* temp = last(head);

  temp->next = newNode;
  newNode->prev = temp;

}

int find(int data, struct Node** head){
  struct Node* temp = *head;
  int index = 0;

  while(temp){
    ++index;
    if(temp->data == data){
      return index;
    }

    temp = temp->next;
  }

  return -1;
}


void print(struct Node* head){
  struct Node* temp = head;

  while(temp){
    printf("%d, ",temp->data );
    temp = temp->next;
  }

  printf("\n");
}

int main(int argc, char const *argv[])
{
  struct Node* head = NULL;

  for (int i = 0; i < 6; ++i)
  {
    insert_at_first(i, &head);
  }

  print(head);
  print_rev(&head);

  insert_after(3, 8, &head);

  print(head);

  printf("Found at index: %d \n ",find(1, &head));
  return 0;
}