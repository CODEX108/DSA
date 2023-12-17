#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to print the linked list
void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the end of the linked list
struct ListNode* insertNode(struct ListNode *head, int val) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct ListNode *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to partition the linked list based on a value x
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL) {
        return NULL;
    }

    // Create two dummy nodes to represent the two partitions
    struct ListNode *lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *greaterEqualHead = (struct ListNode*)malloc(sizeof(struct ListNode));

    // Initialize pointers for the two partitions
    struct ListNode *lessPtr = lessHead;
    struct ListNode *greaterEqualPtr = greaterEqualHead;

    struct ListNode *current = head;

    while (current != NULL) {
        // Compare the current node's value with x
        if (current->val < x) {
            lessPtr->next = current;
            lessPtr = lessPtr->next;
        } else {
            greaterEqualPtr->next = current;
            greaterEqualPtr = greaterEqualPtr->next;
        }

        // Move to the next node
        current = current->next;
    }

    // Connect the two partitions
    lessPtr->next = greaterEqualHead->next;
    greaterEqualPtr->next = NULL;

    // Get the head of the new partitioned list
    struct ListNode *result = lessHead->next;

    // Free the dummy nodes
    free(lessHead);
    free(greaterEqualHead);

    return result;
}

// Function to free the linked list
void freeList(struct ListNode *head) {
    struct ListNode *current = head;
    struct ListNode *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Example usage
    struct ListNode *head = NULL;

    // Insert nodes into the linked list
    head = insertNode(head, 1);
    head = insertNode(head, 5);
    head = insertNode(head, 3);
    head = insertNode(head, 2);
    head = insertNode(head, 4);
    head = insertNode(head, 2);

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Partition the linked list
    int x = 3;
    head = partition(head, x);

    // Print the partitioned linked list
    printf("Partitioned Linked List: ");
    printList(head);

    // Free the linked list
    freeList(head);

    return 0;
}
