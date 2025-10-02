#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next_node;
}node;

void insert_begin(node **head, int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    node *current;

    if (new_node == NULL)
    {
        printf("no memory available\n");
        return;
    }
    else
    {
        if(*head == NULL)
        {
            new_node->data = value;
            new_node->next_node = new_node;
            *head = new_node;
        }
        else
        {
            new_node->data = value;
            new_node->next_node = NULL;

            current = *head;
            while (current->next_node != *head)
            {
                current = current->next_node;
            }

            new_node->next_node = *head;
            current->next_node = new_node;
            *head = new_node;
            
        }
    }
    
}

void print_list(node *head)
{
    node *current;

    if(head == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        current = head;
        while (1)
        {
            printf("| %d | %p | ---> ", current->data, current->next_node);
            current = current->next_node;

            if (current == head)
                break;
        }
        printf("HEAD\n");
        
    }
}

int main()
{

    node *list = NULL;

    insert_begin(&list, 1);
    insert_begin(&list, 2);
    insert_begin(&list, 3);
    insert_begin(&list, 4);

    print_list(list);

    return 0;
}
