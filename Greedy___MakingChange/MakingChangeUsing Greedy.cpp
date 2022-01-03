#include<iostream>
using namespace std;
int main()
{
int deno[]={500,200,100,50,10,1},n,i=0,j;
cout<<”Enter Amount:”;
cin>>n;
while(n>0)
{
if(n>=deno[i])
{
n=n-deno[i];
cout<<deno[i]<<” “;
}
else
{
i++;
}
}
return 0;
}