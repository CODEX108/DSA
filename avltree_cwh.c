#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLNode {
    char* data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

AVLNode* createNode(char* data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->data = strdup(data);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

void displayAVLTree(AVLNode* root) {
    if (root != NULL) {
        printf("%s ", root->data);
        displayAVLTree(root->left);
        displayAVLTree(root->right);
    }
}

int getHeight(AVLNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(AVLNode* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

AVLNode* insert(AVLNode* node, char* data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (strcmp(data, node->data) < 0) {
        node->left = insert(node->left, data);
    } else if (strcmp(data, node->data) > 0) {
        node->right = insert(node->right, data);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balfac = getBalance(node);

    if (balfac > 1 && strcmp(data, node->left->data) < 0) {
        return rotateRight(node);
    }

    if (balfac < -1 && strcmp(data, node->right->data) > 0) {
        return rotateLeft(node);
    }

    if (balfac < -1 && strcmp(data, node->right->data) < 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    if (balfac > 1 && strcmp(data, node->left->data) > 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    return node;
}


struct AVLNode* inorderPredecessor(struct AVLNode * root){
    root = root->left;
    //reach the greatest elem in the left subree
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// This function should handle deletion from the AVL tree
struct AVLNode *  deleteNode(AVLNode* root, char* data) {
    struct AVLNode * iPre;
    if(root= NULL)
        return NULL;
    
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    

   //search for the node to be deleted
    if(data < root->data){
      root->left =  deleteNode(root->left,data);
    }else if (data > root->data)
    {
       root->right = deleteNode(root->right,data);
    }
    /*
        b
       / \ 
      a   d
        / \
       c   f
    */
    //DELETION STRAGEGY when the node is found
    else{
        //findin the inorder predecessor
        iPre = inorderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left,iPre->data);
    }
    return root;
}

// This function should handle freeing the memory used by the AVL tree
void freeAVLTree(AVLNode* root) {
    if (root == NULL) return;
    freeAVLTree(root->left);
    freeAVLTree(root->right);
    free(root->data);
    free(root);
}

int main() {
    struct AVLNode* root = NULL;
    root = insert(root, "a");
    root = insert(root, "b");
    root = insert(root, "d");
    root = insert(root, "c");
    root = insert(root, "f");

    displayAVLTree(root);
    freeAVLTree(root);
    deleteNode(root,"f");
    displayAVLTree(root);

    return 0;
}
