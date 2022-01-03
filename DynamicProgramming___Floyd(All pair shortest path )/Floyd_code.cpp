#include<iostream>
using namespace std;

int min(int c1,int c2)
{
	
	if(c1<c2)
		return c1;
	else
		return c2;

}

int Floyd_algo(int matrix[][10],int n )
{
	int D[n+1][n+1];
	int P[n+1][n+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			D[i][j]=matrix[i][j];
			P[i][j]=0;
		}
	}
	cout<<"The process is as folows:";
	cout<<"\n";
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(D[i][k]+D[k][j]<D[i][j])
					{
						D[i][j]=D[i][k]+D[k][j];
						P[i][j]=k;
					}		
			}
		}

		cout<<"D"<<k<<":"<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<D[i][j]<<"\t";
			}
			cout<<"\n";
		}
	cout<<"\n";

	}
	cout<<"Shortest route's intermediate nodes are:"<<endl;
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<P[i][j]<<"\t";
			}
			cout<<"\n";
		}
    return 0;
}

int main()
{
	int n, matrix[10][10];
	cout<<"Enter size of the matrix: ";
	cin>>n;

	if(n>0)
	{
		cout<<"Enter the elements of "<<n<<"x"<<n<<" matrix:"<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<"M["<<i<<"]["<<j<<"]: ";
				cin>>matrix[i][j];
			}
		cout<<"\n";
		}
		cout<<"The matrix you entered is: "<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<matrix[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
		Floyd_algo(matrix,n);
	}
	else
		cout<<"Matrix must be of size greater than 0"<<endl;
}
