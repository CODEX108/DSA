/*
 * File: detectOrigin.c
 * Author: Manjiri Chavande
 * Email: cmanjiri1912@gmail.com
 * Created: September 18, 2023
 * Description: ii.	 Detect origin of linked list cycle
 */


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect the origin of a linked list cycle
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        // No cycle if there are less than two nodes
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Use the Tortoise and Hare algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // Move slow pointer by one step
        fast = fast->next->next; // Move fast pointer by two steps

        // If they meet, there's a cycle
        if (slow == fast) {
            // Reset one pointer to the head
            slow = head;

            // Move both pointers one step at a time until they meet again
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow; // Return the node where the cycle begins
        }
    }

    return NULL;
}

int main() {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 3;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 0;
    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = -4;
    head->next->next->next->next = NULL; // Create a cycle

    struct ListNode *cycleOrigin = detectCycle(head);

    if (cycleOrigin != NULL) {
        printf("Cycle begins at node with value %d\n", cycleOrigin->val);
    } else {
        printf("No cycle found\n");
    }

    // Clean up memory
    free(head->next->next->next);
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
