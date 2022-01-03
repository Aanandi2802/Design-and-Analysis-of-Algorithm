#include<stdio.h>

void knapSack(int W, int n, int val[], int wt[]);
int getMax(int x, int y);

int main(void) { 
  int n;  //total items
  int W;  //capacity of knapsack
  printf("\nEnter the total no. of Objects You Have : ");
  scanf("%d",&n);
  printf("Enter the Max. capacity of Knapsack : ");
  scanf("%d",&W);
  int val[n] ;
  val[0]=-1;
  int wt[n] ; 
  wt[0]=-1;
  //the first element is set to -1 as
  //we are storing item from index 1
  //in val[] and wt[] array
  
  printf("Enter weights of objects from 1 to %d : ",n);
  for (int i=1;i<n+1;i++)
    scanf("%d",&wt[i]);

  printf("Enter Values of objects from 1 to %d : ",n);
  for (int i=1;i<n+1;i++)
    scanf("%d",&val[i]);

  knapSack(W, n, val, wt);

  return 0;
}

int getMax(int x, int y) {
  if(x > y) {
    return x;
  } else {
    return y;
  }
}

void knapSack(int W, int n, int val[], int wt[]) {
  int i, w;

  //value table having n+1 rows and W+1 columns
  int V[n+1][W+1];

  //fill the row i=0 with value 0
  for(w = 0; w <= W; w++) {
    V[0][w] = 0;
  }

  //fille the column w=0 with value 0
  for(i = 0; i <= n; i++) {
    V[i][0] = 0;
  }

  //fill the value table
  for(i = 1; i <= n; i++) {
    for(w = 1; w <= W; w++) {
      if(wt[i] <= w) {
        V[i][w] = getMax(V[i-1][w], val[i] + V[i-1][w - wt[i]]);
      } else {
        V[i][w] = V[i-1][w];
      }
    }
  }

  //max value that can be put inside the knapsack
  printf("Max Value: %d\n\n", V[n][W]);
}