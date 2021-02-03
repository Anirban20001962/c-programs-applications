#include<stdio.h>
#include<stdlib.h>
unsigned capacity;
typedef struct  queue
{
    int front,rear;
    int* arr;
} QUEUE;

void insert(QUEUE* s,int data) {
   if (s->rear == capacity - 1)
   {
       printf("Overflow\n");
       return;
   }
   s->arr[++s->rear] = data;
}

int delete(QUEUE* s) {
    if(s->front == -1 && s->rear ==-1) {
        printf("Underflow\n");
        return -1;
    }
    else if(s->front == s->rear)
    {
        printf("Underflow\n");
        return -1;     
    }
    return s->arr[++s->front];
}

void display(QUEUE* s) {
   if(s->front == -1 && s->rear ==-1) {
        printf("Underflow\n");
        return;
    }
    else if(s->front == s->rear)
    {
        printf("Underflow\n");
        return;     
    }
    for (int i = s->front+1; i <= s->rear; i++)
    {
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int main() {
    int n,ch,no;
    QUEUE* queue = (QUEUE*) malloc(sizeof(QUEUE));
    queue->front = -1;
    queue->rear = -1;
    printf("Enter length of queue\n");
    scanf("%d",&n);
    capacity = n;
    queue->arr = (int*)calloc(n,sizeof(int));
    printf("Press 1 to insert ,press2 to delete , press 3 to display and any no. to exit\n");
    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter a number\n");
            scanf("%d",&no);
            insert(queue,no);
            break;
        case 2:
            printf("%d",delete(queue));
            break;
        case 3:
            display(queue);
            break;
        default : 
            exit(0);
            break;
        }
    }
    return 0;
}