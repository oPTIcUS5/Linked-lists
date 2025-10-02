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

void del_end(node **head)
{
    node *current;
    node *previous;

    if(*head != NULL)
    {
        current = *head;

        if(current->next_node == NULL)
        {
            free(current);
            *head = NULL;
        }
        else
        {
            while (current->next_node != NULL)
            {
                previous = current;
                current = current->next_node;
            }

            previous->next_node = NULL;
            free(current);
        }
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
    node *list = NULL;
    int option;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        int data;

        switch (option)
        {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insert_begin(&list, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_end(&list, data);
                break;
            case 3:
                del_begin(&list);
                break;
            case 4:
                print_list(list);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 5);
    
    return 0;
}
