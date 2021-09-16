#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "node.h"

struct Queue
{
    Node* front_node;
};

typedef struct Queue Queue;

Queue* create_queue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front_node = NULL;
    return q;
}

void delete_queue(Queue* q)
{
    Node* current = q->front_node;
    while(current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(q);
}

void enqueue(Queue* q, int value)
{
    Node* new_node = create_node();
    new_node->data = value;
    if(q->front_node == NULL)
    {
        q->front_node = new_node;
    }
    else
    {
        Node* current = q->front_node;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

int dequeue(Queue* q)
{
    int dequeued = q->front_node->data;
    Node* new_front = q->front_node->next;
    free(q->front_node);
    q->front_node = new_front;
    return dequeued;
}

int front(Queue* q)
{
    return q->front_node->data;
}

#endif