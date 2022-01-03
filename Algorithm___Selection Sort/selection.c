# include <stdio.h>

//fn to swap values at givn index
void swap(int arr[], int firstIndex, int secondIndex) 
{   
    int temp;
    temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
}

// fn to find smallest in subarray
int indexOfMinimum(int arr[], int startIndex, int n) 
{
    int minValue = arr[startIndex];
    int minIndex = startIndex;

    for(int i = minIndex + 1; i < n; i++) {
        if(arr[i] < minValue) 
        {
            minIndex = i;
            minValue = arr[i];
        }
    } 
    return minIndex;
}
//selection sort
void selectionSort(int arr[], int n) 
{
    for(int i = 0; i < n; i++) 
    {
        int index = indexOfMinimum(arr, i, n);
        swap(arr, i, index);
    }
    
}
//printing o/p
void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }
}

int main()
{   
    int i;
    printf("Enter number of elements : ");
    scanf("%d",&i);
    int arr[i];
    printf("Enter %d elements : \n",i);
    for(int j=0;j<i;j++)
    {scanf("%d",&arr[j]);}
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array : \n");
    printArray(arr, n);
    return 0;
}
