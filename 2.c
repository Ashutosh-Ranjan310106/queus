#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define FALSE -2147483647
#define TRUE 2147483647

typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct
{
    Node* front;
    Node* rear;
    int size;
} Queus;


int print_linked_list(struct Node** head){
    struct Node* temp;
    temp = *head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

Queus* create_queus()
{   
    Queus *queue = (Queus *)malloc(sizeof(Queus));
    if (queue == NULL)
    {
        printf("memory allocation fail");
        exit(-1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}
int is_empty(Queus *queue)
{
    return queue->front == NULL;
}
int get_size(Queus *queue){
    return queue->size;
}
int enqueu(Queus *queue, int value)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    if (node==NULL){
        printf("queus is Full, Cannot enque %d. \n", value);
        return FALSE;
    }else{
        node->data=value;
        node->next=NULL;
        queue->size++;
        if (queue->front==NULL){
            queue->front = node;
            queue->rear = node;
            return TRUE;
        }
        queue->rear->next=node;
        queue->rear=node;
        
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
    Node* de=queue->front;
    queue->front=queue->front->next;
    if (queue->front == NULL){
        queue->rear == NULL;
    }
    int data=de->data;
    free(de);
    queue->size--;
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
    while (x<10)
    {
        enqueu(queue, x);
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