#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define FALSE -2147483647
#define TRUE 2147483647
typedef struct
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queus;
Queus *create_queus()
{
    Queus *queue = (Queus *)malloc(sizeof(Queus));
    if (queue == NULL)
    {
        printf("memory allocation fail");
        exit(-1);
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
int is_empty(Queus *queue)
{
    return queue->front == -1;
}

int is_full(Queus *queue)
{
    return queue->rear >= MAX_SIZE - 1;
}
int get_size(Queus *queue){
    return queue->rear + 1;
}
int enqueu(Queus *queue, int value)
{
    if (is_full(queue))
    {
        printf("queus is Full, Cannot enque %d. \n", value);
        return FALSE;
    }    
    else
    {
        if (is_empty(queue)){
            queue->front = 0;
        }
        queue->items[++queue->rear] = value;
        return TRUE;
    }
}
int dequeu(Queus *queue)
{
    if (is_empty(queue))
    {
        printf("queus is empty, Cannot deque \n");
        return FALSE;
    }
    int data=queue->items[queue->front];
    for (int i = queue->front; i < queue->rear; i++){
        queue->items[i]=queue->items[i+1];
    }
    queue->rear--;
    if (queue->rear == -1){
        queue->front = -1; 
    }
    return data;
}
void destroy_queus(Queus *queus)
{
    free(queus);
}
int main()
{
    Queus *queue = create_queus();
    printf("size: %d\n",get_size(queue));
    int x = 0;
    while (enqueu(queue, x) != FALSE)
    {
        x++;
    }
    printf("size: %d\n",get_size(queue));
    int dequed=-dequeu(queue);
    while ( dequed != FALSE)
    {
        printf("dequed element is: %d\n",dequed);
        dequed=dequeu(queue);
    }
    printf("size: %d\n",get_size(queue));
    destroy_queus(queue);
    return 0;
}