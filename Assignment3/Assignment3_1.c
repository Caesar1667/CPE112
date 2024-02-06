//Pansa Intawong 66070503474
//Sort Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int ID;
    int score;
    struct node *next;
} nodes;

void append(nodes **head, int ID, int score){
    nodes *new_node = (nodes*)malloc(sizeof(nodes));

    new_node->ID = ID;
    new_node->score = score;

    nodes *last = *head;

    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

void sortScore(nodes **head){
    nodes *current = *head;
    nodes *index = NULL;
    int tempScore, tempID;

    while(current != NULL && current->next != NULL){
        index = current->next;
        while(index != NULL){
            if(current->score > index->score){
                tempID = current->ID;
                tempScore = current->score;
                current->ID = index->ID;
                current->score = index->score;
                index->ID = tempID;
                index->score = tempScore;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void sortID(nodes **head){
    nodes *current = *head;
    nodes *index = NULL;
    int tempScore, tempID;

    while(current != NULL && current->next != NULL){
        index = current->next;
        while(index != NULL){
            if(current->ID > index->ID){
                tempID = current->ID;
                tempScore = current->score;
                current->ID = index->ID;
                current->score = index->score;
                index->ID = tempID;
                index->score = tempScore;
            }
            index = index->next;
        }
        current = current->next;
    }
}
void printList(nodes *head){
    while(head != NULL){
        printf("%d ", head->score);
        head = head->next;
    }
}

int main(){
    nodes *student = NULL;
    int size, mode;
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        int tempScore, tempID;
        scanf("%d%d", &tempID, &tempScore);
        append(&student, tempID, tempScore);
    }
    scanf("%d", &mode);
    // sortID(&student);
    if(mode){
        sortScore(&student);
    }else if(!mode){
        sortID(&student);
    }
    printList(student);
    return 0;
}