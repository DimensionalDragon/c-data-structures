#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "node.h"

struct Stack
{
    Node* top_node;
    Node* start_node;
};

typedef struct Stack Stack;

Stack* create_stack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top_node = NULL;
    s->start_node = NULL;
    return s;
}

void delete_stack(Stack* s)
{
    Node* current = s->start_node;
    while(current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(s);
}

void push(Stack* s, int value)
{
    Node* new_node = create_node();
    new_node->data = value;
    if(s->start_node == NULL)
    {
        s->start_node = new_node;
        s->top_node = new_node;
    }
    else
    {
        s->top_node->next = new_node;
        s->top_node = s->top_node->next;
    }
}

int pop(Stack* s)
{
    int popped = s->top_node->data;
    Node* current = s->start_node;
    while(current->next != s->top_node)
    {
        current = current->next;
    }
    free(s->top_node);
    current->next = NULL;
    s->top_node = current;
    return popped;
}

int top(Stack* s)
{
    return s->top_node->data;
}

#endif