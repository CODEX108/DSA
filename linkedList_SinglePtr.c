/*
 * File: linkedlist.c
 * Author: Manjiri Chavande
 * Email: cmanjiri1912@gmail.com
 * Created: September 18, 2023
 * Description: i.  Create a Linked List ADT using the Struct 'Node'.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Create a new linked list node with 'data'
Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the given position in the linked list
void insert_at_pos(Node *head, int pos, int data)
{
    Node *new_node = create_node(data);
    if (pos == 0)
    {
        new_node->next = head->next;
        head->next = new_node;
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < pos - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            printf("Position not found.\n");
            free(new_node);
            return;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    printf("Node with data %d inserted successfully\n", data);
}

// Delete a node at the given position in the linked list
void delete_at_pos(Node *head, int pos)
{
    if (pos == 0 && head->next != NULL)
    {
        Node *temp = head->next;
        head->next = head->next->next;
        free(temp);
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < pos - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            printf("Position not found.\n");
            return;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

// Delete the first occurrence of a node with the given value in the linked list
void delete_by_value(Node *head, int value)
{
    Node *current = head;
    while (current->next != NULL && current->next->data != value)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        printf("Value not found.\n");
        return;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Get the node at the given position in the linked list
int *get_node_at_pos(Node *head, int pos)
{
    Node *current = head->next;
    int count = 0;
    while (current != NULL)
    {
        if (count == pos)
        {
            return current->data;
        }
        current = current->next;
        count++;
    }
    printf("Position not found.\n");
    return NULL;
}

// Find the first node with the given value in the linked list
Node *find_first(Node *head, int value)
{
    Node *current = head->next;
    while (current != NULL)
    {
        if (current->data == value)
        {
            return current;
        }
        current = current->next;
    }
    printf("Value not found.\n");
    return NULL;
}

// Display the entire linked list
void display(Node *head)
{
    Node *current = head->next;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Deallocate the memory used by the linked list
void free_linkedlist(Node *head)
{
    Node *current = head->next;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

// Reverse the linked list
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head->next;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
    return head;
}


int main()
{
    Node *head = create_node(-1); // Create a dummy head node

    // Insert some nodes
    insert_at_pos(head, 0, 1);
    insert_at_pos(head, 1, 2);
    insert_at_pos(head, 2, 3);

    // Display the linked list
    display(head);

    // Find and delete a node by value
    Node *found_node = find_first(head, 2);
    if (found_node != NULL)
    {
        printf("Found node with value %d. Deleting the node\n", found_node->data);
        delete_by_value(head, 2);
    }

    insert_at_pos(head, 2, 67);
    insert_at_pos(head, 3, 35);
    insert_at_pos(head, 4, 90);
    // Display the linked list after deletion
    display(head);
    printf("Node at posiiton 3 is : %d \n", get_node_at_pos(head, 3));
    display(head);

    printf("Deleting a node at position 2:\n");
    delete_at_pos(head, 2);
    display(head);

    // Reverse the linked list
    head = reverse(head);

    // Display the reversed linked list
    printf("Reversed linked list :");
    display(head);

    // Free memory
    free_linkedlist(head);

    return 0;
}
