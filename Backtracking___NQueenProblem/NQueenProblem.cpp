#include<iostream>
using namespace std;

int x[10];

void print(int x[10],int n)
{
	cout<<"Possible Solution is: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"Queen "<<i<<" is placed at Row "<<i<<" and Column "<<x[i]<<endl;
	}
	cout<<endl;
}

bool Place(int k,int i)
{
	for(int j=1;j<=k-1;j++)
	{
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
		{
			return false;
		}
	}
	return true;
}
  

int Nqueens(int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(Place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				print(x,n);
			}
			else
				Nqueens(k+1,n);
		}	
	}
	return 0;
}

int main() 
{
	int n;
	cout<<"Enter the N(size of the board) : ";
	cin>>n;
	int k=1;
  Nqueens(k,n);
}
