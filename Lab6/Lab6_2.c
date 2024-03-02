//Pansa Intawong 66070503474
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
} BTree;

BTree *newNode(int data){
    BTree *node = (BTree*)malloc(sizeof(BTree));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

BTree* Insert(BTree *tree, int data){
    if(tree == NULL){
        tree = newNode(data);
        return tree;
    }

    if(data < tree->data){
        tree->left = Insert(tree->left, data);
    }else{
        tree->right = Insert(tree->right, data);
    }

    return tree;
}

void Preorder(BTree *tree){
    if(tree != NULL){
        printf("%d ", tree->data);
        Preorder(tree->left);
        Preorder(tree->right);
    }
}

void Inorder(BTree *tree){
    if(tree != NULL){
        Inorder(tree->left);
        printf("%d ", tree->data);
        Inorder(tree->right);
    }
}

void Postorder(BTree *tree){
    if(tree != NULL){
        Postorder(tree->left);
        Postorder(tree->right);
        printf("%d ", tree->data);
    }
}

int main(){
    BTree *tree = NULL;

    char option[10];
    do{
        scanf("%s", option);
        if(strcmp(option, "INS") == 0){
            int temp;
            scanf("%d", &temp);
            tree = Insert(tree, temp);
        }else if(strcmp(option, "PREORDER") == 0){
            Preorder(tree);
            printf("\n");
        }else if(strcmp(option, "INORDER") == 0){
            Inorder(tree);
            printf("\n");
        }else if(strcmp(option, "POSTORDER") == 0){
            Postorder(tree);
            printf("\n");
        }else if(strcmp(option, "END") == 0){
            Inorder(tree);
            printf("\n");
            break;
        }else{
            continue; //do nothing... just loop again.
        }
    }while(strcmp(option, "END") != 0);
    
    return 0;
}