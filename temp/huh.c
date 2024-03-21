#include <stdio.h>
#include <stdlib.h>

struct node{
    int node_value;
    struct node* left;
    struct node* right;
};

struct node* newNode(int node_value){
    struct node *tree = (struct node*)malloc(sizeof(struct node));

    tree->node_value = node_value;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

struct node* smallest(struct node* l){
    struct node *temp = l;

    if(temp->left != NULL){
        temp = smallest(temp->left);
    }

    return temp;
}

struct node* insert(struct node* tree, int node_value){
    if(tree == NULL){
        tree = newNode(node_value);
        return tree;
    }

    if(node_value < tree->node_value){
        tree->left = insert(tree->left, node_value);
    }else{
        tree->right = insert(tree->right, node_value);
    }

    return tree;
}

int main(){
    struct node *tree = NULL;
    struct node *small = NULL;
    tree = insert(tree, 6);
    tree = insert(tree, 7);
    tree = insert(tree, 8);
    tree = insert(tree, 9);
    tree = insert(tree, 10);

    small = smallest(tree);
    printf("%d ", small->node_value);
    return 0;
}
