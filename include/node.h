#ifndef NODE_H
#define NODE_H

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* create_node()
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = 0;
    n->next = NULL;
}

#endif