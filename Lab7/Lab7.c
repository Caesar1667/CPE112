//Pansa Intawong 66070503474
//AVL Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
    int height;
} BTree;

int height(BTree *tree){
    if(tree == NULL){
        return 0;
    }
    return tree->height;
}

int max(int a, int b){
    return (a > b)? a : b; 
}

BTree *newNode(int data){
    BTree *node = (BTree*)malloc(sizeof(BTree));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

//left rotation : create 2 temp nodes
BTree *RotateLeft(BTree *tree){
//assign 1 as right node and other as left of the right node (keep up)
    BTree *temp1 = tree->right;
    BTree *temp2 = temp1->left;

//then swap left of the right node to ancestor node and right node as left of the right node
    temp1->left = tree;
    tree->right = temp2;

//update height accordingly and return
    tree->height = max(height(tree->left), height(tree->right) + 1);
    temp1->height = max(height(temp1->left), height(temp1->right) + 1);

    return temp1;
}

//right rotation : create 2 temp nodes
BTree *RotateRight(BTree *tree){
//assign 1 as left node and other as right of the left node
    BTree *temp1 = tree->left;
    BTree *temp2 = temp1->right;

//swap the right of left node with the ancestor node and the left node as the right of left node
    temp1->right = tree;
    tree->left = temp2;

//update height accodingly and return
    tree->height = max(height(tree->left), height(tree->right) + 1);    
    temp1->height = max(height(temp1->left), height(temp1->right) + 1);

    return temp1;
}

//check balance from height of left-child of said node subtract with height of right-child of said node.
int isBalanced(BTree *tree){
//if the child is NULL then the height is -1
    if(tree == NULL){
        return 0;
    }else{
        return height(tree->left) - height(tree->right);
    }
}


BTree* Insert(BTree *tree, int data){
    if(tree == NULL){
        return newNode(data);
    }

    if(data < tree->data){
        tree->left = Insert(tree->left, data);
    }else if(data > tree->data){
        tree->right = Insert(tree->right, data);
    }else{
        return tree;
    }
    //assigned height every Insert
    tree->height = 1 + max(height(tree->left), height(tree->right)); 

    //check balance factor is the node
    int balance = isBalanced(tree);

    //more than 1 and data is less than left -> rotate right
    if(balance > 1 && data < tree->left->data){
        return RotateRight(tree);
    }
    
    //more than 1 and data is more than left -> rotate right
    if(balance > 1 && data > tree->left->data){
        tree->left = RotateLeft(tree->left);
        return RotateRight(tree);
    }
    
    //less than -1 and data is more than right -> rotate left
    if(balance < -1 && data > tree->right->data){
        return RotateLeft(tree);
    }
    
    //less than -1 and data ia less than right -> rotate left
    if(balance < -1 && data < tree->right->data){
        tree->right = RotateRight(tree->right);
        return RotateLeft(tree);
    }
    return tree;
}

BTree *minValue(BTree *tree){
    BTree *current = tree;

    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

BTree *delete(BTree *tree, int data){
    if(tree == NULL){
        printf("Node not found.\n");
        return tree;
    }

    if(data < tree->data){
        tree->left = delete(tree->left, data);
    }else if(data > tree->data){
        tree->right = delete(tree->right, data);
    }else{
        if((tree->left == NULL) || (tree->right == NULL)){
            BTree *temp = tree->left ? tree->left : tree->right;

            if(temp == NULL){
                temp = tree;
                tree = NULL;
            }else{
                *tree = *temp;
                free(temp);
            }
        }else{
            BTree *temp = minValue(tree->right);
            tree->data = temp->data;

            tree->right = delete(tree->right, temp->data);
        }
    }

    if(tree == NULL){
        return tree;
    }

    tree->height = 1 + max(height(tree->left), height(tree->right));

    int balance = isBalanced(tree);

    if(balance > 1 && isBalanced(tree->left) >= 0){
        return RotateRight(tree);
    }

    if(balance > 1 && isBalanced(tree->left) < 0){
        tree->left = RotateLeft(tree->left);
        return RotateRight(tree);
    }

    if(balance < -1 && isBalanced(tree->right) <= 0){
        return RotateLeft(tree);
    }
    
    if(balance < -1 && isBalanced(tree->right) > 0){
        tree->left = RotateRight(tree->right);
        return RotateLeft(tree);
    }

    return tree;
}

void Preorder(BTree *tree){
    if(tree == NULL){
        printf("Tree is empty.");
        return;
    }
        printf("%d ", tree->data);
        if(tree->left != NULL){
            Preorder(tree->left);
        }
        if(tree->right != NULL){
            Preorder(tree->right);
        }
}


int main(){
    BTree *tree = NULL;
    int temp;
    char option[7];
    do{
        scanf("%s", option);
        if(strcmp(option, "INSERT") == 0){
            while(scanf("%d", &temp) == 1){
                tree = Insert(tree, temp);
            }
        }else if(strcmp(option, "DELETE") == 0){
            while(scanf("%d", &temp) == 1){
                tree = delete(tree, temp);
            }
        }else if(strcmp(option, "PRINT") == 0){
            Preorder(tree);
            printf("\n");
        }else if(strcmp(option, "EXIT") == 0){
            free(tree);
            break;
        }else{
            printf("Invalid command.\n");
            continue;
        }
    }while(strcmp(option, "EXIT") != 0);

    return 0;
}
