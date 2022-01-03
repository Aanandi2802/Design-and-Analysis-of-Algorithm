#include <iostream> 
using namespace std; 
  
#define N 7 
int parent[N]; 
  
 
int find(int i) 
{ 
    while (parent[i] != i) 
        i = parent[i]; 
    return i; 
} 
   
void combine(int i, int j) 
{ 
    int a = find(i); 
    int b = find(j); 
    parent[a] = b; 
} 
  
void kruskal(int cost[][N]) 
{ 
    int mincost = 0; 								
    for (int i = 0; i < N; i++) 
        parent[i] = i; 
  
    int edge_count = 0; 
    while (edge_count < N - 1) 
    {
										//
        int min = 9999, a = -1, b = -1; 
        for (int i = 0; i < N; i++) { 
            for (int j = 0; j < N; j++) { 
                if (find(i) != find(j) && cost[i][j] < min) { 
                    min = cost[i][j]; 
                    a = i; 
                    b = j; 
                } 
            } 
        } 
  
       combine(a, b); 
       cout<<"Edge "<<edge_count++<<"=("<<a<<","<<b <<") cost = "<<min<<endl;
       mincost += min; 
    } 
    cout<<" Minimum cost = "<<mincost<<"\n\n"; 
} 
int main() 
{ 
	
	cout<<"\nMin. Cost Spanning Tree using Kruskal's Algo : "<<endl;
		//
		int cost[N][N]={
      { 9999, 28, 9999, 9999, 9999, 10, 9999  },
      { 28, 9999, 16, 9999, 9999, 9999 ,14 },
      { 9999, 16, 9999, 12, 9999,9999,9999 },
      { 9999, 9999, 12, 9999, 22,9999,18 },
      { 9999, 9999, 9999, 22, 9999,25,24 },
      { 10, 9999, 9999, 9999, 25,9999,9999 },
      { 9999, 14, 9999, 18, 24,9999,9999 },
    };
	   
        kruskal(cost); 
  
        return 0; 
}
