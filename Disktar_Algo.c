#include <stdio.h>
#include <stdbool.h>
#define INF 9999

#define V 5

int minIndex(int key[],bool mstSet[]){
    int min = INF,min_index = -1;
    for(int i=0;i<V;i++){
        if(mstSet[i] == false && key[i] < min){
             min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[],int d[]){
    printf("Edge\t Weight\t \n ");
    for(int i=1;i<V;i++){
        printf("%d -- %d -> %d\n",parent[i],i,d[i]);
    }
}

void primMST(int graph[V][V]){
    // initial 
    int parent[V];
    int key[V];
    bool mstSet[V];
    for(int i=0;i<V;i++){
        key[i] = INF;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    
    for(int i=0;i<V;i++){
        int u = minIndex(key,mstSet);
        if(u == -1){
            printf("not vertice to process");
        }
        mstSet[u] = true;
        for(int v=0;v<V;v++){
            if(graph[u][v] && mstSet[v] == false && key[u]+ graph[u][v] < key[v]){
                key[v] = graph[u][v] + key[u];
                parent[v] = u;
            }
        }
    }
     printMST(parent,key);
}


int main() {
   int graph[V][V] = {
        { 0, 1, 4, 6, 1 }, // Node A (0) connections
        { 1, 0, 0, 2, 0 }, // Node B (1) connections
        { 4, 0, 0, 0, 1 }, // Node C (2) connections
        { 6, 2, 0, 0, 5 }, // Node D (3) connections
        { 1, 0, 1, 5, 0 } // Node E (4) connections
   };
   
   primMST(graph);

    return 0;
}
