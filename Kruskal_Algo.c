// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comparator(const void *n1,const void *n2){
    int *a = (int*)n1;
    int *b = (int*)n2;
    return a[2] - b[2];
}

void makeSet(int parent[],int rank[],int numver_of_vertice){
    for(int i=0;i<numver_of_vertice;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[],int component){
    if(parent[component] != component){
        parent[component] = findParent(parent,parent[component]);
    }
    return parent[component];
}

void unionSet(int u,int v,int parent[],int rank[],int number_of_vertice){
    u = findParent(parent,u);
    v = findParent(parent,v);
    
    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}




void kruskalAlgo(int number_of_vertice,int number_of_edge,int edge[number_of_edge][3]){
    //Sogt edge
    qsort(edge,number_of_edge,sizeof(edge[0]),comparator);
    
    //intitial 
    int parent[number_of_vertice];
    int rank[number_of_vertice];
    int minCost = 0;
    makeSet(parent,rank,number_of_vertice);
    
    //Loop find the MST edges
    for(int i=0,count =0;i<number_of_edge && count < number_of_vertice -1;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];
        
        if(findParent(parent,u) != findParent(parent,v)){
            unionSet(u,v,parent,rank,number_of_vertice);
            minCost += wt;
            count++;
            printf("%d -- %d -> %d\n",u,v,wt);
        }
    }
    
    printf("Minimum spanning tree : %d",minCost);

}

int main() {
    //edge[edge][]
    int edge[5][3] = {
        {0,1,10},
         {0,2,6},
         {0,3,5},
         {1,3,15},
         {2,3,4}
    };
    
    int number_of_vertice = 4, number_of_edge = 5;
    kruskalAlgo(number_of_vertice,number_of_edge,edge);

    return 0;
}
