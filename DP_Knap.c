#include <stdio.h>

struct Item {
    int id;
    int value;
    int weight;
};

int max(int a,int b){
    if(a<b){
        return b;
    }
    return a;
}

int main(){
    int n,W;
    
    printf("Enter n,W: ");
    scanf("%d",&n);
    scanf("%d",&W);
    
    struct Item arrItem[n];
    
    for(int i=0;i<n;i++){
        arrItem[i].id = i+1;
        printf("Enter value & weight of item %d: ",i+1);
        scanf("%d",&arrItem[i].value);
        scanf("%d",&arrItem[i].weight);
    }
    
    // for(int i=0;i<n;i++){
    //     arrItem[i].id = i+1;
    //     printf("%d %d %d\n",arrItem[i].id,arrItem[i].value,arrItem[i].weight);
        
    // }
    
    int k[n+1][W+1];
    
    for(int i=0;i<=n; i++){
        for(int w=0;w<=W;w++){          
            if(i == 0 || w == 0){
                k[i][w] = 0;
            }else if(arrItem[i-1].weight <= w){
                k[i][w] = max(arrItem[i-1].value+k[i-1][w-arrItem[i-1].weight],k[i-1][w]);
            }else{
                k[i][w] = k[i-1][w];
            }
        }
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            printf("%d ", k[i][j]);
        }
        printf("\n");
    }
    

}
