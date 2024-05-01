//Pansa Intawong 66070503474
#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2){
    const int(*x)[3] = p1;
    const int(*y)[3] = p2;

    return (*x)[2] - (*y)[2];
}

void makeSet(int parent[], int rank[], int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component){
     if(parent[component] == component)
        return parent[component];
    
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[], int n){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[u] > rank[v]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

void Kruskal(int n, int edge[n][3]){
    qsort(edge, n, sizeof(edge[0]), comparator);

    int parent[n];
    int rank[n];

    makeSet(parent, rank, n);

    int minCost = 0;

    for(int i = 0; i < n; i++){
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];
        
        if(v1 != v2){
            unionSet(v1, v2, parent, rank, n);
            minCost += wt;
        }
    }

    printf("%d", minCost);
}

int isMST(int vertices_num, int edges_num, int mat[edges_num][3]){

    int count_edges = 0;
    for (int i = 0; i < edges_num; i++) {
        if (mat[i][0] != mat[i][1])
            count_edges++;
    }

    if (count_edges == vertices_num - 1)
        return 1; 
    else
        return 0;
}


int main(){
    int vertices_num, edges_num;
    scanf("%d%d", &vertices_num, &edges_num);
    int mat[edges_num][3];

    for(int i = 0; i < edges_num; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    if (isMST(vertices_num, edges_num, mat)) {
        int total_weight = 0;
        for (int i = 0; i < edges_num; i++) {
            total_weight += mat[i][2];
        }
        printf("%d", total_weight);
    } else {
        Kruskal(edges_num, mat);
    }

    return 0;
}