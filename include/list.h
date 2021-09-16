#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "node.h"

struct List
{
    int size;
    Node* start_node;
};

typedef struct List List;

List* create_list()
{
    List* l = (List*)malloc(sizeof(List));
    l->size = 0;
    l->start_node = NULL;
    return l;
}

void delete_list(List* l)
{
    Node* current = l->start_node;
    while(current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(l);
}

void push_back(List* l, int value)
{
    Node* new_node = create_node();
    new_node->data = value;
    if(l->start_node == NULL)
    {
        l->start_node = new_node;
    }
    else
    {
        Node* current = l->start_node;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    l->size++;
}

int pop_back(List* l)
{
    Node* current = l->start_node;
    while(current->next->next != NULL)
    {
        current = current->next;
    }
    int popped = current->next->data;
    free(current->next);
    current->next = NULL;
    l->size--;
    return popped;
}

Node* get_node(List* l, int index)
{
    if(index >= l->size || index < 0) return NULL;
    else
    {
        Node* current = l->start_node;
        for(int i = 1; i <= index; i++)
        {
            current = current->next;
        }
        return current;
    }
}

int get_data(List* l, int index)
{
    if(index >= l->size || index < 0) return -999;
    else return get_node(l, index)->data;
    // {
    //     Node* current = l->start_node;
    //     for(int i = 1; i <= index; i++)
    //     {
    //         current = current->next;
    //     }
    //     return current->data;
    // }
}

int get_list_size(List* l)
{
    return l->size;
}

void print_list(List* l)
{
    printf("{");
    if(l->start_node == NULL) printf("}\n");
    else
    {
        Node* current = l->start_node;
        while(current->next != NULL)
        {
            printf("%d, ", current->data);
            current = current->next;
        }
        printf("%d}\n", current->data);
    }
}

#endif