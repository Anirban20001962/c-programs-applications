#include<stdio.h>
#include<stdlib.h>
unsigned capacity;
unsigned no_of_el;
typedef struct  queue
{
    int front,rear;
    int* arr;
} QUEUE;

void insert(QUEUE* s,int data) {
   if (no_of_el == capacity)
   {
       printf("Overflow\n");
       return;
   }
   no_of_el++;
   s->arr[++s->rear%capacity] = data;
}

int delete(QUEUE* s) {
    if(no_of_el == 0) {
        printf("Underflow\n");
        return -1;
    }
    no_of_el--;
    return s->arr[++s->front%capacity];
}

void display(QUEUE* s) {
   if(no_of_el == 0) {
        printf("Underflow\n");
        return;
    }
    if(s->front < s->rear) {
        for (int i = s->front+1; i <= s->rear; i++)
        {
            printf("%d ",s->arr[i]);
        }
    }
    else
    {
        for (int i = s->front+1; i <= capacity-1; i++)
        {
            printf("%d ",s->arr[i]);
        }
        for (int i = 0; i <= s->rear; i++)
        {
            printf("%d ",s->arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int n,ch,no;
    QUEUE* circular_queue = (QUEUE*) malloc(sizeof(QUEUE));
    circular_queue->front = -1;
    circular_queue->rear = -1;
    no_of_el = 0;
    printf("Enter length of circular queue\n");
    scanf("%d",&n);
    capacity = n;
    circular_queue->arr = (int*)calloc(n,sizeof(int));
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
            insert(circular_queue,no);
            break;
        case 2:
            printf("%d",delete(circular_queue));
            break;
        case 3:
            display(circular_queue);
            break;
        default : 
            exit(0);
            break;
        }
    }
    return 0;
}
