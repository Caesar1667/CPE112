//Pansa Intawong 66070503474
//Dictionary
#include<stdio.h>
#include<string.h> //hint

struct dict{
	char value[100];
	char key[100];
};

void editdict(struct dict *dic,int size, char *key, char *value){ //for editing the dictionary
    int change = 0;
    for(int i = 0; i < size; i++){
        if(strcmp(dic[i].key, key) == 0){
            strcpy(dic[i].value, value);
            change = 1;
        }
    }
    if(!change){
        printf("No change\n");
    }
}

void printdict(struct dict *dic, int size){ //for printing the output
	for(int i=0; i<size ; i++){
		printf("%s : %s\n",dic[i].key,dic[i].value);
	}
}

int main(){
	int size;
	scanf("%d",&size);
	struct dict dic[size]; //you can do this to declare structure in the array
    for(int i = 0; i < size; i++){
        scanf("%s %s", dic[i].key, dic[i].value);
    }
    char keyChange[100], valueChange[100];
    scanf("%s %s", keyChange, valueChange);
    editdict(dic, size, keyChange, valueChange);
    printdict(dic, size);

	//write your code here
}