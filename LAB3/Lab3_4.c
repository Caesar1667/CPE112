//Pansa Intawong 66070503474
//Doubly Linked List Operation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} nodes;

void append(nodes **head, int data){
    nodes *new_node = (nodes*)malloc(sizeof(nodes));

    nodes *last = *head;

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL){
        *head = new_node;
        free(last);
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;

}

void deleteSelected(nodes **head, int val){
    if(*head == NULL){
        return;
    }

    nodes *new_node = *head;
    nodes *temp = NULL;

    if(new_node->data == val){
        *head = new_node->next;
        if(new_node->next != NULL){
            new_node->next->prev = NULL;
        }
        return;
    }

    while(new_node != NULL && new_node->data != val){
        temp = new_node;
        new_node = new_node->next;
    }

    if(new_node != NULL){
        temp->next = new_node->next;
        if(new_node->next != NULL){
            new_node->next->prev = temp;
        }
    }
}

void neighbor(nodes **head, int val){
    if(*head == NULL){
        // printf("none\n");
        return;
    }

    nodes *new_node = *head;
    
    while(new_node->next != NULL && new_node->data != val){
        new_node = new_node->next;
    }

    if(new_node == NULL){
        printf("none\n");
        return;
    }

    if(new_node->data != val){
        printf("none\n");
        return;
    }

    if(new_node->prev != NULL){
        printf("%d ", new_node->prev->data);
    }else{
        printf("NULL ");
    }

    if(new_node->next != NULL){
        printf("%d \n", new_node->next->data);
    }else{
        printf("NULL\n");
    }
}

void reverse(nodes **head){
    if(*head == NULL){
        return;
    }

    nodes *temp = NULL;
    nodes *new_node = *head;

    while(new_node != NULL){
        temp = new_node->prev;
        new_node->prev = new_node->next;
        new_node->next = temp;
        new_node = new_node->prev;
    }

    if(temp != NULL){
        *head = temp->prev;
    }
}

void printList(nodes *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    char func[3];
    int val = 4;
    nodes *list = NULL;
    // for(int i = 0; i < 5; i++){
    //     int temp;
    //     scanf("%d", &temp);
    //     append(&list, temp);
    // }
    // neighbor(&list, val);
    // deleteSelected(&list, val);
    do{
        scanf("%s", func);
        if(strcmp(func, "END") != 0){
            scanf("%d", &val);
        }
        if(strcmp(func, "ADD") == 0){
            append(&list, val);
        }else if(strcmp(func, "DEL") == 0){
            deleteSelected(&list, val);
        }else if(strcmp(func, "SCH") == 0){
            neighbor(&list, val);
        }
    }while(strcmp(func, "END") != 0);
    // if(list == NULL){
    //     printf("none");
    // }else{
    //     printList(list);
    // }
    // printf("\n");
    // reverse(&list);
    if(list == NULL){
        printf("none\nnone");
    }else{
        printList(list);
        printf("\n");
        reverse(&list);
        printList(list);
    }
    return 0;
}