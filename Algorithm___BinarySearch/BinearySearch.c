#include <stdio.h> 
  
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        
        if (arr[mid] == x) 
            return mid; 
   
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
} 
  
int main(void) 
{   
    printf("\n-----------Binary Search Example-----------\n");
    int arr[] = { 1, 2, 3, 50, 60, 81, 4, 123, 51, 40, 86 };
    printf("Array : ");
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<n;i++) 
    printf("%d, ",arr[i]);
    printf("\nEnter element : "); 
    int x;
    scanf("%d",&x); 
    int result = binarySearch(arr, 0, n - 1, x); 
    (result == -1) ? printf("Element is not present in array\n") : printf("Element is present at index : %d\n", result);
    
    printf("\n"); 
    return 0; 
} 