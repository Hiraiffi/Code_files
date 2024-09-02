#include<iostream>
#include<vector>
using namespace std;
class Graph
{
	public:
		int numofvertices;
		vector<vector<int>>obj;
	Graph(int vertices)
	{
		numofvertices=vertices;
		obj.resize(vertices,vector<int>(vertices,0));
	}
	void display()
	{
		for(int i=0;i<obj.size();i++)
		{
			for(int j=0;j<obj.size();j++)
			{
				cout<<obj[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void addedge(int u,int v)
	{
		obj[v][u]=1;
		obj[u][v]=1;
	}
	void removeVertex(int x)
	{
    // checking if the vertex is present
    if (x > numofvertices) {
        cout << "\nVertex not present!";
        return;
    }
    else {
        int i;
        // removing the vertex
        while (x < numofvertices) {
            // shifting the rows to left side
            for (i = 0; i < numofvertices; ++i) {
                obj[i][x] = obj[i][x + 1];
            }
 
            // shifting the columns upwards
            for (i = 0; i < numofvertices; ++i) {
                obj[x][i] = obj[x + 1][i];
            }
            x++;
        }
 
        // decreasing the number of vertices
        numofvertices--;
    }
}
};
int main()
{
	Graph g(4);
//	g.addedge(1,3);
	g.addedge(1,2);
	g.removeVertex(2);
	g.display();
	
	return 0;
};