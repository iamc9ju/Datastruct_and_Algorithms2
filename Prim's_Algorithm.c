#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index = -1;
    for(int v = 0; v < V; v++) {
        if(mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for(int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int v = 0; v < V; v++) {
        key[v] = INT_MAX;
        mstSet[v] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1; count++) {
        int u = minKey(key, mstSet);
        if(u == -1) {
            printf("No more vertices to process!\n");
            break;
        }
        mstSet[u] = true;

        for(int v = 0; v < V; v++) {
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main(void) {
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
