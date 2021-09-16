#include <stdio.h>
#include "data_struct.h"

int main()
{
    // Stack* stack = create_stack();
    // push(stack, 5);
    // push(stack, 9);
    // printf("%d\n", pop(stack));
    // printf("%d\n", top(stack));
    // delete_stack(stack);
    // stack = NULL;

    // Queue* queue = create_queue();
    // enqueue(queue, 5);
    // enqueue(queue, 9);
    // printf("%d\n", dequeue(queue));
    // printf("%d\n", front(queue));
    // delete_queue(queue);
    // queue = NULL;

    List* list = create_list();
    push_back(list, 2);
    push_back(list, 9);
    push_back(list, 3);
    push_back(list, 6);
    pop_back(list);
    push_back(list, 12);
    print_list(list);
    printf("index 0 of the list is %d\n", get_data(list, 0));
    sort_list(list);
    print_list(list);
    delete_list(list);
    list = NULL;

    // int arr[5] = {4, 2, 7, 4, 9};
    // sort_array(arr, 5);
    // print_array(arr, 5);

    return 0;
}