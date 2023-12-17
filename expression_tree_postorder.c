/*
 * File: expression_tree_postorder.c
 * Author: Manjiri Chavande 
 * Email: manjiri.chavande23@spit.ac.in
 * Created: October 27, 2023
 * Description: Create an expression tree from a postorder traversal. 
 *  Additionally, add function to evaluate a given expression tree
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.c"


// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform an operation on 2 operands
float perform_operation(char op, float left, float right){
    switch (op) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            case '/':
                if (right != 0) {
                    return left / right;
                } else {
                    fprintf(stderr, "Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
            default:
                fprintf(stderr, "Error: Unknown operator %c\n", op);
                exit(EXIT_FAILURE);
        }
}


// Create a new expression tree node
ExprTreeNode *create_node(OpType op_type, Data data) {
    ExprTreeNode *node = (ExprTreeNode *)malloc(sizeof(ExprTreeNode));
    node->type = op_type;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create an expression tree from a postfix expression
ExprTreeNode *create_ET_from_postfix(char *postfix_expression) {
    Stack *stack = initialize_stack(10); // Adjust the size as needed

    int len = strlen(postfix_expression);
    for (int i = 0; i < len; i++) {
        if (postfix_expression[i] == ' ') {
            continue;  // Skip spaces
        } else if (isOperator(postfix_expression[i])) {
            Data data;
            data.operation = postfix_expression[i];
            ExprTreeNode *node = create_node(OPERATOR, data);
            node->right = pop(stack);
            node->left = pop(stack);
            push(stack, node);
            display(stack);
        } else {
            // Assuming the operand is a single-digit
            float operand_value = (float)(postfix_expression[i] - '0');
            Data data;
            data.operand = operand_value;
            ExprTreeNode *node = create_node(OPERAND, data);
            push(stack, node);
            display(stack);
        }
    }

    if (!isEmpty(stack)) {
        ExprTreeNode *root = pop(stack);
        return root;
    } else {
        fprintf(stderr, "Error: Empty expression\n");
        return NULL;
    }
}

// Evaluate the expression tree
float evaluate_ET(ExprTreeNode *root) {
    if (root->type == OPERAND) {
        return root->data.operand;
    } else {
        float left_value = evaluate_ET(root->left);
        float right_value = evaluate_ET(root->right);
        return perform_operation(root->data.operation, left_value, right_value);
    }
}

int main() {
    char postfix_expression_1[] = "34+2*";
    char postfix_expression_2[] = "62/5*84/-";
    char postfix_expression_3[] = "2 3 1 * + 9 -";

    
    // Test expression 1
    printf("Postfix expression 1: %s\n", postfix_expression_1);
    ExprTreeNode *root1 = create_ET_from_postfix(postfix_expression_1);
    if (root1 != NULL) {
        printf("Result of expression 1: %.2f\n", evaluate_ET(root1));
    }
    printf("\n");

    // Test expression 2
    printf("Postfix expression 2: %s\n", postfix_expression_2);
    ExprTreeNode *root2 = create_ET_from_postfix(postfix_expression_2);
    if (root2 != NULL) {
        printf("Result of expression 2: %.2f\n", evaluate_ET(root2));
    }

    printf("Postfix expression 3: %s\n", postfix_expression_3);
    ExprTreeNode *root3 = create_ET_from_postfix(postfix_expression_3);
    if (root3 != NULL) {
        printf("Result of expression 3: %.2f\n", evaluate_ET(root3));
    }

    return 0;
}