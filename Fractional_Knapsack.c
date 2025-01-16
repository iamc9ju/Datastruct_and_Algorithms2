#include <stdio.h>

typedef struct {
  int value;
  double weight;
  double ratio;
} Item;

int partition(Item items[],int low,int high){
  double pivot = items[high].ratio;
  int i = (low - 1);
  for(int j = low ; j<high;j++){
    if(items[j].ratio >= pivot){
      i++;
      Item temp = items[j];
      items[j] = items[i];
      items[i] = temp; 
    }
  }
  
  Item temp = items[i+1];
  items[i+1] = items[high];
  items[high] = temp;

  return i+1;
}

void quickSort(Item items[], int low, int high) {
  if(low < high){
    // BASE CASE
    int pi = partition(items, low, high);
    quickSort(items,low,pi-1);
    quickSort(items,pi+1,high);
  }
  
}

int fractionalKnapsack(Item items[], int n, double maxWeight) {
  // หาอัตราส่วนก่อน
  for(int i=0;i<n;i++){
    items[i].ratio = items[i].value / items[i].weight;
  }

  printf("\nRatio : ");
  for(int i=0;i<n;i++){
    printf("%lf ",items[i].ratio);
  }

  printf("\n \n");
  
  // SORT MAX TO MIN
  quickSort(items, 0, n-1);

  double totalValue = 0.0;
  for(int i=0;i<n;i++){
    if(maxWeight >= items[i].weight){
      totalValue += items[i].value;
      maxWeight -= items[i].weight;
    }else{
      totalValue += items[i].value * (maxWeight / items[i].weight);
    }
  }
  return totalValue;
}



int main() {
  int n;
  double maxWeight;

  printf("จำนวน : ");
  scanf("%d", &n);
  printf("น้ำหนักสูงสุด : ");
  scanf("%lf", &maxWeight);

  Item items[n];
  for (int i = 0; i < n; i++) {
    printf("ชิ้นที่ %d", i + 1);
    printf("ราคา : ");
    scanf("%d", &items[i].value);
    printf("น้ำหนัก : ");
    scanf("%lf", &items[i].weight);
  }

  double maxValue = fractionalKnapsack(items, n, maxWeight);

  printf("อัตราส่วนหลังจาก Quicksort : ");
  for (int i = 0; i < n; i++) {
    printf("%lf ",items[i].ratio);
  }

  printf("Max Value: %lf\n", maxValue);
}
