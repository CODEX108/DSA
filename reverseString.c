/*
 * File: reverseString.c
 * Author: Manjiri Chavande
 * Email: cmanjiri1912@gmail.com
 * Created: September 6, 2023
 * Description: Reversing a string
 */

// reverse_a_string.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stacks.c"

// Function to reverse a string using the stack
void reverse_string(char *msg){
    struct Stack *stack = initialize_stack(strlen(msg));

    // Push each character of the string onto the stack
    for (int i = 0; i < strlen(msg); i++){
        push(stack, msg[i]);
    }

    printf("Reversed String: ");
    // Pop and print each character to reverse the string
    while (!isEmpty_stack(stack)){
        printf("%c", pop(stack));
    }
    printf("\n");
}

int main(){
   reverse_string("SPIT Comps");
   return 0;
}