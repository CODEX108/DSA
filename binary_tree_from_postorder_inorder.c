/*
Manjiri Chavande
UID: 2023301003
Comps B batch A
*/
// Given two integer arrays postorder and inorder 
// where postorder is the postorder traversal of a binary tree and 
// inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Input: postorder = [9,15,7,20,3], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

#include <stdlib.h>
#include <stdio.h>

  struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* create_node(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the position in the inorder array
int findPosition(int in[], int inorderStart, int inorderEnd, int element, int n) {
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (in[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to build the binary tree
struct TreeNode* solve(int in[], int post[], int *postorderIndex, int inorderStart, int inorderEnd, int n) {
    if (*postorderIndex < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = post[(*postorderIndex)--];
    struct TreeNode* root = create_node(element);
    int position = findPosition(in, inorderStart, inorderEnd, element, n);

    // In case of inorder and postorder, we first build the right sub-tree
    root->right = solve(in, post, postorderIndex, position + 1, inorderEnd, n);
    root->left = solve(in, post, postorderIndex, inorderStart, position - 1, n);

    return root;
}

// Wrapper function to call the helper function
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postorderIndex = postorderSize - 1;  // Start from the last index of postorder
    return solve(inorder, postorder, &postorderIndex, 0, inorderSize - 1, inorderSize);
}

// Function to print the preorder traversal
void printBinTree(struct TreeNode* node) {
    if (node == NULL) {
        printf("null ");
        return;
    }
    printf("%d ", node->val);
    printBinTree(node->left);
    printBinTree(node->right);
}

int main() {
    // Given input arrays
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int inorderSize = 5;
    int postorderSize = 5;

    // Construct the binary tree
    struct TreeNode* root = buildTree(inorder, inorderSize, postorder, postorderSize);


    printf("Constructed Binary Tree: ");
    printBinTree(root);
    printf("\n");


    return 0;
}

