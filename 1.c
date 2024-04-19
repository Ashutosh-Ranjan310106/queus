#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queus;
Queus *create_queus()
{
    Queus *queus = (Queus *)malloc(sizeof(Queus));
    if (queus == NULL)
    {
        printf("memory allocation fail");
        exit(-1);
    }
    queus->front = -1;
    queus->rear = -1;
    return queus;
}
int is_empty(Queus *queus)
{
    return queus->rear == -1;
}

int is_full(Queus *queus)
{
    return queus->rear >= MAX_SIZE - 1;
}
int enqueu(Queus *queus, int item)
{
    if (is_full(queus))
    {
        printf("queus is Full, Cannot push %d. \n", item);
        return -1;
    }    
    else
    {
        if (queus->front = queus->rear){
            queus->front++;
        }
        queus->items[++queus->rear] = item;
        return 1;
    }
}
int dequeu(Queus *queus)
{
    if (is_empty(queus))
    {
        printf("queus is empty, Cannot pop, \n");
        return -1;
    }
    int data=queus->items[queus->front];
    for (int i = queus->front; i < queus->rear; i--){
        queus->items[i]=queus->items[i+1];
    }
    queus->rear--;
    if (queus->rear == -1){
        queus->front--; 
    }
    return data;
}
void destroy_queus(Queus *queus)
{
    free(queus);
}
int main()
{
    Queus *queus = create_queus();
    int x = 0;
    while (enqueu(queus, x) != -1)
    {
        x++;
    }
    int dequed=-dequeu(queus);
    while ( dequed != -1)
    {
        printf("dequed element is: %d\n",dequed);
        dequed=dequeu(queus);
    }
    destroy_queus(queus);
    return 0;
}