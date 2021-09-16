#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int array[], int size)
{
    printf("{");
    for(int i = 0; i < size - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d}\n", array[size - 1]);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort_array(int array[], int size)
{
    for(int i = size - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            if(array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void sort_array(int array[], int size)
{
    bubble_sort_array(array, size);
}

#ifdef LIST_H
void bubble_sort_list(List* list)
{
    if(list->start_node == NULL) return;
    for(int i = list->size - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            if(get_data(list, j) > get_data(list, j + 1))
            {
                swap(&get_node(list, j)->data, &get_node(list, j + 1)->data);
            }
        }
    }
}

void sort_list(List* list)
{
    bubble_sort_list(list);
}
#endif

#endif