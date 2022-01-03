#include <stdio.h>   //quick-sort

//to swap position 
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

//to partition the array base on pivot element,
int partition(int array[], int low, int high) {
  
  // Selecting the pivot 
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // Selecting pivot position 
    // put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pi = partition(array, low, high);
    
    // Sort elements--> on left of pivot
    quickSort(array, low, pi - 1);
    
    // Sort elements--> on right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Function to print elements of an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int n; 
  
  printf("\nEnter No. of Digits in array : "); 
  scanf("%d",&n); 
  
  int arr[n]; 
  
  printf("\nEnter Digits : \n"); 
  for(int i=0;i<n;i++) 
  { scanf("%d",&arr[i]); }
  
  int a = sizeof(arr) / sizeof(arr[0]);
  
  quickSort(arr, 0, a - 1);
  
  printf("\nSorted array : \n");
  printArray(arr, a);
  printf("\n");
}