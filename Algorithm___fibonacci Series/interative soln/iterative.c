#include <stdio.h>
int fibonacciIterative(int nthNum) {
        //use loop
        int ppnum, pnum = 0, currentNum = 1;
        if(nthNum==0){return 0;}
        for (int i = 1; i < nthNum ; i++) {

            ppnum = pnum;

            pnum = currentNum;

            currentNum = ppnum + pnum;

        }
        return currentNum;
}
int main(void) 
{
  int n;
  printf("\n Enter number : ");
  scanf("%d",&n);
  printf("Number at %dth position in fibonacci is : %d\n",n,fibonacciIterative(n));
  
  return 0;
}