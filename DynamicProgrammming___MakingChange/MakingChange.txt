#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
 
int changeMaking(int coin[], int n, int sum)
{
    int i,j;
    int x,y;
    int dp[n+1][sum+1]; 

    for(j=0;j<=sum;j++)
        dp[0][j]=INT_MAX;
    for(i=1;i<=n;i++)
        dp[i][0]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(j>=coin[i-1])
            {
                //without including the current coin
                x=dp[i-1][j];
 
                //the current coin is included(hence 1+)
                y=1+dp[i][j-coin[i-1]];
 
                //the lesser value out of both is taken
                dp[i][j]=min(x,y);
            }
            //If value of current coin is greater than the amount, this coin can not be included
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
 
int main()
{
    int i;
    int n,sum;
 
    cout<<"Enter the amount whose change is required : ";
    cin>>sum;
 
    cout<<"Enter the number of coins available : ";
    cin>>n;
 
    int coin[n];
 
    cout<<"Enter the values of coins : ";
    for(i=0;i<n;i++)
        cin>>coin[i];
 
    cout<<"The least number of coins required is : ";

    cout<<changeMaking(coin,n,sum);
 
    cout<<endl;
    return 0;
}