#include <stdio.h>
int fibonacciRecursion(int nthNum)
{
        //using recursion
    if (nthNum < 2)
    {

      return nthNum;

    }
    return fibonacciRecursion(nthNum - 1) + fibonacciRecursion(nthNum - 2);
}
int main(void)
{
  int n;
  printf("\n Enter number : ");
  scanf("%d",&n);
  printf("Number at %d th position in fibonacci is : %d\n",n,fibonacciRecursion(n));
  return 0;
}
