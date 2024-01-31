//Pansa Intawong 66070503474
//Calculate Mean and Standard Deviation
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Student{
    char name[100];
    float score;
};

struct Statistics{
    float min, max, mean, standard_deviation;
    char min_name[100], max_name[100];
};

float calculateSD(struct Student score[],int size, struct Statistics stats){
    float standard_deviation = 0.0f;
    for(int i = 0; i < size; i++){
        standard_deviation += pow(score[i].score - stats.mean, 2);
    }
    return sqrt(standard_deviation / size);
}

int main(){
    int size;
    struct Statistics stats = {100.0f, 0.0f, 0.0f, 0.0f};
    scanf("%d", &size);
    struct Student student[size];
    for(int i = 0; i < size; i++){
        scanf("%s %f", student[i].name, &student[i].score);
        stats.mean += student[i].score;
    }
    stats.mean /= size;
    stats.standard_deviation = calculateSD(student, size, stats);
    //find Minimum and Maximum
    int min_flag, max_flag;
    for(int i = 0; i < size; i++){
        if(student[i].score < stats.min){
            stats.min = student[i].score;
            strcpy(stats.min_name, student[i].name);
            min_flag = 1;
        }
        if(!min_flag) strcpy(stats.min_name, student[0].name);
        if(student[i].score > stats.max){
            stats.max = student[i].score;
            strcpy(stats.max_name, student[i].name);
            max_flag = 1;
        }
        if(!max_flag) strcpy(stats.max_name, student[0].name);
    }
    printf("%.2f %.2f %s %s", stats.mean, stats.standard_deviation, stats.max_name, stats.min_name);
    return 0;
}