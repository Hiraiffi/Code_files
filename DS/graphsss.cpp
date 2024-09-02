#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MP pair<int,pair<int,int>>
#define DP pair<int,int>
#define SIZE 10
class Graph
{
	public:
	int parent[SIZE];
	int vertices;
	int cost;
	bool visited[SIZE];
	int distance[SIZE];
	int arr[SIZE][SIZE];
	int MST[SIZE][SIZE];
	Graph()
	{
		cost=0;
		vertices=SIZE;
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				arr[i][j]=0;
				MST[i][j]=0;
			}
		}
		for(int i=0;i<SIZE;i++)
		{
			parent[i]=i;
		}
		for(int i=0;i<SIZE;i++)
		{
			visited[i]=0;
		}
		for(int i=0;i<SIZE;i++)
		{
			distance[i]=0;
		}
	}
	void reset_visited()
	{
		for(int i=0;i<vertices;i++)
		{
			visited[i]=false;
		}
	}
	void initialize_distance()
	{
		for(int i=0;i<vertices;i++)
		{
			distance[i]=INT_MAX;
		}
	}
	  Graph(int nodes)
    {
        vertices = nodes;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                arr[i][j] = 0;
                MST[i][j] = 0;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            parent[i] = i;
        }
    }

    int findparent(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            return parent[x] = findparent(parent[x]);
        }
    }

    void makeunion(int x, int y)
    {
        int a = findparent(x);
        int b = findparent(y);
        parent[a] = b;
    }

    bool checkcycle(int x, int y)
    {
        if (findparent(x) != findparent(y))
        {
            makeunion(x, y);
            return false;
        }
        else
        {
            return true;
        }
    }

    void kruskal()
    {
        priority_queue<MP, vector<MP>, greater<MP>> pq;

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                int source_node = i;
                int dest_node = j;
                int weight = arr[i][j];
                if (source_node != dest_node && weight != 0)
                {
                    pq.push({weight, {source_node, dest_node}});
                }
            }
        }

        while (!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            int source_node = t.second.first;
            int dest_node = t.second.second;
            int weight = t.first;

            if (!checkcycle(source_node, dest_node))
            {
                cost += weight;
                MST[source_node][dest_node] = weight;
                MST[dest_node][source_node] = weight;
            }
        }
    }
	void printMST()
	{
		cout<<cost<<endl;
		for(int i=0;i<vertices;i++)
		{
			for(int j=0;j<vertices;j++)
			{
				cout<<MST[i][j]<<" ";
			}
			cout<<endl;
		}
	}
		void dijsktra(int src)
		{
			priority_queue<DP,vector<DP>,greater<DP>>pq;
			
			distance[src]=0;
			reset_visited();
			initialize_distance();
			pq.push({0,src});
			while(!pq.empty())
			{
				auto s =pq.top();
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
				for(int i=0;i<vertices;i++)
				{
					for(int j=0;j<vertices;j++)
					{
						if(arr[node][j]!=0 && node!=j)
						{
							if(distance[j]>distance[node]+arr[node][j])
							{
								distance[j]=distance[node] + arr[node][j];
								pq.push({distance[j],j});
							}			
						} 
					}
				//	cout<<endl;
				}
			}
		}
		void shortest_path(int i)
		{
			dijsktra(i);
			print();
		}
		void addEdge(int a,int b,int weight)
		{
			arr[a][b]=weight;
			arr[b][a]=weight;
		}
		void print()
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
		void prims(int src) 
		{
	        vector<vector<int>> mstmatrix(vertices, vector<int>(vertices, 0));
	        bool visited[vertices];
	        int mst = 0, no_of_edges = 0, min, v1, v2;

        for(int i = 0; i < vertices; i++) 
		{
            visited[i] = false;
        }
        visited[src] = true;

        while(no_of_edges < (vertices - 1)) 
		{
            min = INT_MAX;
            v1 = 0;
            v2 = 0;

            for(int i = 0; i < vertices; i++) 
			{
                if(visited[i] == true) 
				{
                    for(int j = 0; j < vertices; j++) 
					{
                        if((arr[i][j] != 0) && (visited[j] == false)) 
						{
                            if(arr[i][j] < min) 
							{
                                min = arr[i][j];
                                v1 = i;
                                v2 = j;
                            }
                        }
                	}
                }
            }
            mstmatrix[v1][v2] = arr[v1][v2];
            mst = mst + arr[v1][v2];
            visited[v2] = true;
            no_of_edges++;
        }
    }

};

int main()
{
	Graph g(5);
	g.addEdge(1,2,5);
	g.addEdge(2,4,2);
	g.addEdge(1,3,2);
	g.addEdge(2,3,8);
	g.addEdge(2,1,1);
	g.kruskal();
	g.printMST();
	cout<<endl;
	//g.shortest_path(0);
	//g.print();
	return 0;
}