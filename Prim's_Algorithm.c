#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6

int minIndex(int key[],bool mstSet[]){
    int min = INT_MAX,min_index = -1;
    for(int i =0;i<V;i++){
        if(mstSet[i] == false && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    
    return min_index;
}

void printMST(int parent[],int graph[V][V]){
    printf("Edge \tWeight\t\n");
    for(int i=1;i<V;i++){
        printf("%d - %d\t %d\n",parent[i],i,graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V]){
    //initial 
    int parent[V];
    int key[V];
    bool mstSet[V];
    
    for(int i=0;i<V;i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    
    for(int i=0;i<V;i++){
        int u = minIndex(key,mstSet);
        if(u == -1){
            printf("No more vertices to process!\n");
        }
        mstSet[u] = true;
        for(int i=0;i<V;i++){
            if(graph[u][i] && mstSet[i] == false && graph[u][i] < key[i]){
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    };
    printMST(parent,graph);
}

int main() {
   //set graph
   int graph[V][V] = {
        {0, 2, 0, 0, 0, 4},
        {2, 0, 8, 0, 0, 3},
        {0, 8, 0, 6, 1, 0},
        {0, 0, 6, 0, 12, 0},
        {0, 0, 1, 12, 0, 2},
        {4, 3, 0, 0, 2, 0}
   };
   
  primMST(graph);

    return 0;
}
