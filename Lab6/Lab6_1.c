//Pansa Intawong 66070503474
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
    int *data;
    int node;
};

void Root(struct tree *Tree, int val){
    int index = 1;
    if(Tree->data[index] != -999){
        printf("cannot create duplicated root\n");
    }else{
        Tree->data[index] = val;
        index++;
    }
}

void Ins_Left(struct tree *Tree, int parent, int val){
    int i = 1, flag = 0;
    while(i <= Tree->node){
        if(Tree->data[i] == parent){
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0){
        printf("not found\n");//not found
    }else if(i * 2 > Tree->node){
        printf("overflow\n");
    }else if(Tree->data[2*i] != -999){
        printf("node already presented\n");
    }else if(Tree->data[2*i] == -999){
        Tree->data[2 * i] = val;
    }

}

void Ins_Right(struct tree *Tree, int parent, int val){
    int i = 1, flag = 0;
    while(i <= Tree->node){
        if(Tree->data[i] == parent){
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0){
        printf("not found\n");//not found
    }else if(2*i + 1 > Tree->node){
        printf("overflow\n");
    }else if(Tree->data[2*i + 1] == -999){
        Tree->data[(2*i) + 1] = val;
    }else if(Tree->data[2*i + 1] != -999){
        printf("node already presented\n");
    }
}

void END(struct tree Tree){
    for(int i = 1; i <= Tree.node; i++){
        if(Tree.data[i] == -999){
            printf("null ");
        }else{
            printf("%d ", Tree.data[i]);
        }
    }
}

int main(){
    struct tree Tree;
    scanf("%d", &Tree.node);
    Tree.data = (int*)malloc((Tree.node + 1) * sizeof(int));
    
    for(int i = 0; i <= Tree.node; i++){
        Tree.data[i] = -999; // init to -999 as in NULL
    }
    char mode[5];
    do
    {
        scanf("%s", mode);
        if(strcmp(mode, "ROOT") == 0){
            int val;
            scanf("%d", &val);
            Root(&Tree, val);
        }else if(strcmp(mode, "INSL") == 0){
            int par, val;
            scanf("%d%d", &par, &val);
            Ins_Left(&Tree, par, val);
        }else if(strcmp(mode, "INSR") == 0){
            int par, val;
            scanf("%d%d", &par, &val);
            Ins_Right(&Tree, par, val);
        }else if(strcmp(mode, "END") == 0){
            END(Tree);
            break;
        }else{
            continue;//do nothing...
        }
    } while (strcmp(mode, "END") != 0);
    
    return 0;
}