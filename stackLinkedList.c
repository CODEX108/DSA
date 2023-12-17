/*
 * File: stack.c
 * Author: Manjiri Chavande
 * Email: cmanjiri1912@gmail.com
 * Created: September 6, 2023
 * Description: This program implements a Stack ADT
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackUsingArray.c"

struct node
{
    char data;
    struct node *link;
};

// top pointer stores the address of node
struct node *top = 0;

void push()
{
    char x;
    printf("Enter the character you want to push\n");
    scanf("%c", &x);
    // creata a new node
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    // data
    newnode->data = x;
    // address
    newnode->link = top;
    top = newnode;
}

void display(){
    struct node *temp;
    temp = top;
    if(top == 0){
        printf("\nStack is empty!!!\n");
    }
    else{
        //trsversing the stack
        while (temp!=0)
        {
            printf("Stack:")
            printf("%c\n",temp->data);
            temp = temp->link;
        }
    }
}

void peek(){
    if(top==0){
        printf("\nstack is empty!!!\n");
    }
    else{
        printf("Top element:  %c\n",top->data);
    }
}

void pop(){
    struct node *temp;
    temp=top;
    //isFull
    if(top==NULL){
        printf("Underflow\n");
    }
    else{
        printf("\nPopped value: %c\n",top->data);
        top = top->link;
        free(temp);
    }
}

void reverse string(){
    
}


int main()
{
    int choice;

    do
    {
        printf("Enter the choice code\n 1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n=>");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Please select valid choice\n");
            break;
        }
    } while (choice != 5);
    return 0;
}
