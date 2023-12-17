/*24.	Add 2 non-negative numbers that have been given as a linked list
Given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example 1:
operand_1:            7 → 2 → 3 → 3
operand_2:                5 → 7 → 4
result:               7 → 8 → 0 → 7

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
    
struct node* head1=NULL;
struct node* head2=NULL;
struct node* head3=NULL;
int n,m;
void insertInEnd(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = data;
    struct node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
    } 
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtFirst(struct node** head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = data;
    if (*head == NULL) {
        *head = newNode;
    } 
    else{
        newNode->next= *head;
        *head= newNode;
    }
}

void traversal(struct node* head) {
    
    while (head != NULL) {
        printf("->%d", head->data);
        head = head->next;
    }
}
struct node* reverse(struct node* head) {
    struct node* current = head;
    struct node* forward = NULL;
    struct node* back = NULL;

    while (current != NULL) {
        forward = current->next;
        current->next = back;
        back = current;
        current = forward;
    }

    return back; // Return the new head of the reversed list
}

void add(struct node* p1, struct node* p2) {
    int carry = 0;
    
    while (p1 != NULL || p2 != NULL || carry != 0) {
       
        int val1 = (p1 != NULL) ? p1->data : 0;
        int val2 = (p2 != NULL) ? p2->data : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        insertAtFirst(&head3, sum % 10);

        if (p1 != NULL) {
            p1 = p1->next;
        }
        if (p2 != NULL) {
            p2 = p2->next;
        }
    }
}

int main(){
    
    int data;
    struct node* s=NULL;
    struct node* d=NULL;
    printf("Enter the no. of node in  linked list 1:\n");
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter data %d for the linked list 1:\n",(i+1));
        scanf("%d", &data);
        insertInEnd(&s,data);
    }

    printf("\nEnter the no. of node in  linked list 2:\n");
    scanf("%d",&m);
    
    for (int i = 0; i < m; i++) {
        printf("Enter data %d for the linked list 2:\n",(i+1));
        scanf("%d", &data);
        insertInEnd(&d,data);
    }
   
    printf("\nOperand 1:");
    traversal(s);
    printf("\nOperand 2:");
    traversal(d);

    head1=reverse(s);
    head2=reverse(d);

    add(head1,head2);
   

    printf("\nResult:");
    traversal(head3);
    return 0;
}