#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next_node;
}node;

void insert_begin(node **head, int data)
{
    node *new_node = (node*)malloc(sizeof(node));

    if(new_node != NULL)
    {
        new_node->data = data;
        new_node->next_node = *head;
        *head = new_node;
    }
    else
    {
        printf("no memory available\n");
    }
}
