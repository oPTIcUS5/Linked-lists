//Simple linked list

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

void insert_end(node **head, int data)
{
    node *current;

    node *new_node = (node*)malloc(sizeof(node));

    if(new_node != NULL)
    {
        new_node->data = data;
        new_node->next_node = NULL;

        if(*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            current = *head;

            while (current->next_node != NULL)
            {
                current = current->next_node;
            }

            current->next_node = new_node;
        }
    }
    else
    {
        printf("no memory available\n");
    }
}

void del_begin(node **head)
{
    node *temporal;

    if(*head != NULL)
    {
        temporal = *head;
        *head = (*head)->next_node;
        free(temporal);
    }
}

void print_list(node *head)
{
    node *current = head;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next_node;
    }
    printf("NULL\n");
}

int main()
{
    node *head = NULL;

    insert_begin(&head, 10);
    insert_begin(&head, 20);
    insert_begin(&head, 30);

    insert_end(&head, 40);
    insert_end(&head, 50);
    insert_end(&head, 60);

    print_list(head);
    
    return 0;
}
