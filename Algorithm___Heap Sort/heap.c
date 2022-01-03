
  #include <stdio.h>
  
  //to swap the the position of two elements--used this in quick
  void swap(int *a, int *b) 
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i) {
    // Find largest from root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  //algo - heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element --- to get highest element at root again
      heapify(arr, i, 0);
    }
  }
  
  // Print 
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
 
  int main() 
  {
    int n; 
  
    printf("\nEnter No. of Digits in array : "); 
    scanf("%d",&n); 
  
    int arr[n]; 
  
    printf("\nEnter Digits : \n"); 
    for(int i=0;i<n;i++) 
    { scanf("%d",&arr[i]); }
    
    int a = sizeof(arr) / sizeof(arr[0]);
  
    heapSort(arr, a);
  
    printf("\nSorted array is :\n");
    printArray(arr, a);
     printf("\n");
  }