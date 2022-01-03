#include<stdio.h>
void TOH(int n,char x,char y,char z)
{
  if(n>0)
  {
    TOH(n-1,x,z,y);
    printf("\n%c to %c",x,y);
    TOH(n-1,z,y,x);
  }
}
int main()
{
  int n;
  printf("\n\t\tTower Of Hanoi\t\t\n");
  printf("Enter no. of Disks : ");
  scanf("%d",&n);
  TOH(n,'A','B','C');
}