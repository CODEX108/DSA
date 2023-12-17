
// Create an AVLNode ADT and complete the following functions:
// 1. createNode
// 2. displayAVLTree
// 3. getHeight
// 4. rotateRight
// 5. rotateLeft
// 6. getBalance
// 7. delete
// 8. freeAVLTree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLNode
{
    char *data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

AVLNode *createNode(char *data)
{
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

void printInorder(AVLNode *r) //  (Left, current node, Right)
{
    if (r == NULL)
        return;
    /* first recur on left child */
    printInorder(r->left);
    /* then print the data of node */
    printf("%s ", r->data);
    /* now recur on right child */
    printInorder(r->right);
}

int getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLNode *rotateRight(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

AVLNode *rotateLeft(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

AVLNode *insert(AVLNode *node, char *data)
{
    if (node == NULL)
    {
        return createNode(data);
    }

    if (strcmp(data, node->data) < 0)
    {
        node->left = insert(node->left, data);
    }
    else if (strcmp(data, node->data) > 0)
    {
        node->right = insert(node->right, data);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balfac = getBalance(node);

    if (balfac > 1 && strcmp(data, node->left->data) < 0)
    {
        return rotateRight(node);
    }

    if (balfac < -1 && strcmp(data, node->right->data) > 0)
    {
        return rotateLeft(node);
    }

    if (balfac < -1 && strcmp(data, node->right->data) < 0)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    if (balfac > 1 && strcmp(data, node->left->data) > 0)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    return node;
}

AVLNode *minValueNode(AVLNode *node)
{
    AVLNode *current = node;
    // loop down to find the leftmost node
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void deleteNode(AVLNode **root, char *data) {
    if (*root == NULL)
        return;

    if (strcmp(data, (*root)->data) < 0)
        deleteNode(&((*root)->left), data);
    else if (strcmp(data, (*root)->data) > 0)
        deleteNode(&((*root)->right), data);
    else {
        if (((*root)->left == NULL) || ((*root)->right == NULL)) {
            AVLNode *temp = (*root)->left ? (*root)->left : (*root)->right;
            if (temp == NULL) {
                temp = *root;
                *root = NULL;
            } else
                **root = *temp;
            free(temp->data);
            free(temp);
        } else {
            AVLNode *temp = minValueNode((*root)->right);
            free((*root)->data);
            (*root)->data = strdup(temp->data);
            deleteNode(&((*root)->right), temp->data);
        }
    }

    if (*root == NULL)
        return;

    (*root)->height = 1 + max(getHeight((*root)->left), getHeight((*root)->right));
    int balance = getBalance(*root);
    if (balance > 1 && getBalance((*root)->left) >= 0)
        *root = rotateRight(*root);
    if (balance > 1 && getBalance((*root)->left) < 0) {
        (*root)->left = rotateLeft((*root)->left);
        *root = rotateRight(*root);
    }
    if (balance < -1 && getBalance((*root)->right) <= 0)
        *root = rotateLeft(*root);
    if (balance < -1 && getBalance((*root)->right) > 0) {
        (*root)->right = rotateRight((*root)->right);
        *root = rotateLeft(*root);
    }
}

// This function should handle freeing the memory used by the AVL tree
void freeAVLTree(AVLNode *root)
{
    if (root == NULL)
        return;
    freeAVLTree(root->left);
    freeAVLTree(root->right);
    free(root->data);
    free(root);
}

int main()
{
    //H, I, J, B, A, E, C, F, D, G, K, L
    struct AVLNode *root = NULL;
    root = insert(root, "h");
    root = insert(root, "i");
    root = insert(root, "j");
    root = insert(root, "b");
    root = insert(root, "a");
    root = insert(root, "e");
    root = insert(root, "c");
    root = insert(root, "f");
    root = insert(root, "d");
    root = insert(root, "g");
    root = insert(root, "k");
    root = insert(root, "l");



    deleteNode(&root, "i");
 printInorder(root);
    deleteNode(&root, "b");
    printf("\n");
    printInorder(root);
    freeAVLTree(root);
    return 0;
}
