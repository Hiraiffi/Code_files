#include<iostream>
#include<queue>
#define SIZE 100
#define DP pair<int,int>
#define MP pair<int,pair<int,int>>
using namespace std;

class Graph
{
	public:
	int arr[SIZE][SIZE];
	int vertices;
	bool visited[SIZE];
	int distance[SIZE];
	int parent[SIZE];
	int MST[SIZE][SIZE];
	int cost;
	Graph()
	{
		cost=0;
		vertices=SIZE;
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			arr[i][j]=0;
		}
		for(int i=0;i<SIZE;i++)
		{
			parent[i]=0;
		}
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			MST[i][j]=0;
		}
		reset_visited();
	}
	Graph(int nodes)
	{
		vertices=nodes;
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			arr[i][j]=0;
		}
		for(int i=0;i<SIZE;i++)
		{
			parent[i]=0;
		}
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			MST[i][j]=0;
		}
		reset_visited();
	}
	void initialize_distance()
	{
		for(int i=0;i<vertices;i++)
		{
			distance[i]=INT_MAX;
		}
	}
	void DFS(int i)
	{
		visited[i]=true;
		cout<<i;
		for(int j=0;j<vertices;j++)
		{
			if(arr[i][j]!=0 && visited[j]!=1)
			{
				visited[j]=true;
				DFS(j);
			}
		}
	}
	void BFS(int i)
	{
		visited[i]=true;
		queue<int>q;
		q.push(i);
		while(!q.empty())
		{
			auto s = q.front();
			q.pop();
			cout<<s<<" ";
			for(int j=0;j<vertices;j++)
			{
				if(arr[s][j]!=0 && visited[j]!=1)
				{
					visited[j]=true;	
					q.push(j);
				}
			}	
		}
	}
	void reset_visited()
	{
		for(int i=0;i<vertices;i++)
		{
			visited[i]=false;
		}
	}
	void insertEdge(int source,int destination,int w)
	{
		arr[source][destination]=w;
		arr[destination][source]=w;
	}
	void dijsktra(int source)
	{
		priority_queue<DP,vector<DP>,greater<DP>>pq;
	 	initialize_distance();
		reset_visited();
		distance[source]=0;
		pq.push({0,source});
		
		while(!pq.empty())
		{
			auto s=pq.top();
			pq.pop();
			int node=s.second;
			int node_distance=s.first;
			
			if(visited[node])
			{
				continue;
			}
			else
			{
				visited[node]=true;
			}
			for(int j=0;j<vertices;j++)
			{
				if(arr[node][j]!=0 && node != j)
				{
					if(distance[j] > distance[node] + arr[node][j])
					{
						distance[j]=distance[node] + arr[node][j];
						pq.push({distance[j],j});
					}
				}
			}
			cout<<endl;
		}
	}
	void print()
	{
		for(int i=0;i<vertices;i++)
		{
			cout<<distance[i]<<" ";
		}
		cout<<endl;
	}
	void shortest_path(int i)
	{
		dijsktra(i);
		print();	
	}
	void display()
	{
		for(int i=0;i<vertices;i++)
		{
			for(int j=0;j<vertices;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}	
	int findparent(int x)
	{
		if(parent[x]==x)
		{
			return x;
		}
		else
		{
			return findparent(x);
		}
	}
	void makeunion(int x,int y)
	{
		int a =findparent(x);
		int b = findparent(y);
		parent[a]=b;
	}
	bool checkcycle(int x,int y)
	{
		if(findparent(x)!=findparent(y))
		{
			makeunion(x,y);
		}
		else
		{
			return true;
		}
		return false;
	}
	void kruskal()
	{
		priority_queue<MP,vector<MP>,greater<MP>>qp;
		for(int i=0;i<vertices;i++)
		{
			for(int j=0;j<vertices;j++)
			{
				int source_node = i;
				int dest_node =j;
				int weight = arr[i][j];
				
				if(source_node != dest_node && weight!=0)
				{
					qp.push({weight,{source_node,dest_node}});
				}
			}
		}
		while(!qp.empty())
		{
			auto t =qp.top();
			qp.pop();
			
			int source_node=t.second.first;
			int dest_node=t.second.second;
			int weight = t.first;
			
			if(!checkcycle(source_node,dest_node))
			{
				cost+=weight;
				MST[source_node][dest_node] = weight;
				MST[dest_node][source_node] = weight;
			}
		}
	}
	void MSTdisplay()
	{
		for(int i=0;i<vertices;i++)
		{
			for(int j=0;j<vertices;j++)
			{
				cout<<MST[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
int main()
{
	Graph g(5);
	g.insertEdge(0,2,7);
	g.insertEdge(4,1,6);
	g.insertEdge(2,1,4);
	g.insertEdge(1,3,6);
	g.insertEdge(3,2,4);
	g.display();
	cout<<endl;
	cout<<"DFS: ";
	g.DFS(0);
	cout<<"\nBFS: ";
	g.reset_visited();
	g.BFS(0);
	cout<<endl;
	g.shortest_path(0);
	
	return 0;
}