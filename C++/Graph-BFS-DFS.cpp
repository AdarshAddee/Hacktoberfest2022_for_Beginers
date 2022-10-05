// ==============
// BFS & DFS
// ==============

#include <iostream>
#include "queue.h"
#include "stack.h"
#define MAX 20   
using namespace std;

class graph
{
	friend class stack;
	int n;
	int adj[MAX][MAX];
	int visited[MAX];   
public:
	graph();
	void create();
	void dfs();
	void bfs();
	void initialize_visited();
};


graph :: graph()
{
	for (int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			adj[i][j]=0;

	for (int i = 0; i<MAX; i++)
		visited[i]=0;
}

void graph :: create()
{
	int ch;
	cout<<"No. of Vertices in a graph ::  ";
	cin>>n;

	for (int i = 0; i< n-1; i++)
	 {
		for(int j = i+1; j < n; j++)
		{
			cout<<"Does edge is present between "<< i <<" and " <<j<<"?(1/0)- ";
			cin >> ch;
			if(ch==1) adj[i][j] = adj[j][i] = 1;
		}
	}
}


void graph :: dfs()
{
	stack s;
	int i;
	cout<<"\n--------------------DFS---------------------\n";
	cout<<"Enter starting vertex :: ";
	cin >> i;

	s.push(i);

	while(!s.isEmpty()) 
	{
		i = s.pop(); 

		if(visited[i]==1) 
			continue;

		cout<<" "<<i;

		visited[i] = 1;   

		for (int k = 0; k < n; k++) 
		{
			if(adj[i][k] == 1 && visited[k] == 0)
            { 
				s.push(k);
            }    
		}
	}	
}
void graph :: initialize_visited()
{
	for (int i = 0; i<MAX; i++)
			visited[i]=0;
}


void graph :: bfs()
{
	queue q;
	int i;
	cout<<"\n--------------------BFS---------------------\n";
	cout<<"Enter starting vertex :: ";
	cin >> i;

	q.push(i); 

	while(!q.isEmpty()) 
	{
		i = q.pop(); 

		if(visited[i]==1) 
			continue;

		cout<<" "<<i;

		visited[i] = 1;

		for (int k = 0; k < n; k++) 
		{
			if(adj[i][k] == 1 && visited[k] == 0)
            { 
				q.push(k);
            }
		}
	}
}


int main()
{
	graph g;
	g.create();
	g.initialize_visited();
	g.dfs();
	g.initialize_visited();
	g.bfs();
	return 0;
}

